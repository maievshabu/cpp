//
// Created by redredmaple on 2026/1/9.
//

#include <memory>
#include "empty.h"
#include "01.h"
//using namespace d109;
using namespace ::std;

void d109::test() {

#ifndef TRUE

    {
        Widget<int> w1;
        Widget<int> w2;
//        w2 = w1;
        swap(w1, w2);
    }


    {

        Rational a(1,2);
        Rational b(3,5);
//        Rational c = a * b;
        Rational d = 2 * a;
        cout << "xx" << endl;
    }
    {
        Empty e1; //默认构造
        Empty e2(e1); //拷贝构造
        e2 = e1; //拷贝赋值

//        using namespace std;
//        std::cout << "size of Empty: " << sizeof(Empty) << std::endl;
//        std::cout << "size of e1: " << sizeof(e1) << std::endl;
//        std::cout << "size of e2: " << sizeof(e2) << std::endl;
    }

    {
        shared_ptr<Invest> sp(new Invest);
    }

    {
        BuyTransaction b;
    }

    {
        TimeKeeper *ptr = getTimeKeeper();
        delete ptr; //需要主动释放 [如果没有虚基类,子类的析构不调用]
    }

//    HomeForSale h1;
//        HomeForSale h2(h1);
//        h2 = h1;

#endif

}