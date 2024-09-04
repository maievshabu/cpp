//
// Created by xiaowei003 on 2024/9/4.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H


class A {
public:
    typedef int foo;
};

template <typename T>
void f(typename T::foo a){ std::cout<<"T::foo:::" << a <<" ---"<< hex << &a << std::endl;}

template <typename T>
void f(T a) { std::cout<< "T:::" << a << "---" << hex  << &a << std::endl;}

#endif //UNTITLED_A_H
