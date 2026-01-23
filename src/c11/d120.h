//
// Created by redredmaple on 2026/1/20.
//

#ifndef FINDWORD_D120_H
#define FINDWORD_D120_H
#include "common.h"

namespace d120 {
    void test();


    struct Key{
        std::string first;
        std::string second;
    };

    struct KeyHash{
        std::size_t operator()(const Key& k)const{
           return std::hash<std::string>()(k.first) ^ (std::hash<std::string>()(k.second) << 1);
        }
    };

    struct KeyEqual{
        bool operator()(const Key& lhs, const Key& rhs){
            return lhs.first == rhs.first && lhs.second == rhs.second;
        }
    };

    struct Complicated{
        int year;
        double country;
        std::string name;
        Complicated(int a, double b, string c)
                :year(a), country(b), name(c){
            cout << "is ctr" << endl;
        }

        Complicated(const Complicated& other)
                :year(other.year),country(other.country),name(std::move(other.name)){
            cout << "is moved" << endl;
        }
    };


//    template<typename T>
//    void PrintT(T& t){
//        cout << "lvalue" << endl;
//    }
//
//    template<typename T>
//    void PrintT(T&& t){
//        cout << "rvalue" << endl;
//    }
//
//    template<typename T>
//    void testForward(T&& val){
//        printT(val);
//        printT(std::forward<T>(val));
//        PrintT(std::move(val));
//    }

    class A{
    public:
        A():m_ptr(new int(0)){
            cout << "construct" << endl;
        }
        A(const A& a):m_ptr(new int(*a.m_ptr)){
            cout << "copy construct" << endl;
        }
        A(A&& a):m_ptr(a.m_ptr){
            a.m_ptr = nullptr;
            cout << "move construct:" << endl;
        }
        ~A(){
            cout << "destruct" << endl;
            delete m_ptr;
        }
    private:
        int * m_ptr;
    };

    class MyString{
    private:
        char* m_data;
        size_t m_len;
        void copy_data(const char* s){
            m_data = new char [m_len + 1];
            memcpy(m_data, s, m_len);
            m_data[m_len] = '\0';
        }
    public:
        MyString(){
            m_data = nullptr;
            m_len = 0;
        }
        MyString(const char* p){
            m_len = strlen(p);
            copy_data(p);
        }
        MyString(const MyString& str){
            m_len = str.m_len;
            copy_data(str.m_data);
            cout << "copy ctr is called! source:" << str.m_data << endl;
        }
        MyString& operator=(const MyString& str){
            if (this != &str){
                m_len = str.m_len;
                copy_data(str.m_data);
            }
            cout << "copy assign is called! source:" << str.m_data << endl;
            return *this;
        }
        MyString(MyString&& str){
            cout << "move ctr is called! source: " << str.m_data << endl;
            m_len = str.m_len;
            m_data = str.m_data;

            str.m_data = nullptr;
            str.m_len = 0;
        }

        MyString& operator=(MyString&& str){
            cout << "move assign is called! source: " << str.m_data << endl;
            if (this != &str){
                m_len = str.m_len;
                m_data = str.m_data;

                str.m_data = nullptr;
                str.m_len = 0;
            }

            return *this;
        }

        virtual ~MyString(){
            if (m_data) free(m_data);
        }
    };

    struct Element{
        typedef int ptree;
        Element(){}
        Element(Element&& other): m_children(std::move(other.m_children)){}
        Element(const Element& other) : m_children(other.m_children){}
    private:
        vector<ptree> m_children;
    };


#ifdef MAIEVV
    struct A{
        A(){
            cout << "construct: " << ++g_constructCount << endl;
        }

        A(const A& a){
            cout << "copy construct: " << ++g_copyConstructCount << endl;
        }

        ~A(){
            cout << "destruct: " << ++g_destructCount << endl;
        }
    };
#endif

    template<typename T>
    void f(T&& param); //T&& 不一定表示右值,它的类型是未定的，可能是左值又可能是右值

    void printValue(int& i);
    void printValue(int&& i);
    void forward(int&& i);

    template<typename T>
    void fforward(T&& i);

    template<class T>
    std::string type_name(){
        typedef typename::std::remove_reference<T>::type TR;
        std::unique_ptr<char, void(*)(void*)> own(
#ifndef __GNUC__
                nullptr
#else
                abi::__cxa_demangle(typeid(TR).name(), nullptr, nullptr,nullptr),
#endif
                std::free
        );
        std::string r = own != nullptr ? own.get() : typeid(TR).name();
        if (std::is_const<TR>::value)
            r += " const";
        if (std::is_volatile<TR>::value)
            r += " volatile";
        if (std::is_lvalue_reference<T>::value)
            r += " &";
        else if (std::is_rvalue_reference<T>::value)
            r += " &&";

        return r;
    }

    template<typename T>
    void Func(T&& t){
        cout << type_name<T>() << endl;
    }



};


#endif //FINDWORD_D120_H
