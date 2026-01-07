//
// Created by redredmaple on 2025/8/27.
//

#ifndef MAIEV_ARRAY_H
#define MAIEV_ARRAY_H

#include <array>
#include <iostream>
#include <tuple>
using namespace std;

int arrayTest(){
    array<int, 6> ar = {1,2};

    cout << "ar.at(): ";
    for(int i = 0; i < 6; i++){
        cout << " " <<  ar.at(i) << " ";
    }
    cout << endl;

    cout << "get<0>(ar): ";
    cout << get<0>(ar)<<" ";
    cout << get<1>(ar)<<" ";
    cout << get<2>(ar)<<" ";
    cout << get<3>(ar)<<" ";
    cout << get<4>(ar)<<" ";
    cout << get<5>(ar)<<" ";
    cout << endl;

    cout << "ar[]: ";
    for(int i = 0; i < 6; i++){
        cout << " " <<  ar[i] << " ";
    }
    cout << endl;

    cout << "front: " <<ar.front() << endl;
    cout << "back: " <<ar.back() << endl;
    cout << "size: " << ar.size() << endl;
    cout << "maxSize: " << ar.max_size() << endl;

    array<int,6> ar2;
    cout << "swap: ";
    ar.swap(ar2);
    std::for_each(ar2.begin(), ar2.end(), [](int elem){
        cout << elem << " ";
    });
    cout << endl;

    cout << "ar2 is empty: " << ar2.empty() << endl;
    cout << "ar fill: ";
    ar.fill(1);
    for( int _ar : ar){
        cout << _ar << " ";
    }
    cout << endl;

    return 1;
}


#endif //MAIEV_ARRAY_H
