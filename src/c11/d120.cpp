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

#include "types.h"
using namespace maiev;

//递推终止函数
void print(){
    cout << endl;
}

template<typename T, typename T1>
void print(T t1, T t2){
    cout << t1 << " " << t2 << endl;
}

//展开函数
template<class T, class... Other>
void print(T t, Other... other){
    cout << t << " ";
    print(other...);
}

template<class T>
void printarg(T t){
    cout << t << endl;
}

template<class... Args>
void expand(Args... args){
//    int ar[] = {(printarg(args),0)...};
//    std::initializer_list<int>{(printarg(args),0)...};
    std::initializer_list<int> {([&]{cout << args << endl;}(),0)...};
    cout << "***************" << endl;
}

#ifdef MAIEV
template<std::size_t I = 0, typename Tuple>
typename std::enable_if<I == std::tuple_size<Tuple>::value>::type printtp(Tuple){
}

template<std::size_t I = 0 , typename Tuple>
typename std::enable_if< I < std::tuple_size<typename std::decay<Tuple>::type>::value>::type
printtp(Tuple t){
    std::cout << std::get<I>(t) << std::endl;
    printtp<I + 1> (t);
}

template<typename... Args>
void print(Args... args){
    printtp(std::make_tuple(args...));
}
#endif

template<typename... Args> struct Sum;//前向申明

//可变参数模板类
template<typename First, typename... Rest>
struct Sum<First, Rest...>{
    enum {value = Sum<First>::value + Sum<Rest...>::value};
};

//特化终止函数
template<typename Last>
struct Sum<Last>{
    enum {value = sizeof(Last)};
};

template<int...>
struct IndexSeq{};

#ifdef MAIEV
template<int N, int...Indexes>
struct MakeIndexes : MakeIndexes<N-1,N-1, Indexes...>{};
    template<int... Indexes>
struct MakeIndexes<0, Indexes...>{
    typedef IndexSql<Indexes...> type;
};
#endif
template<int N, int...Indexes>
struct MakeIndexes {
    using type = typename MakeIndexes<N-1, N-1, Indexes...>::type;
};
template<int... Indexes>
struct MakeIndexes<0, Indexes...>{
    using type = IndexSeq<Indexes...>;
};

template<int... Indexes, typename ... Args>
void print_helper(IndexSeq<Indexes...>, std::tuple<Args...>&& tup){
    print(std::get<Indexes>(tup)...);
}
template<typename... Args>
void printx(Args... args){
    print_helper(typename MakeIndexes<sizeof...(Args)>::type(), std::make_tuple(args...));
}

template<typename T, typename ... Args>
T* Instance(Args ... args){
    return new T(args...);
}

template<typename T, typename ... Args>
T* Instance(Args&& ... args){
    return new T(std::forward<Args>(args)...);
}

template<typename T, typename U>
typename std::enable_if<std::is_convertible<T,U>::value ||
                        std::is_convertible<U,T>::value, bool>::type
compare(T t, U u){
    return t == u;
}

bool compare(...){
    return false;
}

template<int I, typename T, typename... Args>
struct find_index {
    static int call(std::tuple<Args...> const& t, T&& val) {
        return compare(std::get<I>(t), val) ? I :
               find_index<I - 1, T, Args...>::call(t, std::forward<T>(val));
    }
};

template<typename T, typename... Args>
struct find_index<0, T, Args...>
{
    static int call(std::tuple<Args...> const& t, T&& val) {
        return compare(std::get<0>(t), val) ? 0 : -1;
    }
};

template<typename T, typename ...Args>
int find_index_helper(std::tuple<Args...>const&t, T&&val){
    return find_index<sizeof...(Args) - 1, T, Args...>::call(t, std::forward<T>(val));
}

template<size_t k, typename Tuple>
typename std::enable_if<k == std::tuple_size<Tuple>::value>::type
GetArgByIndex(size_t index, Tuple& p){
    throw std::invalid_argument("ar index out of range");
}

template<size_t k = 0, typename Tuple>
typename std::enable_if<k < std::tuple_size<Tuple>::value>::type
GetArgByIndex(size_t index, Tuple& tp){
    if (k == index){
        cout << std::get<k>(tp) << endl;
    }else{
        GetArgByIndex<k+1>(index,tp);
    }
}

template<typename Arg>
void GetArgByIndex2(int index, std::tuple<Arg>& tp){
    cout << std::get<0>(tp) << endl;
}

template<typename Arg, typename... Args>
void GetArgByIndex2(int index, std::tuple<Args...>& tp){
    if (index < 0 || index > std::tuple_size<std::tuple<Arg, Args...>>::value){
        throw std::invalid_argument("inde x is not valid");
    }
    if (index > 0){
        GetArgByIndex2(index -1, (std::tuple<Args...>)& tp);
    }else{
        cout << std::get<0>(tp) << endl;
    }
}

void d120::test() {
    {
        using Tuple = std::tuple<int,double, string, int>;
        Tuple tp = std::make_tuple(1,2,"Test",3);
        const size_t length = std::tuple_size<Tuple>::value;
        for(size_t i = 0; i< length; i++){
            GetArgByIndex<0>(i,tp);
        }

//        GetArgByIndex(4,tp);
    }
#ifdef MAIEV
    {
        std::tuple<int,double,string>  tp = std::make_tuple(1,1.1, "ok");
        int index = find_index_helper(tp,"ok");
        cout << index << endl;
    }
    {
        using T = MakeIndexes<3>::type;
        T t1;
//    printx(t1);
//    cout << typeid(T).name() << endl;

        cout << "--------------------------" << endl;

        using sum_t = Sum<int, double, unsigned>;
        cout << Sum<int, double, unsigned>::value << endl;
        cout << sum_t::value << endl;

        expand(1, 2, 3, 4, 5);

        print(1, 2);
        print(1, 2, 3);

        std::cout << "*************************" << std::endl;

//    cout << GetLeftSize<int>::value << endl;
//    cout << GetLeftSizex<double>::value << endl;
//    cout << GetLeftSize1<float>::value << endl;
//
//    using five = maiev::integral_constant<int, 5>;
//    five f;
//    int x = f;

    cout << maiev::is_integral<int>::value << endl;
    cout << maiev::is_integral<short int>::value << endl;
    cout << maiev::is_integral<char16_t>::value << endl;
    cout << maiev::is_integral<char32_t>::value << endl;
    cout << maiev::is_void<int>::value << endl;
    cout << maiev::is_void<void>::value << endl;
    cout << maiev::is_array<void>::value << endl;
    cout << maiev::is_array<int[]>::value << endl;
    cout << maiev::is_array<Key[]>::value << endl;
    cout << std::is_array<Key[]>::value << endl;
}
#endif


    /**
    struct AA{
        AA(int x_):x(x_){}
        operator int (){//将对象转换成()
            return x;
        }
    private :
        int x;
    };

    AA a(10);
    int b = a;
    std::cout << b << std::endl;
     */


    /**
     * 2.5 unordered container 无序容器
     * unordered_map
     * unordered_multimap
     * unordered_set
     * unordered_multiset
     *
     */
#ifdef MAIEV
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

