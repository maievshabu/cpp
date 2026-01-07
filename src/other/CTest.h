//
// Created by redredmaple on 2025/8/27.
//

#ifndef MAIEV_CTEST_H
#define MAIEV_CTEST_H
#include <iostream>
using std::cout;
using std::ostream;
using std::endl;

struct CTest{
    CTest() = default;
    CTest(int i):i(i){ cout<< "CTest("<< i <<")"<<endl;};
    CTest(const CTest& c1){
        std::cout << "Copy ctor" << std::endl;
        i = c1.i;
    }
    CTest& operator=(const CTest& c1){
        std::cout << "assign ctor" << std::endl;
        if (&c1 != this){
            i = c1.i;
        }

        return *this;
    }
    int getI()const{return i;}
    ~CTest(){cout << "~CTest("<< this <<")"<< endl;}
    bool operator==(int q) const{
        return q == i;
    }
    bool operator>(int q) const{
        return q > i;
    }
    friend ostream& operator<<(ostream& os, const CTest& other);
private:
    int i;
};

ostream& operator<<(ostream& out, const CTest& other){
    out << &other << ": i: ";
    out << other.i;
    return out;
}
#endif //MAIEV_CTEST_H
