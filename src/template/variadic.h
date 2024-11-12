//
// Created by xiaowei003 on 2024/11/12.
//

#ifndef UNTITLED_VARIADIC_H
#define UNTITLED_VARIADIC_H
#include <iostream>
#include <bitset>
#include <array>

void my_print()
{
}

template<typename T>
void my_print(T arg)
{
    std::cout << arg << " ";
}

template<typename T, typename ...Types>
void my_print(T firstArg , Types... args)
{
    my_print(firstArg);
    my_print(args...);
}

template<unsigned long N>
void printBit(std::bitset<N> const& bs)
{
    std::cout << bs.template to_string<char, std::char_traits<char>, std::allocator<char>>();
}

/**
 * c14
template<typename T>
constexpr T pi {3.1415926};
template <typename T> T val{};
template <int N>
std::array<int,N> arr{};
 **/

//template<auto N>
//constexpr decltype(N) dval = N;
#endif //UNTITLED_VARIADIC_H
