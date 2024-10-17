//
// Created by xiaowei003 on 2024/9/4.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H

#include <string>
using namespace std;
namespace A06 {
    class A {
    public:
        typedef int foo;
    };

    template<typename T>
    void f(typename T::foo a) { std::cout << "T::foo:::" << a << " ---" << hex << &a << std::endl; }

    template<typename T>
    void f(T a) { std::cout << "T:::" << a << "---" << hex << &a << std::endl; }

    enum{
        K1, k2, k3
    }anon_e;

    union{
        decltype(anon_e) key;
        char *name;
//        string name2; //error
    }anon_u;

    struct {
        decltype(anon_u) id;
    }anon_s[100];

//    template<typename T1, typename T2>
//    void Sum(T1 & t1, T2 & t2, decltype( t1 + t2) &s){
//        std::cout << "template sum :::" << std::endl;
//        s = t1 + t2;
//    }

//    template<typename T1, typename T2>
//     auto Sum(T1 & t1, T2 & t2)->decltype(t1+t2){
//        return t1 + t2;
//    }

    template<typename T1, typename T2>
    auto Sum(const T1 & t1, const T2 & t2)-> decltype(t1 + t2){
        return t1 + t2;
    }

    void Sum(int a[], int b[], int c[])
    {
        std::cout << "sum :::[]" <<endl;
    }

    typedef struct{
        int age;
    } Pp, *Pptr;

    class OuterType{

        struct InnerType {int i;};

        InnerType getInner();
        InnerType it;
    };

    auto OuterType::getInner()->InnerType {
        return it;
    }

    int (*(*pf())())(){
        return nullptr;
    }

    auto pf1() -> auto(*)() -> int(*)(){
        std::cout << "pf func" << std::endl;
        return nullptr;
    }

    double foo(int a){
        return (double) a + 0.1;
    }

    int foo(double b) {
        return (int)b;
    }

    template<typename T>
    auto forward(T t) -> decltype(foo(t)){
        return foo(t);
    }
}
#endif //UNTITLED_A_H
