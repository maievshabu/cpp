//
// Created by redredmaple on 2025/12/10.
//

#ifndef WEB_PTR_H
#define WEB_PTR_H

#include "inc.h"
using namespace  std;

#define COUT(str) std::cout << '\n' << str << '\n'
#define DEMO(...) std::cout << #__VA_ARGS__ << " = " << __VA_ARGS__ << '\n'

namespace ptr{
    struct MyObj{
        MyObj() {std::cout << "MyObj() constructed "<< std::endl;}
        ~MyObj() {std::cout << "~MyObj() destructed "<< std::endl;}
    };

    struct Container: std::enable_shared_from_this<Container>{

        std::shared_ptr<MyObj> memberObj;
        void createMember(){
            memberObj = make_shared<MyObj>();
        }

        shared_ptr<MyObj> getAsMyObj(){
            return shared_ptr<MyObj>(shared_from_this(), memberObj.get());
        }
    };
    struct Base
    {
        Base() { std::cout << "Base::Base()\n"; }

        // Note: non-virtual destructor is OK here
        ~Base() { std::cout << "Base::~Base()\n"; }
    };

    struct Derived : public Base
    {
        Derived() { std::cout << "Derived::Derived()\n"; }

        ~Derived() { std::cout << "Derived::~Derived()\n"; }
    };

    struct Myxx{
        int a{0};
        Myxx(int i = 0): a(i){std::cout << "Myxx()" << std::endl;}
        ~Myxx(){std::cout << "~Myxx()" << std::endl;}
    };

    struct D{
        void operator()(Myxx* p){
            std::cout << "~" << std::endl;
            delete p;
        }
    };

    void print(const char*, std::shared_ptr<Base>const&);
    void thr(std::shared_ptr<Base>);
    void xy(shared_ptr<MyObj>const&);
//    void xy(shared_ptr<MyObj>);
    std::shared_ptr<MyObj> xy();

    void test();
    void test(int);
}

#endif //WEB_PTR_H
