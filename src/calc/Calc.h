//
// Created by xiaowei003 on 2024/10/17.
//

#ifndef UNTITLED_CALC_H
#define UNTITLED_CALC_H
#include <iostream>

//namespace maiev{
    template <typename T>
    class Calc
    {
    public:
        Calc() = default;
        T add(T a, T b);
        T sub(T a, T b);
        T div(T a, T b);
        T mul(T a, T b);
    private:
        T result;
    };
//}

template <typename T>
T Calc<T>::add(T a, T b) {
    return a + b;
}

template <typename T>
T Calc<T>::sub(T a, T b) {
    return a - b;
}

template <typename T>
T Calc<T>::div(T a, T b) {
    return a /b;
}

template <typename T>
T Calc<T>::mul(T a, T b) {
    return a * b;
}

void test_calc()
{
    std::cout << "test calc" << std::endl;
}

void test_calc();

int test_calc2(int);


#endif //UNTITLED_CALC_H
