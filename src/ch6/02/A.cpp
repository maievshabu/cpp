//
// Created by xiaowei003 on 2024/9/8.
//

#include "A.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace ch602;
using namespace std;

int ch602::test()
{
    cout << sumOfFloat(3, 1.1, 2.2,3.1) <<endl;

    Ttuple<int> tif;
    Ttuple<int, double> tb;
    Ttuple<int, int, double> tiid;
    NonTypeTemplate<1, 0,2> ntval;

    Template<int,double> xy;

    A a;
    a.show();

    int *pa = nullptr;

    nullptr_t n1, n2;

    if (n1 == 0){
        cout << "nullptr== 0" << endl;
    }

    if (n1 == n2){
        cout << "nullptr n1 == n2" << endl;
    }

    if (pa == 0){
        cout << "nullptr pa == 0" << endl;
    }

    if (nullptr == 0){
        cout << "nullptr == 0 " <<endl;
    }

    cout << "is_pod :::" << is_pod<A>::value << endl;

    typeid(nullptr);
//    throw(nullptr);

    cout << "size of nullptr:::" << sizeof(nullptr) << endl;
    cout << "size of nullptr_t:::" << sizeof(nullptr_t) << endl;

//    A b(a);\
    cout << "-------------------" <<endl;
    Func(3);
    Func('a');

    cout << "-------------------" <<endl;
    ConvType ci(3);
//    ConvType cc('a');

    cout << "-------------------" <<endl;
    ConvType c2 = 'b';

//    NoHeapAlloc *noHeapAlloc = new NoHeapAlloc(10);
    NoHeapAlloc noHeapAlloc;


    int girls = 3, boys = 4;

    // [capture] (parameters) mutable -> return_type { statement }
    /**
     * [var]
     * [=]
     * [&]
     * [&var]
     * [this]
     */

    auto totalChild = [=] ()-> int { return girls + boys;};

    cout << "total-child:::" << totalChild() << endl;

    _functor _func;
    cout <<_func(1,3) << endl;

    Tax high(0.4, 3000);
    Tax middle(0.24, 300000);

    cout << "high:::" << high(375000) << endl;
    cout << "middle:::" << middle(275000) << endl;

    int jj = 12;
    auto by_val = [=](){ return jj + 1;};
    auto by_ref = [&](){ return jj + 1;};

    cout << "by val:::" << by_val() << endl; //13
    cout << "by ref:::" << by_ref() << endl; //13

    jj++;
    cout << "by val:::" << by_val() << endl; //13?
    cout << "by ref:::" << by_ref() << endl; //14?

    int val;
//    auto const_val = [=](){ val = 3;};
    auto const_val = [=]()mutable{ val = 3;};

    auto const_ref = [&](){val=3;};

    auto const_param = [&](int v) {v= 3;};

    vector<int> vc = { 1,2,23,3};

    for_each(vc.begin(), vc.end(), [](int i){
        i = i * i;
        return i;
    });

    for(int vx: vc){
        cout << "i ::: " << vx << endl;
    }
    int num = 3;
    auto pc = find_if(vc.begin(), vc.end(), [=](int i){
        return i > num;
    });

    cout << "--------------" << endl;
    {
        int i = 1;
        {
            int j = 1;
            {
                auto pr = [i, num, j] (){
                    cout << i << num << j  << endl;
                };

                pr();
            }
        }
    }
    cout << "--------------" << endl;

    while(pc != vc.end()){
        cout << "pc:::" << *(pc++) << endl;
    }

    return 0;
}