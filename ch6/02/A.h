//
// Created by xiaowei003 on 2024/9/8.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H

#include <stdio.h>
#include <stdarg.h>

namespace ch602{
    class A {
    public:
        A() = default;
        A(int i) : _i(i){}
        A(const A &) = delete;
        void show() { std::cout <<"A:::" << _i << std::endl;}
    private:
        int _i;
    };

    int test();

    double sumOfFloat(int count, ...){
        va_list ap;
        double sum = 0;
        va_start(ap, count);
        for(int i = 0 ;i < count; i ++)
            sum += va_arg(ap, double);
        va_end(ap);

        return sum;
    }

    template<typename ...Elements> class Ttuple{};

    template<int ...A> class NonTypeTemplate{};

    template<typename T1, typename T2> class B{};
    template<typename ...A> class Template:private B<A...>{};

    template<typename Head, typename... Tail>
    class Ttuple<Head, Tail...>: private Ttuple<Tail...>{
        Head head;
    };

    template<> class Ttuple<>{};

    class ConvType{
    public:
        ConvType(int i) {};
        explicit ConvType(char c)= delete;
    };

    void Func(ConvType ct) { std::cout << "Func" << std::endl;}

    class NoHeapAlloc{
    public:
        void *operator new (std::size_t) = delete;
    };

    class _functor{
    public:
        int operator () (int x, int y) { return x + y;}
    };

    class Tax{
    private:
        float rate;
        int base;
    public:
        Tax( float r, int b) : rate(r),base(b){}
        float operator () (float money) { return (money - base) * rate;}
    };

}
#endif //UNTITLED_A_H
