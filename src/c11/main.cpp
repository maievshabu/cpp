//
// Created by redredmaple on 2026/1/17.
//

#include <iostream>
using namespace std;

#include "d117.h"
#include "d119.h"
#include "d120.h"

int g_constructCount = 0;
int g_copyConstructCount = 0;
int g_destructCount = 0;

int main(){

    std::cout << "C++ 11" << std::endl;
//    d117::test();
//    d119::test();
    d120::test();

    return 0;
}
