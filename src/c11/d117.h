//
// Created by redredmaple on 2026/1/17.
//

#ifndef EFFECTIVE_D117_H
#define EFFECTIVE_D117_H

#include <iostream>
#include <vector>

namespace d117{
    void test();

    template<typename T> void func(T x) {}
    template<typename T> void func(T* x) {}
    template<typename T> void func(T& x) {}

//    template<typename T> void func(const T x) {}
    template<typename T> void func(const T* x) {}
    template<typename T> void func(const T& x) {}

    template<class A>
    void func(void){
        auto val = A::get();
        std::cout << val << std::endl;

        //....
    }

    int* func_pint(int);
//    template<class ContainerT>
//    class Foo{
//        typename ContainerT::iterator it_;
//    public:
//        void func(ContainerT& container){
//            it_ = container.begin();
//        }
//    };
//    template<class ContainerT>
//    class Foo<const ContainerT>{
//        typename ContainerT::const_iterator it_;
//    public:
//        void func(const ContainerT& container){
//            it_ = container.begin();
//        }
//    };

    template<class ContainerT>
    class Foo{
        decltype(ContainerT().begin()) it_;
    public:
        void func(ContainerT& container){
            it_ = container.begin();
        }
    };

//    template<typename R, typename T, typename U>
//    R add(T t, U u){
//        return t + u;
//    }

    /**
     *
     * //error
     * template<typename T, typename U>
     * decltype(t+u) add(T t, U u){
     *      return t+u;
     * }
     *
     */

//    template<typename T, typename U>
//    decltype(T()+ U()) add(T t, U u){
//        return t + u;
//    }

    template<typename T, typename U>
    decltype((*(T*)0) + (*(U*)0)) add(T t, U u){
        return t + u;
    }

    template<typename T, typename U>
    auto add2(T t, U u)->decltype(t+u){
        return t+u;
    }

    int& foo(int & i);
    float foo(float& f);
    template<typename T>
    auto func(T& val) -> decltype(foo(val)){
        return foo(val);
    }

}


#endif //EFFECTIVE_D117_H
