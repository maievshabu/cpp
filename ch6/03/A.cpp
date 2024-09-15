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


int ch603::test()
{
    {
        auto tp = std::make_tuple(1, "a", 22);

        int y;
        std::tie(std::ignore, std::ignore, y) = tp;

        std::cout << get<0>(tp)<< std::endl;
        std::cout << get<1>(tp)<< std::endl;
        std::cout << get<2>(tp)<< std::endl;
    }

    {
        AA aa;
        std::function<void(int,int)> fr = std::bind(&AA::output, aa, std::placeholders::_1, std::placeholders::_2);
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
    return 0;
}