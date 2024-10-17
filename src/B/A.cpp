//
// Created by xiaowei003 on 2024/8/18.
//
namespace B {
#include "A.h"
    using namespace std;
    void test(void) noexcept {
        std::cout<<"namespace B test" << std::endl;

        Point p3(1,2);
        p3.printX();

        Point p1(7);
        p1.printX();

        Point p2;
        p2.printX();

        DCException a(1.2);
    }
}
