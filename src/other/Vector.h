//
// Created by redredmaple on 2025/8/27.
//

#ifndef MAIEV_VECTOR_H
#define MAIEV_VECTOR_H
using namespace std;
#include "CTest.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <tuple>

template<typename T>
void print(const T& container){
    cout << "for_each:";
    std::for_each(container.begin(), container.end(), [](typename T::value_type elem){
        cout << elem << "]-[ ";
    });
    cout << endl;
    cout << "---" << endl;
}

void vectorTest(){
    cout << "init" << endl;
    vector<int> v1;
    vector<int> v2(v1);
    vector<int> v3(5,10);

    cout << "insert: push_back ";
    v1.push_back(1);
    v1.push_back(2);
    print(v1);
    cout << endl;

    int len = 3;
    vector<CTest> vc;
    vc.reserve(len); //先占空间, 再复制, 注意vector的动态扩容~~~~会产生一定的开销
    cout << "size: " << vc.size() << endl;

    cout << "insert: emplace_back "<< endl;
    for(int i = 0 ;i < len; i++){
        vc[i] = CTest(i);
//        vc.emplace_back(CTest(i));
    }

    cout << "size: " << vc.size() << endl;
    print(vc);

    cout << "access:" << vc.at(1) << " " << vc[1] << endl;
    cout << "emplace_back after size: " << vc.size() << endl;

    cout << "delete";
    vc.pop_back(); //delete last;
    //delete for eq = 1 ctest(1);
    vc.erase(find(vc.begin(), vc.end(), 1));

    if (!vc.empty()){
        cout << "vc is not empty" << endl;
    }

}

#endif //MAIEV_VECTOR_H
