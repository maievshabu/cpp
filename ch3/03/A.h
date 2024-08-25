//
// Created by xiaowei003 on 2024/8/25.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H


class A {
public:
    A():d(new int(0)){std::cout<<"contructor"<<std::endl;}
//    A(const A& h):d(new int(*h.d)){std::cout<<"copy constructor" <<std::endl;}
//    A(A&& h):d(h.d){ h.d = nullptr; std::cout << "move constructor" << std::endl;}
    ~A(){delete d;}
    int *d;
};

#endif //UNTITLED_A_H
