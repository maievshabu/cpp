//
// Created by xiaowei003 on 2024/8/25.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H




class A {};

class B {
public:
    explicit operator A () const { std::cout << __func__ << std::endl; return A();}
};

void Func(A ct){std::cout<<__func__<<std::endl;}

#endif //UNTITLED_A_H
