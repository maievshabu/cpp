//
// Created by xiaowei003 on 2024/8/18.
//

#ifndef CPP_A_H
#define CPP_A_H

using namespace std;

class A {
public:
    void pr1(){std::cout<<"public func" << std::endl;}
protected:
    void pr2(){std::cout<<"protected func" << std::endl;}
private:
    void pr3(){std::cout<<"private func" << std::endl;}
public:
    void pr(){
        pr1();
        pr2();
        pr3();
    }
};

class B : public A{
public:
    void pr()
    {
        pr1();
        pr2();
    }
};

class C : protected A{
public:
    void pr(){
        pr1();
        pr2();
    }
};

class D: private A{
public:
    void pr(){
        pr1();
        pr2();
//        throw std::runtime_error("123");
    }
};

#endif //CPP_A_H
