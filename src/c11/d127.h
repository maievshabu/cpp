//
// Created by redredmaple on 2026/1/27.
//

#ifndef C11_D127_H
#define C11_D127_H
#include "common.h"

class NonCopyable{
protected:
    NonCopyable() = default;
    ~NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};

template<typename T, typename... Args>
unique_ptr<T> make_unique(Args&&... args){
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

namespace d127{
    void test();

#if 0
    const int MaxObjectNum = 10;
    template<typename T>
    class ObjectPool {
    public:
        // 为了多次构造，不使用 && 转发，避免循环内参数失效
        template<typename ...Args>
        void Init(size_t num, Args... args) {
            if (num <= 0 || num > MaxObjectNum)
                throw std::logic_error("object num out of range.");

            // 统一 Key 的生成方式
            std::string constructName = typeid(T(args...)).name();

            for (size_t i = 0; i < num; i++) {
                // 池子持有 unique_ptr，保证池子销毁时对象也销毁
                auto obj = make_unique<T>(args...);
                m_object_map.emplace(constructName, std::move(obj));
            }
        }

        template<typename ...Args>
        std::shared_ptr<T> Get() {
            std::string constructName = typeid(T(Args...)).name();

            auto it = m_object_map.find(constructName);
            if (it == m_object_map.end()) {
                return nullptr;
            }

            // 1. 从池子取出所有权
            std::unique_ptr<T> ptr = std::move(it->second);
            m_object_map.erase(it);

            // 2. 将 unique_ptr 转交给 shared_ptr，并定义回收逻辑
            // 使用 release() 移交原始指针，删除器负责包装回 unique_ptr 归还
            T* raw_ptr = ptr.release();
            return std::shared_ptr<T>(raw_ptr, [this, constructName](T* p) {
                // 当用户端的 shared_ptr 计数归零时，自动放回池子
                this->m_object_map.emplace(constructName, std::unique_ptr<T>(p));
            });
        }

    private:
        // 使用 unique_ptr，完全不用手动 delete，且不影响引用计数
        std::multimap<std::string, std::unique_ptr<T>> m_object_map;
    };
#endif

#if 0
    const int MaxObjectNum = 10;
    template<typename T, typename DT= shared_ptr<T>>
    class ObjectPool : NonCopyable
    {
        template<typename ...Args>
        using Constructor = std::function<DT>(Args...);
    public:
        template<typename ...Args>
        void Init(size_t num, Args&&... args){
            if (num < 0 || num > MaxObjectNum)
                throw std::logic_error("object num out of range.");
            auto constructName = typeid(Constructor<Args...>).name();
            for(size_t i = 0; i < num; i++){
                m_object_map.emplace(constructName, DT(new T(std::forward<Args>(args)...),
                        [this, constructName](T* p){
                        m_object_map.emplace(std::move(constructName), std::shared_ptr<T>(p));
                }));
            }
        }

        template<typename ... Args>
        DT Get(){
            string constructName = typeid(Constructor<Args...>).name();
            auto range = m_object_map.equal_range(constructName);
            for(auto it = range.first;  it !=range.second; ++it){
                auto ptr = it->second;
                m_object_map.erase(it);

                return ptr;
            }

            return nullptr;
        }
    private:
        multimap<string, DT> m_object_map;
    };

#endif

#if 0
    const int MaxObjectNum = 10;
    template<typename T>
    class ObjectPool{
        template<typename ...Args>
        using Constructor = std::function<std::shared_ptr<T>(Args...)>;
    public:
        ObjectPool() : needClear(false){}
        ~ObjectPool() {needClear = true;}

        template<typename... Args>
        void Init(size_t num, Args&&... args){
            if (num <= 0 || num > MaxObjectNum)
                throw std::logic_error("object num out of range.");
            auto constructName = typeid(Constructor<Args...>).name();

            for(size_t i = 0; i < num; i++){
                m_object_map.emplace(constructName,
                                     shared_ptr<T>(new T(std::forward<Args>(args)...),
                                                   [this,constructName,args...](T* p){
                                                       return createPtr<T>(string(constructName), args...);
                                                   }));
            }
        }

        template<typename T, typename... Args>
        std::shared_ptr<T> createPtr(std::string& constructName, Args... args){
            return std::shared_ptr<T>(new T(args)...), [constructName, this](T* t){
                if (needClear)
                    delete [] t;
                else
                    m_object_map.emplace(constructName, std::shared_ptr<T>(t));
            };
        }

        template<typename ...Args>
        std::shared_ptr<T> Get(){
            std::string constructName = typeid(Constructor<Args...>).name();
            auto range = m_object_map.equal_range(constructName);
            for(auto it = range.first; it != range.second; ++it){
                auto ptr = it->second;
                m_object_map.erage(it);
                return ptr;
            }

            return nullptr;
        }

    private:
        bool needClear;
        std::multimap<std::string, std::shared_ptr<T>> m_object_map;
    };

#endif

    struct BigObject {
        BigObject() {}
        BigObject(int a) {}
        BigObject(const int& a, const int& b){}
        void Print(const string& str){
            cout << str << endl;
        }
    };


    class Command{
    public:
        virtual void Execute() = 0;
    };

    template<class F,
            class ... Args,
            class = typename std::enable_if<!std::is_member_function_pointer<F>::value>::type
    >
    void Wrap(F && f, Args&& ... args){
        return f(std::forward<Args>(args)...);
    }

#if 0
    template<class Receiver>
    class SimpleCommand: public Command{
    public:
        typedef void (Receiver::* Action)();
        SimpleCommand(Receiver* r, Action a):_receiver(r),_action(a){}
        virtual void Execute();
    private:
        Action _action;
        Receiver _receiver;
    };
#endif

    class MyClass{
    public:
        void Action();
    };


    struct ConcreteElement1;
    struct ConcreteElement2;

    template<typename ... Types>
    struct Visitor;

    template<typename T, typename ...Types>
    struct Visitor<T, Types...> : Visitor<Types...>
    {
        using Visitor<Types...>::Visit;
        virtual void Visit(const T&) = 0;
    };

    template<typename T>
    struct Visitor<T>
    {
        virtual void Visit(const T&) = 0;
    };

    struct stA;
    struct stB;

    struct Base{
        typedef Visitor<stA, stB> MyVisitor;
        virtual void Accept(MyVisitor&) = 0;
    };

    struct stA : Base{
        double val;
        void Accept(Base::MyVisitor& v){
            v.Visit(*this);
        }
    };

    struct stB : Base{
        double val;
        void Accept(Base::MyVisitor& v){
            v.Visit(*this);
        }
    };

    struct PrintVisitor: Base::MyVisitor {
        void Visit(const stA& a){
            std::cout << "from stA: " << a.val << std::endl;
        }
        void Visit(const stB& b){
            std::cout << "from stB: " << b.val << std::endl;
        }
    };

#if 0
    struct Visitor{
        virtual ~Visitor(){};
        virtual void Visit(ConcreteElement1* element) = 0;
        virtual void Visit(ConcreteElement2* element) = 0;
    };
#endif


#if 0
    struct Element{
        virtual ~Element(){}
        virtual void Accept(Visitor& visitor) = 0;
    };

    struct ConcreteVisitor: public Visitor{
        void Visit(ConcreteElement1* element){
            cout << "visit concreteelement1" << endl;
        }
        void Visit(ConcreteElement2* element){
            cout << "visit concreteelement2" << endl;
        }
    };

    struct ConcreteElement1: public Element{
        void Accept(Visitor& visitor){
            visitor.Visit(this);
        }
    };

    struct ConcreteElement2: public Element{
        void Accept(Visitor& visitor){
            visitor.Visit(this);
        }
    };

#endif

    template<typename Func>
    class Events : NonCopyable{
    public:
        Events(){}
        ~Events(){}
        int Connect(Func&& f){
            return Assign(f);
        }

        int Connect(const Func& f){
            return Assign(f);
        }
        void Disconnect(int key){
            m_connections.erase(key);
        }

        template<typename ...Args>
        void Notify(Args&&... args){
            for (auto & it: m_connections){
                it.second(std::forward<Args>(args)...);
            }
        }
    private:
        template<typename F>
        int Assign(F&& f){
            int k = m_observerId ++;
            m_connections.emplace(k ,std::forward<F>(f));
            return k;
        }
        int m_observerId = 0;
        std::map<int, Func> m_connections;
    };

#if 0
    struct stA{
        int a, b;
        void print(int a, int b) {cout << a << "," << b << endl;}
    };
#endif


    class Subject;
    class Observer{
    public:
        virtual ~Observer();
        virtual void update(Subject* theChangedSubject) = 0;
    protected:
        Observer();
    };

    class Subject{
    public:
        virtual ~Subject();
        virtual void Attach(Observer*);
        virtual void Detach(Observer*);
        virtual void Notify();
    protected:
        Subject();

    private:
        list<Observer*> *_observers;//
    };


    template<typename T>
    class Singleton{
    public:
       template<typename... Args>
       static T* Instance(Args... args){
            if (m_pInstance == nullptr){
                m_pInstance = new T(std::forward<Args>(args)...);
            }

            return m_pInstance;
       }

        static T* GetInstance(){
            if (m_pInstance == nullptr)
                throw std::logic_error("this instance is not iit, please initialize the instance first");
            return m_pInstance;
        }
        static void DestoryInstance(){
            delete m_pInstance;
            m_pInstance = nullptr;
        }

    private:
        Singleton();
        virtual ~Singleton(void);
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);
        static T* m_pInstance;
    };

    struct A{
        A(const string&){cout << "lvalue"<< endl;}
        A(string&& x){cout << "rvalue" << endl;}
    };

    struct B{
        B(const string&){cout << "lvalue" << endl;}
        B(string&& x){cout << "rvalue" << endl;}
    };

    struct C{
        C(int x, double y){}
        void Fun() {cout << "test" << endl;}
    };


#if 0
    template<typename T>
    class Singleton{
    public:
        static T* Instance(){
            if (m_pInstance == nullptr)
                m_pInstance = new T();

            return m_pInstance;
        }

        template<typename T0>
        static T* Instance(T0 arg0){
            if (m_pInstance == nullptr){
                m_pInstance = new T(arg0);
            }

            return m_pInstance;
        }

        template<typename T0, typename T1>
        static T* Instance(T0 arg0, T1 arg1){
            if (m_pInstance == nullptr){
                m_pInstance = new T(arg0, arg1);
            }

            return m_pInstance;
        }

        template<typename T0, typename T1, typename T2>
        static T* Instance(T0 arg0, T1 arg1, T2 arg2){
            if (m_pInstance == nullptr){
                m_pInstance = new T(arg0, arg1, arg2);
            }

            return m_pInstance;
        }

        template<typename T0, typename T1, typename T2, typename T3>
        static T* Instance(T0 arg0, T1 arg1, T2 arg2, T3 arg3){
            if (m_pInstance == nullptr){
                m_pInstance = new T(arg0, arg1, arg2, arg3);
            }

            return m_pInstance;
        }

        template<typename T0, typename T1, typename T2, typename T3, typename T4>
        static T* Instance(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4){
            if (m_pInstance == nullptr){
                m_pInstance = new T(arg0, arg1, arg2, arg3, arg4);
            }

            return m_pInstance;
        }

        template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
        static T* Instance(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5){
            if (m_pInstance == nullptr){
                m_pInstance = new T(arg0, arg1, arg2, arg3, arg4, arg5);
            }

            return m_pInstance;
        }


        static T* GetInstance(){
            if (m_pInstance == nullptr)
                throw std::logic_error("this instance is not iit, please initialize the instance first");
            return m_pInstance;
        }
        static void DestoryInstance(){
            delete m_pInstance;
            m_pInstance = nullptr;
        }
    private:
        Singleton();
        virtual ~Singleton(void);
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);
    private:
        static T* m_pInstance;
    };

    struct A{
        A(){}
    };
    struct B{
        B(int x){}
    };
    struct C{
        C(int x, int y){}
    };
#endif

}


#endif //C11_D127_H
