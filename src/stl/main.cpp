//
// Created by xiaowei003 on 2024/10/17.
//

#include "stl.h"
#include "../include/Calc.h"
//using namespace maiev;

int main(int argc ,char** argv)
{
//    stl::test_stl();
//    test_calc();
//    std::cout << test_calc2(55) << std::endl;
    Calc<int> calc;
    std::cout << calc.add(11,23)<< std::endl;
    std::cout << calc.sub(11,23) << std::endl;
    std::cout << calc.div(10,2) << std::endl;
    std::cout << calc.mul(1,2) << std::endl;

    return 1;
}