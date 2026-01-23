//
// Created by redredmaple on 2026/1/23.
//

#ifndef C11_D123_H
#define C11_D123_H
#include "common.h"
using namespace chrono;

namespace d123 {
    void test();


//    template<class T>
//    struct alignment_of : std::integral_constant<std::size_t, alignof(T)>{};

    _Pragma("pack(1)")
    struct MyStruct{
        char a;
        int b;
        short c;
        long long d;
        char e;
    };
    _Pragma("pack()");

    //alignas(int) char c; char 就按int的方式对齐了

    struct Base{
        int x;
        double y;
        string s;
        Base(int i): x(i),y(0){}
        Base(int i, double j): x(i),y(j){}
        Base(int i, double j, const string& str): x(i),y(j),s(str){}
    };

    //继承构造 / 委托构造
    struct Derived: Base{
        using Base::Base; //继承基类构造函数
    };

    class Timer{
    public:
        Timer():m_begin(high_resolution_clock::now()){}
        void reset() { m_begin = high_resolution_clock::now();}

        template<typename Duration=milliseconds>
        int64_t elapsed() const{
            return duration_cast<Duration>(high_resolution_clock::now() - m_begin).count();
        }
        int64_t elapsed_micro()const{
            return elapsed<microseconds>();
        }
        int64_t elapsed_nano()const{
            return elapsed<nanoseconds>();
        }
        int64_t elapsed_seconds()const{
            return elapsed<seconds>();
        }
        int64_t elapsed_minutes()const{
            return elapsed<minutes>();
        }
        int64_t elapsed_hours()const{
            return elapsed<hours>();
        }
    private:
        time_point<high_resolution_clock> m_begin;
    };
};


#endif //C11_D123_H
