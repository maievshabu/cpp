//
// Created by xiaowei003 on 2024/9/12.
//

#include "A.h"
using namespace ch603;

#include  <pthread.h>
#include <iostream>
#include <map>
#include <functional>
#include <tuple>
#include <cassert>
#include <typeinfo>
#include <exception>

using namespace std;

static long long total = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void * func(void *){
    long long i;
    for(i = 0; i < 100LL; i++){
        pthread_mutex_lock(&m);
        total += i;
        pthread_mutex_unlock(&m);
    }

    return nullptr;
}

struct howManyBytes{
    char a;
    int b;
};

void Polygon::xx() {
    std::cout <<__FUNCTION__ << endl;
}

typedef unsigned int uint_t;
using unit_2 = unsigned int;

void func(int x){
    std::cout << "func x:::" << x <<endl;
}

//typedef std::map<std::string, int> map_int_t;
//typedef std::map<std::string, std::string> map_str_t;

template <typename val> struct str_map {
    typedef std::map<std::string, val> type;
};

using map_int_t = std::map<std::string, int> ;
using map_str_t = std::map<std::string, std::string> ;

template<typename T>
using func1 = void(*)(T);

func1<int> funcx(void(*_ca)(int)){
    return _ca;
}

template <typename T = int>
void funcy(func1<T> x){
    std::cout << "funcy" << std::endl;
}

template <typename R = int, typename U>
R funcru(U val)
{
    return val;
}

class Foo{
public:
    Foo(std::initializer_list<int>){std::cout << "init lize -list " << endl;}
};

void foo(std::initializer_list<int> l){
    cout << " size of list::" << l.size() << endl;
    for(auto it = l.begin(); it != l.end(); it ++){
        cout<< ":::" << *it <<endl;
    }
}

void ff(){};
struct Foo1{
    void operator()(void){
    }
};

struct Bar{
    using fr_t = void(*)(void);

    static void func(void){
        std::cout << "func " << std::endl;
    }

    operator fr_t(void) {
        return func;
    }
};

struct A1{
    int a_;
    void mem_func(void){
        std::cout << "mem -func" << std::endl;
    }
};


void func2(void)
{
    std::cout << __FUNCTION__ << std::endl;
}

class Foo2{
public:
    static int foo_func(int a)
    {
        std::cout << __FUNCTION__ << "(" << a << ") -> :";
        return a;
    }
};

class Bar2{
public:
    int operator()(int a)
    {
        std::cout << __FUNCTION__ << "(" << a << ") -> :";
        return a;
    }
    void operator()(void){
        std::cout << __FUNCTION__ << std::endl;
    }
};

void call_when_even(int x, const std::function<void(int)> &f){
    if (!(x & 1)){
        f(x);
    }
}

void output(int x){
    std::cout << x << " ";
}

void output2(int x, int y){
    std::cout << x << "---" << y << std::endl;
}

void output_add_2(int x){
    std::cout << x + 2 << " ";
}

class AA {
public:
    int _i = 0;

    void output(int x, int y)
    {
        std::cout << x << " " << y << std::endl;
    }
};


class AB{
public:
    AB() : m_ptr(new int(0)){}
    void show() {std::cout << "m_ptr:::" << &m_ptr << std::endl;}
    ~AB(){delete m_ptr;}
private:
    int *m_ptr;
};

AB getAb(bool flag)
{
   AB a;
   AB b;

   if (flag ){
        return a;
   }else {
       return b;
   }
}

template <typename T>
void printT(T &t){
    cout << "lvalue " << endl;
}

template <typename T>
void printT(T &&t){
    cout << "rvalue " << endl;
}
template <typename T>
void testForward(T && t){
    std::cout << "-----------------" << std::endl;
    printT(t);
    printT(std::forward<T>(t));
    printT(std::move(t));
    std::cout << "-----------------" << std::endl;
}

template <typename T, T v>
struct inter_constant{
    static const T  value = v;
    typedef T value_type;
    typedef inter_constant<T,v>type;
    operator value_type() { return value;}
};

class B1: A1{

};

class C1:B1{

};
class D1{

};

template <typename ...T>
void f(T... args){
    std::cout << sizeof...(args) << std::endl;
}

void pr()
{
    std::cout << std::endl;
}

template <typename T, typename ...Args>
void pr(T head, Args ...rest )
{
    std::cout << "param ::: " << head << std::endl;
    pr(rest...);
}

template<std::size_t I = 0, typename Tuple>
typename std::enable_if<I == std::tuple_size<Tuple>::value>::type printtp(Tuple t){

}

template<std::size_t I = 0, typename Tuple>
typename std::enable_if<I < std::tuple_size<Tuple>::value>::type printtp(Tuple t){
    std::cout << std::get<I>(t) << std::endl;
    printtp<I + 1>(t);
}

template<typename... Args>
void printtp(Args ...args){
    printtp(std::make_tuple(args...));
}

template <class T>
void printarg(T t)
{
    std::cout << "expand:::" <<t << std::endl;
}

template <class... Args>
void expand(Args... args)
{
//    int arr[] = { (printarg(args), 0)...};
    std::initializer_list<int> { (printarg(args), 0)...};
}

template <typename... Args> struct Sum;

template <typename First, typename... Rest>
struct Sum<First, Rest...>
{
    enum { value = Sum<First>::value + Sum<Rest...>::value};
};

template <typename Last> struct Sum<Last>
{
    enum { value = sizeof(Last) };
};

template<int...>
struct IndexSql{};

template<int N, int... Indexes>
struct MakeIndexes: MakeIndexes<N-1, N-1, Indexes...> {};

template <int... Indexes>
struct MakeIndexes<0, Indexes...>
{
    typedef IndexSql<Indexes...> type;
};

struct AX
{
    AX(int){}
};
struct BX
{
    BX(int,double){}
};

template <typename T, typename... Args>
T* Instance(Args... args)
{
    return new T(std::forward<Args > (args)...);
}

void double_string(std::string& s)
{
    s += s;
}

char & char_number(std::string& s, std::size_t n)
{
    return s.at(n);
}

void f(int& x)
{
    cout << "lvalue::" << x << endl;
}

void f(const int& x)
{
    cout << "const lvalue::" << x << endl;
}

void f(int&& x)
{
    cout << "rvalue::" << x << endl;
}

template<typename T>
void ff(T && t)
{
    cout << "xx" << t <<endl;
}

int fx(int a)
{
    return ~a + 1;
}

void f0(const std::string & arg = "world")
{
    cout << "hello::" << arg <<endl;
}

auto fp11() -> void(*)(const std::string &)
{
    return f0;
}

int f2(int)
try
{
    throw 1;
}catch (const std::exception &e) {
    std::cerr << "stoi error::" <<std::endl;
    return 0;
}

struct A6 {
    A6(){}
    A6(int a){}
};
class B6{
public:
    explicit B6(const A6&){cout << "b6::" << endl;}
    B6 operator = (const A6&){ cout << "operator::" << endl; return *this;}
    operator A6() { cout << "operator A6::"<< endl;return A6();}
    A6 operator ()(int a) { cout << "operator A6::"<< endl;return A6(a);}
    B6 operator +() {cout << "+" << endl; return *this;};
};

void fn (B6 x) {}

class Dummy{
    double i,j;
};

class Addition{
    int x, y;
public:
    Addition(int a, int b):x(a),y(b){}
    int result() { return x + y;}
};

class Base { virtual void dummy(){}};
class Derived: public Base { int a;};


int ch603::test()
{
    {
        try{
            Base* a = new Base;
            Derived* b = new Derived;

            cout << "typeid(a)::" << typeid(a).name() << endl;
            cout << "typeid(b)::" << typeid(b).name() << endl;
            cout << "typeid(*a)::" << typeid(*a).name() << endl;
            cout << "typeid(*b)::" << typeid(*b).name() << endl;

//            Base *pba = new Derived;
//            Base *pbb = new Base;
//            Derived *pd;
//
//            cout << "typeid(pba)" << typeid(pba).name() << endl;
//
//            Derived *pd2 = new Derived;
//            Base * pb2;

//            pd = static_cast<Derived*>(pbb);
//            if (pd == 0){
//                cout << "static-cast" <<endl;
//            }

//            pd2 = static_cast<Base*>(pd2);
//            if (pd2 == 0){
//                cout << "static-cast" <<endl;
//            }

//            pd = dynamic_cast<Derived*>(pba);
//            if (pd == 0){
//                cout << "nullptr on first type-cast" <<endl;
//            }
//
//            pd = dynamic_cast<Derived*>(pbb);
//            if (pd == 0){
//                cout << "nullptr on second type-cast" <<endl;
//            }

        }catch(exception& e){
            cout << "Exception ::" << e.what() << std::endl;
        }

        cout << "----------------------" << endl;
    }


    {
        Dummy d;
//        padd = (Addition*) &d;
//        Addition *padd = dynamic_cast<Addition*>(&d);
        Addition *padd = reinterpret_cast<Addition*>(&d);
//        Addition *padd = const_cast<Addition*>(&d);
//        Addition *padd = static_cast<Addition*>(&d);

        cout << padd->result() << endl;
        cout << "----------------------" << endl;
    }

    {
        A6 a6;
        B6 b6(a6); //b6
        b6 = a6; //operator
        A6 a8 = b6; //operator A6
        A6 aa = b6(1);

//        fn(a6);
//        fn(b6);

    }

    {
        f0();
        auto p = fp11();
        std::string name("maiev");
        p(name);
        int f2(10);

        cout << "------------------------" <<endl;
    }

    {
        cout << hex << 1 << endl;
        cout << fx(1) << endl;
        int i = 0;
        ff(i);
        ff(0);
    }

    {
        auto x = [](){};
        auto y = []{};
        x();

        auto revese = map<string, int,function<bool(const string&, const string&)>>{
            [](const string& a ,const string& b) { return a > b;}
        } = {
                {"a", 2},
                {"b", 1},
                {"c", 0},
        };

//        assert(revese.begin()->first == "a");
//        assert(revese.begin()->second == 2);
    }

    {
        int i = 2;
        const int ci = 2;
        f(i);
        f(ci);
        f(3); //f(int && );
        f(std::move(i));

        int&& x = 1;
        f(x); // f(int &)
        f(std::move(x));
        std::cout << "------------------------------" << std::endl;
    }

    {
        std::string str = "Test";
        double_string(str);
        std::cout << str << endl;

        char_number(str, 1) = 'A';
        std::cout << str << endl;

        const std::string &r2 = str + str;

        std::string&& r3 = str + str;
        r3 += "XX";
        std::cout  << r3 << endl;
        std::cout << "------------------------------" << std::endl;
//        auto t = create_task([]() ->int{
//            return 0;
//        });
//
//        auto increment = [](int n) { return n + 1;};
//
//        int result = t.then(increment).then(increment).then(increment).get();
//
//        wcout << result << endl;
    }

    {
        AX* pa = Instance<AX>(1);
        BX* pb = Instance<BX>(1, 1.1);

        using T = MakeIndexes<3>::type;
        std::cout << typeid(T).name() << std::endl;

        std::cout << "-------------------------------" << std::endl;

        std::cout << Sum<int, double>::value << std::endl;
        std::tuple<int> tp1 = std::make_tuple(1);
        std::tuple<int,double> tp2 = std::make_tuple(1,1.1);
        std::tuple<int,double,std::string> tp3 = std::make_tuple(1,1.1, "maiev");

        std::tuple<> tp;

        /*
        expand(1,2,3,3,4,5);
        pr(1,2,2,3,3,"qq");
        printtp(1,2,3,4, "qq");
         */
    }

    {
        typedef inter_constant<bool, true> true_type;
        typedef inter_constant<bool, false> false_type;

        std::cout << is_fundamental<AB>::value << std::endl;
        std::cout << is_fundamental<int>::value << std::endl;
        std::cout << is_fundamental<A1>::value << std::endl;
        std::cout << is_class<inter_constant<bool, false>>::value << std::endl;

        std::cout << is_base_of<A1, C1>::value << std::endl;
        std::cout << is_base_of<B1, C1>::value << std::endl;
        std::cout << is_base_of<C1, C1>::value << std::endl;
        std::cout << is_base_of<D1, C1>::value << std::endl;

        true_type b2c;
        false_type c2b;

        std::cout << std::boolalpha;

        std::cout << false << '\n';
        std::cout << true << '\n';
        std::cout << b2c << '\n';
        std::cout << c2b << '\n';

        std::cout << "all-extends::" << std::is_same<int, std::remove_all_extents<int[2][3]>>::value << std::endl;
        std::cout << "extent::" << std::is_same<int, std::remove_extent<int[2]>>::value << std::endl;

        typedef std::common_type<unsigned char, short, int>::type NumberType;
        using x = std::common_type<unsigned char, short, int>::type;
        std::cout << std::is_same<int, NumberType >::value << std::endl;
        std::cout << std::is_same<int, x>::value << std::endl;

        typedef std::conditional<(sizeof(long long) > sizeof (long double)),long long ,long double>::type max_size_t;
        std::cout << typeid(max_size_t).name() << std::endl;

    }

    {
        testForward(1);
        int x = 1;
        testForward(x);
        testForward(std::forward<int>(x));
    }

    {
        AB a;
        AB b;
        a.show();
        b.show();

        int i = 10;
        std::cout << "i ::" << i << std::endl;
        std::cout << "&i ::" << &i << std::endl;

        int *pa = &i;
        int *pb = &i;
        int *pc = pa;

        std::cout << "pa ::" << pa << std::endl;
        std::cout << "pb ::" << pb << std::endl;
        std::cout << "pc ::" << pc << std::endl;

        std::cout << "&pa ::" << &pa << std::endl;
        std::cout << "&pb ::" << &pb << std::endl;
        std::cout << "&pc ::" << &pc << std::endl;

        std::cout << "-------------------" << std::endl;
        i = 20;

        std::cout << "pa ::" << pa << std::endl;
        std::cout << "pb ::" << pb << std::endl;
        std::cout << "pc ::" << pc << std::endl;

        std::cout << "&pa ::" << &pa << std::endl;
        std::cout << "&pb ::" << &pb << std::endl;
        std::cout << "&pc ::" << &pc << std::endl;
    }

    {
        auto tp = std::make_tuple(1, "a", 22);

        std::cout << typeid(tp).name() << std::endl;

        int y;
        std::tie(std::ignore, std::ignore, y) = tp;

        std::cout << get<0>(tp)<< std::endl;
        std::cout << get<1>(tp)<< std::endl;
        std::cout << get<2>(tp)<< std::endl;
    }

    {
        AA aa;
        std::function<void(int,int)> fr = std::bind(&AA::output, &aa, std::placeholders::_1, std::placeholders::_2);
        fr(1,2);

        //???????????
        auto fr_i = std::bind(&AA::_i, &aa);
        fr_i() = 123;
        std::cout << aa._i << std::endl;
    }

    {
        int a = 0, b = 1;
//        auto f1 = [=]{ return a++;};//a.不允许呗改变
        std::function<int(void)> f2 = std::bind([](int a) {return a;}, 123);

        using func_t = int(*)(int);
        func_t f = [](int a) { return a;};
        f(123);
    }

    {
        std::bind(output2, 1, 2)();
        std::bind(output2, 2,3)();
        std::bind(output2,2, std::placeholders::_3)(1,20,3);
        auto fr = std::bind(output2,2, std::placeholders::_3);
        fr(1, 20, 3);
    }

    {
        auto fr = std::bind(output, std::placeholders::_1);
        for(int i = 0; i < 10; i ++){
            call_when_even(i, fr);
        }
        std::cout << std::endl;
    }

    {
        auto fr = std::bind(output_add_2, std::placeholders::_1);
        for(int i = 0; i < 10; i ++){
            call_when_even(i, fr);
        }
        std::cout << std::endl;
    }

    {
        std::function<void(void)> fr1 = func2;
        fr1();

        std::function<int(int)> fr2 = Foo2::foo_func;
        std::cout << fr2(10) << std::endl;

        Bar2 bar;
        fr2 = bar;
        std::cout << fr2(10) << std::endl;

        Bar b;
        b();

        A a1(bar);
        a1.notify();
    }

    {
        void (A1::*mem_func_ptr)(void)= &A1::mem_func;
        int A1::*mem_obj_ptr = &A1::a_;

        A1 aa;

        (aa.*mem_func_ptr)();
        aa.*mem_obj_ptr = 123;
    }

    {
        int i = 10;
        std::cout << i << std::endl;
    }

    {
        int i = 1000;
        std::cout << i << std::endl;
    }

    std::map<std::string, int> mm = {
            {"1", 1},
            {"2", 2},
            {"3", 3},
            {"4", 4},
    };

    for(auto p : mm){
        std::cout << p.first << p.second << std::endl;
    }

    int a = 1.1;
//    int b = { 1.1 };

    float fa = 1e40;
//    float fb = { 1e40; };
//    float fc =  { (unsigned int) -1 };
    float fd =   (unsigned int) 10;

    foo({});
    foo({1,2});
    Foo foo{1,2,3,4,5};

    funcru(123);
    funcru<long>(123);

//    func1<int> f = funcx(func);
//    f(12);
    funcy(func);

    str_map<int>::type map1;
    map_int_t map2;

    int i = 0;
    int sum = 0;
    for(i = 0 ; i< 100;i++){
        sum += i;
    }

    cout << "sum of ..." << sum <<endl;

    pthread_t pthread1, pthread2;
    if (pthread_create(&pthread1, NULL, func, NULL)){
        cout << "pthread -created error:::" << endl;
        return 1;
    }

    if (pthread_create(&pthread2, NULL, func, NULL)){
        cout << "pthread -created error:::" << endl;
        return 1;
    }

    pthread_join(pthread1, NULL);
    pthread_join(pthread2, NULL);

    cout << total << endl;

    cout << "size of howManyBytes:::" << sizeof(howManyBytes) << endl;
    cout << "size of char :::" << sizeof(char) << endl;
    cout << "size of int :::" << sizeof(int) << endl;

    cout << "offset of char a:::" << offsetof(howManyBytes, a) << endl;
    cout << "offset of int b:::" << offsetof(howManyBytes, b) << endl;

    cout << "align of  howmanybytes::" << alignof(howManyBytes) << endl;

    {
        Rectangle rectangle;
        Triangle triangle;
        Polygon *p1 = &rectangle;
        Polygon *p2 = &triangle;
//        Polygon *p3 = new Polygon;

        p1->set_values(1,2);
        p2->set_values(1,2);
//        p3->set_values(1,2);

        p1->xx();
        p2->xx();
        p1->printArea();
        p2->printArea();
//        cout << "polygon-area::" << p3->area() << endl;
    }

    {
        cout << "----------------------" << endl;
        try {
//            throw myex;
//            throw 1;
            throw new int(1);
        }catch(int e) {
            cout << "err::" << e << endl;
        }catch(int* e) {
            cout << "::" << *e << endl;
        }catch(exception& e) {
            cout << e.what() << endl;
        }catch(...) {
            cout << "default ..." << endl;
        }
    }


    return 0;
}