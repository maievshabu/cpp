//
// Created by xiaowei003 on 2024/9/8.
//

#include "A.h"
#include <iostream>
using namespace ch602;

int ch602::test()
{
    cout << sumOfFloat(3, 1.1, 2.2,3.1) <<endl;

    Ttuple<int> tif;
    Ttuple<int, double> tb;
    Ttuple<int, int, double> tiid;
    NonTypeTemplate<1, 0,2> ntval;

    Template<int,double> xy;


    return 0;
}