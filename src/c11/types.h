//
// Created by redredmaple on 2026/1/17.
//

#ifndef C11_TYPES_H
#define C11_TYPES_H

#include <iostream>
#include <string>
#include <map>

template<typename T, typename U = int, U N = 0>
struct Foo{
    //#...
};

template<typename T = int>
T Func(T z){
}

#endif //C11_TYPES_H
