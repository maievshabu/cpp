//
// Created by xiaowei003 on 2024/9/28.
//

#include "A.h"
#include <iostream>
#include <functional>

using namespace std;

namespace ch801{

    void maiev_const()
    {
        std::string cx1 = "hi";
        std::string cx2 = "hi";

        std::string const c1 = "c1";
        const std::string c2 = "c2";

        cx1 = "HI";  //ok
//        c1 = "HI"; //error
//        c2 = "HI"; //error

        std::string const & c3 = c1;
//        std::string & const c32 = cx1; //这是一种错误的写法
        std::string &cx3 = cx1; //
//        c3[0] = "H"; //error c3 is const
        cx3[0] = 'H'; //ok
        cx3 = "H"; //ok

        std::string const * c41 = &c1; //常量指针, 指针可以改，指向不可改
        c41 = &c2; //ok
        c41 = &cx1; //ok ? 非const -> const;
//        *c41 = "qqqqq"; //error

        std::string * const c42 = &cx1; // 指针是不可改
        cout << *c42 << endl;
//        c42 = &c2; //error
        *c42 = "HH";
        cout << *c42 << endl;
    }

    static void maiev_print()
    {
        string name("maiev");
        int i = 10;
        int *pi = &i;
        int &ri = i;

//        printV("hello"); // hello
//        printV(name); //maiev
//        printV(i); //i
//        printV(pi); //pi
//        printV(ri); //i
//
//        printV(std::move("hello")); //hello
//        printV(std::move(name)); //maiev
//        printV(std::move(i)); //10
//        printV(std::move(pi)); //pi
//        printV(std::move(ri)); //i
//        printV(returnString());
//        printV("hi");
//        int arr[4]={1,2,3};
//        printV(arr);
//
//        //reference [no tmp, no move]
//        outR(name);
//        outR("hi");
//        outR(ri);
//        outR(returnConstantString());
//        std::string const c ="HI";
//        outR(std::move(c)); //error

//        passR(name);
//        passR(i);
//        passR(pi);
//        passR(ri);
//        passR(move(name));

        std::string s = "Hello";
        printStr(s);
        printStr(std::cref(s));
    }

    void maiev_test()
    {
        maiev_print();
    }
}