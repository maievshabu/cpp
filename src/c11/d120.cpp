//
// Created by redredmaple on 2026/1/20.
//

#include "d120.h"
using namespace d120;

A getA(){
    return A();
}

A Get(bool flag){
    A a;
    A b;
    if (flag)
        return a;
    else
        return b;
}

void d120::printValue(int& i){
    std::cout << "lvalue: " << i << std::endl;
}

void d120::printValue(int&& i){
    std::cout << "rvalue: " << i << std::endl;
}

void d120::forward(int&& i){
    printValue(i);
}

template<typename T>
void d120::fforward(T&& i){
    printValue(i);
}

template<typename T>
void PrintT(T& t){
    cout << "lvalue" << endl;
}

template<typename T>
void PrintT(T&& t){
    cout << "rvalue" << endl;
}

template<typename T>
void testForward(T&& val){
    PrintT(val);
    PrintT(std::forward<T>(val));
    PrintT(std::move(val));
}

template<typename Function, typename... Args>
auto FuncWrapper(Function && f, Args&&... args) -> decltype(f(std::forward<Args>(args)...)){
    return f(std::forward<Args>(args)...);
}

void test0(){
    cout << "void" << endl;
}
int test1(){
    return 1;
}

int test2(int x){
    return x;
}

string test3(string s1, string s2){
    return s1 + s2;
}


void d120::test() {

    /**
     * 2.5 unordered container 无序容器
     * unordered_map
     * unordered_multimap
     * unordered_set
     * unordered_multiset
     *
     */
    {
        std::unordered_map<std::string, std::string> m1;
        std::unordered_map<int, std::string> m2={
                {1, "foo"},
                {3, "bar"},
                {2, "baz"},
        };

        std::unordered_map<int, std::string> m3 = m2;
        std::unordered_map<int ,std::string> m4 = std::move(m2);

        std::vector<std::pair<std::bitset<8>,int>> v ={{0x12,1}, {0x01, -1}};

        std::unordered_map<std::bitset<8>,double> m5(v.begin(), v.end());

        std::unordered_map<Key, std::string, KeyHash, KeyEqual> m6 = {
                {{"John", "Doe"}, "example"},
                {{"Mary", "Sue"}, "another"},
        };
    }

#ifdef MAIEV
    {
        std::map<int,Complicated> m;
        int anInt = 4;
        double aDouble = 5.0;
        std::string aString = "c++";
        cout << "--insert--" << endl;
        m.insert(std::make_pair(4,Complicated(anInt,aDouble,aString)));

        cout << "--emplace--" << endl;
        m.emplace(4, Complicated(anInt,aDouble,aString));

        cout << "--emplace_back--" << endl;
        vector<Complicated> v;
        v.emplace_back(anInt, aDouble, aString);
        cout << "--push_back--" << endl;
        v.push_back(Complicated(anInt, aDouble, aString));
    }
#endif

    /**
     * 2.4 emplace_back减少内存拷贝和移动
     *
     * emplace_back 代替push_back;
     *
     * emplace
     * emplace_hint
     * emplace_front
     * emplace_after
     * emplace_back
     *
     * struct A{
     *      int x;
     *      double y;
     *      A(int a, double b): x(a),y(b){}
     * }
     *
     * vector<A>v;
     * v.emplace_back(1,2);
     * cout << v.size() << endl;
     *
     *
     */

#ifdef MAIEV
    {
        FuncWrapper(test0);
        FuncWrapper(test1);
        FuncWrapper(test2, 2);
        FuncWrapper(test3, "hello", "world");
    }

    {
        testForward(1);
        cout << "-----------" << endl;
        int x = 1;
        testForward(x);
        cout << "-----------" << endl;
        testForward(std::forward<int>(x));
        cout << "-----------" << endl;
    }
#endif

    /**
     * P78 2.3 forward和完美转发
     * template<typename T>
     * void forwardValue(T& val){
     *      processValue(val); //右值参数会变成左值
     *}
     *
     * template<typename T>
     * void forwardValue(const T& val){
     *      processValue(val); //所有参数都变成常量左值引用了
     * }
     */

    /**
     * P77
     * 2.2 move语义
     * std::list<std::string> tokens;
     * std::list<std::string> t = tokens;
     *
     * std::list<std::string> tokens;
     * std::list<std::string> t = std::move(tokens);
     *
     * move只是转移了自由的控制权，本质上是将左值强制转换为右值引用，以用于move语义
     * 避免含有自营的对象发生无畏的拷贝。move对于拥有如对内存,文件句柄等资源的成员的对象有效。
     * move对于基本类型。还说拷贝。move对于含资源的对象来说更有意义
     */
#ifdef MAIEV
    {
        auto v = std::move(10);
        std::cout << v << std::endl;
        std::cout << is_rvalue_reference<v>::value << std::endl;
    }
#endif

    /**
     * P64
     * 2.1 右值引用
     *
     * A a = getA();
     * A&& a = getA();
     * const A& a = getA(); //常量左值是一个万能的引用类型可接收左值，右值，常量左值，常量右值
     * A& a = getA(); //error 普通左值不能接收右值
     *
     * template<typename T>
     * void f(T&& param); //T&& 不一定表示右值,它的类型是未定的，可能是左值又可能是右值
     * f(10);//右值
     * int x = 10;
     * f(x); //左值
     * 未定的类型(universal references)，必须初始化，它是左值还是右值取决于它的初始化，
     * 如果一个&&被一个左值初始化，它就是左值，如果它被一个右值初始，它就是右值
     * 只有当发生自动类型推断时(函数模板的类型自动推导，或auto关键字)，&&才是一个universal references;
     * template<typename T>
     * void f(T&& param);//T的类型需要推导，所以T是一个universal references
     *
     * template<typename T>
     * class Test{
     *      Test(Test&& rhs); //已级定义了一个特定的类型，没有类型推断,&& 是一个右值引用
     * }
     *
     * void f(Test&& param); //已级定义了一个确定的类型，没有推断类型，&&是一个右值引用
     *
     * template<typename T>
     * void f(std::vector<T>&& param);这里既有推断类型T又有确定类型vector，param是说明类型呢？ 答案是右值引用类型
     *
     * template<typename T>
     * void f(const T&& param); //右值引用类型,:universal references 仅仅在T&&下发生，任何一点附加条件都会使之失效,
     * 而变成一个普通的右值引用
     *
     * c11重引用折叠规则如下：
     * 1) 所有的右值引用叠加到右值引用上仍然是一个右值引用
     * 2)所有的其他引用类型直接的叠加都将变为左值引用
     *
     * 左值和右值是独立于它的类型的，右值引用可能是左值也可能是右值
     * int&& var1 = std::move(x); //var1 的类型是一个int&&
     * auto&& var2 = var1; //var2存在类型推断，是一个 universal references.这里auto&& 最终被推断为int&
     *
     * var1的类型是一个左值类型，但var1本身是一个左值,var1是一个左值，根据引用叠加规则var2是一个int&?
     *
     * int w1, w2;
     * auto&& v1 = w1; //int&
     * decltype(w1)&& v2 = w2; //int&&
     *
     *
     * &&总结如下：
     * 1) 左值和右值是独立于它们的类型的，右值引用类型可能是左值也可能是右值
     * 2) auto&&或者函数出纳书类型自动推导的T&&是一个未定的引用类型，被成为universal references ,
     * 它可能是左值引用也可能是右值引用，取决于初始化值的类型
     * 3)所有的右值引用叠加到右值引用上仍然是右值引用，其他引用折叠都为左值引用。
     * 当T&&为模板参数时，输入左值，它会变成左值引用，而输入右值时编为具名的右值引用
     * 4) 编译器会将已命名的右值引用视为左值，而将未命名的右值视为右值
     *
     * 有了右值引用和移动语义,在设计和实现类时,对于需要动态神器大量自营的类，应该设计右值引用的拷贝 构造函数和赋值函数
     * 以提高应用效率。需要注意的是，我们一般在提供右值引用的构造函数的同时，也会提供常量最值引用的拷贝构造函数，以保证
     * 移动不成还可以使用拷贝构造。
     * 需要注意一个细节：我们提供移动构造函数的同事也会提供一个拷贝构造函数，以防止移动不成功是还能拷贝构造。使代码安全
     */
#ifdef MAIEVV
    {
//        A a = Get(false);
        MyString a;
        a = MyString("hello");

        std::vector<MyString> vec;
        vec.push_back(MyString("World"));
    }

    {
        {
            class Foo{};
            std::cout << typeid(Foo*[10]).name() << std::endl;

            //这里是把gcc的类型输出更具human！！
            char* name = abi::__cxa_demangle(typeid(Foo*[10]).name(), nullptr, nullptr, nullptr);
            std::cout << name << std::endl;
            free(name);
        }

        {
            class Foo{};
            std::cout << typeid(Foo).name() << std::endl;

            char* name = abi::__cxa_demangle(typeid(Foo).name(), nullptr, nullptr, nullptr);
            std::cout << name << std::endl;
            free(name);
        }
    }
    {
        int x = 10;
        int&& var1 = std::move(x);
        auto&& var2 = var1;

        int w1, w2;
        auto&& v1 = w1;
        decltype(w1) && v2 = std::move(w2);//error

        int i = 0;
        printValue(i); //lvalue
        printValue(1); //rvalue
        forward(2); //lvalue
        fforward(2); //lvalue
    }

    {
        string str = "Test";
        Func(str);
        Func(std::move(str));
    }

#endif

}

