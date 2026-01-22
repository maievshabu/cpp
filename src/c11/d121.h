//
// Created by redredmaple on 2026/1/21.
//

#ifndef C11_D121_H
#define C11_D121_H

#include "common.h"

namespace d121 {
    void test();
    struct B;
    struct A;

    struct A : public enable_shared_from_this<A>{
        std::shared_ptr<B> bptr;
        shared_ptr<A>GetSelf(){
//            return this;
            return shared_from_this();
        }

        A(){
            cout << "A()" << endl;
        }
        ~A(){
            cout << "~A()" << endl;
        }
    };

    struct B{
        B(){
            cout << "B()" << endl;
        }
        std::weak_ptr<A> aptr;
//        std::shared_ptr<A> aptr;
        ~B(){cout << "~B()" << endl;}
    };

    struct MyDeleter{
        void operator()(int*p){
            cout << "delete" << endl;
            delete p;
        }
    };

};

#endif //C11_D121_H
