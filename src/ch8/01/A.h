//
// Created by xiaowei003 on 2024/9/28.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H
#include <tuple>
#include <functional>

namespace ch801{
    class A {
    };

    template<typename T>
    void printV(T arg){
        cout  << "---------------" << endl;
        cout << "arg is const:" << std::is_const<T>::value <<endl;
        cout << "arg is ref:" << std::is_reference<T>::value <<endl;
        cout << "arg:" << arg << endl;
        cout  << "---------------" << endl;
    }

    template <typename T>
    void outR(T& arg){
        if (std::is_array<T>::value){
            cout << "got array of :" << std::extent<T>::value << endl;
        }
    }

    template <typename T>
    void passR(T&& arg)
    {
        cout << "arg is const:" << std::is_const<T>::alue <<endl;
        cout << "arg is ref:" << std::is_reference<T>::value <<endl;
        cout << "------------------" << endl;
    }

    void printStr(std::string const & s)
    {
        cout << s << endl;
    }

    template <typename T>
    void printStr(T arg)
    {
        cout << "arg is ref:" << std::is_reference<T>::value <<endl;
        printStr(arg);
    }

    template <typename T>
    void printT(T arg)
    {
        cout << "arg is ref:" << std::is_reference<T>::value <<endl;
        cout << "------------------" << endl;
    }

    std::string returnString()
    {
        return "Hi";
    }

    std::string const returnConstantString()
    {
        std::string const hi = "HI";

        return hi;
    }

    std::tuple<int, float> foo()
    {
        return {1, 1.1f};
    }

    class Foo{
    public:
        Foo(tuple<int,float>){
            cout << "Foo::Foo(tuple)" << endl;
        }

        template<typename... Args>
        Foo(Args... args){
            cout << "Foo::Foo(args...)" <<endl;
        }
    };

    void ff(std::pair<int, const char*>);
    void gg(std::pair<int const, std::string>);

//    typname std::tuple<int, float> tutt;

    std::tuple<int, int, int> fx()
    {
        return { 1,2, 3};
    }

    template<typename T>
    void fx1(T const& val)
    {
        cout << std::is_pointer<T>::value ? *val : val <<endl;
    }

    template<typename T>
    void fx2(T const&val)
    {
        if (std::is_pointer<T>::value){
            cout << "foo() called for a pointer" << endl;
        }else{
            cout << "foo() called for a value" << endl;
        }
    }

    template<typename T>
    void foo_impl(T val ,true_type);

    template<typename T>
    void foo_impl(T val ,false_type);

    template<typename T>
    void foo1(T val)
    {
        foo_impl(val, is_integral<T>());
    }

    template<typename T1, typename T2>
    typename std::common_type<T1, T2>::type min1(T1 const& t1 ,T2 const& t2);

    template<typename T, T val>
    struct integral_constat_1{
        static constexpr T value = val;
        typedef T value_type;
        typedef integral_constat_1<T,val> type;
        constexpr operator value_type() {
            return val;
        }

        typedef integral_constat_1<bool, true> true_type;
        typedef integral_constat_1<bool, false> false_type;
    };
}



#endif //UNTITLED_A_H
