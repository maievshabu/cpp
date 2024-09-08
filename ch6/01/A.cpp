//
// Created by xiaowei003 on 2024/9/8.
//

#include "A.h"

int ch601::test()
{
    cout << "ch601::test" << endl;

    struct MyType{
        constexpr MyType(int x):i(x){}
        int i;
    };

    constexpr Date PRCfound(1949, 10, 1);
    constexpr int foundMonth = PRCfound.GetMonth();

    cout << "found month :::" << foundMonth << endl;

//    constexpr struct MyType { int i;}
    constexpr MyType mt = {0};

    int fib[] = {
            Fibonacci(11), Fibonacci(12),
            Fibonacci(13), Fibonacci(14),
            Fibonacci(15), Fibonacci(16),
    };

    int fib1[] = {
            Fibo<11>::val, Fibo<12>::val,
            Fibo<13>::val, Fibo<14>::val,
            Fibo<15>::val, Fibo<16>::val,
    };

    for( int i : fib1)
        cout << i << endl;

    return 1;
}

