//
// Created by xiaowei003 on 2024/9/12.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H
#include <functional>

namespace ch603{
    class A {
    private:
        std::function<void()> _callback;
    public:
        A(const std::function<void()> &f):_callback(f){}
        void notify(void){_callback();}
    };

    int test();
}


#endif //UNTITLED_A_H
