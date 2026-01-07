//
// Created by redredmaple on 2025/12/10.
//

#ifndef STUDY_TEMPLATE_H
#define STUDY_TEMPLATE_H

namespace _tpl{
template<typename T, typename T::type n = 0>
class X;
struct S{
    using type = int;
};

//template<typename T>
//concept C1 = sizeof(T) != sizeof(int);

//template<C1 T>
//struct S1{};
//
//template<C1 T>
//using Ptr = T*;

//S1<int>* p1;
//Ptr<int> p2;

//template<typename T>
//struct S2{Ptr<int> x;};

//template<typename T>
//struct s3{Ptr<T> x;};

//template<template<C1 T> typename X>
//struct S4{
//    X<int> x;
//};

//template<typename T>
//concept C2 = sizeof(T) == 1;
//
//template<C2 T> struct Ss{
//};

//template struct Ss<char[1]>;

//using T1 = X<S,int,int,int>;
//using T2 = X<>;
//using T3 = X<1>;
//using T4 = X<int>;
using T5 = X<S>;

struct less_than7: std::unary_function<int,bool>{
    bool operator()(int i) const{ return i < 7;}
};

struct Foo{

    void display_greeting(){
        std::cout << "hello world.\n";
    }

    void display_number(int i){
        std::cout << "number: " << i << '\n';
    }

    int add_xy(int x, int y){
        return data + x + y;
    }

    int add_many(){
        return 0;
    }

    template <typename T, typename ...Args>
    int add_many(T first, Args... rest){
        return first + add_many(rest...);
    }

//    template<typename ... Args> int add_many(Args... args){
//        return data + (args + ...);
//    }

    int data = 7;
};

void test1();
}

template<typename ...Args>
class TTuple;

#endif //STUDY_TEMPLATE_H
