//
// Created by redredmaple on 2026/1/17.
//

#include <iostream>
using namespace std;

#include "d117.h"
#include "d119.h"
#include "d120.h"
#include "d121.h"
#include "d122.h"

int g_constructCount = 0;
int g_copyConstructCount = 0;
int g_destructCount = 0;
std::once_flag flag;

int main(){

    std::cout << "C++ 11" << std::endl;
//    d117::test();
//    d119::test();
//    d120::test();
//    d121::test();
    d122::test();


    return 0;
}
