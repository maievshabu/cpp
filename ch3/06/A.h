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

//    enum class{
//        K1, k2, k3
//    }anon_e;
//
//    union{
//        decltype(anon_e) key;
//        string name;
//    }anon_u;

//    struct {
//        decltype(anon_u) id;
//    }anon_s[100];

    template<typename T1, typename T2>
    void Sum(T1 & t1, T2 & t2, decltype( t1 + t2) &s){
        s = t1 + t2;
    }
}
#endif //UNTITLED_A_H
