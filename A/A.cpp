//
// Created by xiaowei003 on 2024/8/18.
//

namespace A{
#include <string>
#include <iostream>
#include "A.h"
    void test(void) noexcept(false)
    {
        A a;
        B b;
        C c;
        D d;
        try {
            std::cout << "---------A------------" << std::endl;
            a.pr();
            std::cout << "---------A-----------" << std::endl;

            std::cout << "---------B-----------" << std::endl;
            b.pr();
            std::cout << "---------B-----------" << std::endl;

            std::cout << "---------C-----------" << std::endl;
            c.pr();
            std::cout << "---------C-----------" << std::endl;

            std::cout << "----------D----------" << std::endl;
            d.pr();
            std::cout << "----------D----------" << std::endl;
        }catch(std::exception& e){
            std::cout<<"error:"
            << e.what() <<
            std::endl;
        }catch (...){
            std::cout<<"eeror" <<std::endl;
        }

    }
};
