//
// Created by xiaowei003 on 2024/9/29.
//

#include "array.hpp"
#include "array_iterator.hpp"
#include <iostream>
using namespace std;
using namespace stl;

namespace stl{
    void test_array()
    {
        cout << "------------------------" <<endl;
        array<int, 5> ar1,ar2{1,2,3,4,5};
        ar1.fill(10);
        cout << "before swap" << endl;
        cout << "ar data:" << *(ar1.data()) <<endl;
        cout << "ar at(3):" << ar1.at(3) <<endl;
        cout << "ar back:" << ar1.back() <<endl;

        ar1.swap(ar2);
        cout << "after swap" << endl;
        cout << "ar data:" << *(ar1.data()) <<endl;
        cout << "ar at(3):" << ar1.at(3) <<endl;
        cout << "ar back:" << ar1.back() <<endl;

//        array_iterator<int,5> it(ar2);
//        for(size_t i = 0; i < 5 ; ++ i){
//            std::cout << it[i] << " ";
//            ++it;
//        }

        for(auto it = ar1.begin(); it != ar1.end(); ++it){
            cout << *it <<endl;
        }

        for(auto it = ar2.begin(); it != ar2.end(); ++it){
            cout << *it <<endl;
        }
    }
}
