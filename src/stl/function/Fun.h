//
// Created by xiaowei003 on 2024/10/31.
//

#ifndef UNTITLED_FUN_H
#define UNTITLED_FUN_H

#include <iostream>
#include <functional>

class Func {
public:
    void test();
    void operator()(int xx){
        std::cout << xx << std::endl;
    }
};

struct Person{
    std::string firstname;
    std::string lastname;
};

class PersonCriterion{
public:
    bool operator()(const Person& p1, const Person& p2){
        return p1.firstname == p2.firstname ||
                p1.firstname < p2.firstname;
    }
};

class IntSequence{
public:
    IntSequence(int val) : value(val){}
    int operator()(){
        return value++;
    }
private:
    int value;
};

class MeanValue{
private:
    long num;
    long sum;
public:
    MeanValue() : num(0),sum(0){}
    void operator()(int elem){
        ++num;
        sum += elem;
    }

    double value(){
        return static_cast<double>(sum)/ static_cast<double>(num);
    }
};

class Nth{
private:
    int nth;
    int count;
public:
    Nth(int n) : nth(n), count(0) {}
    bool operator()(int){
        return ++ count  == nth;
    }
};

int foo(int a, int b){
    return a + b;
}

char myToupper(char c){
    std::locale loc;
    return std::use_facet<std::ctype<char>>(loc).toupper(c);
}

int incr (int &i){
    ++i;
    return 0;
}

class Hor{
private:
    std::string name;
public:
    Hor(const std::string n): name(n){}
    void print()const{
        std::cout << name << std::endl;
    }
    void print2(const std::string prefix)const{
        std::cout << prefix << name << std::endl;
    }
};

#include <cmath>
template <typename T1, typename T2>
struct fopow{
    T1 operator()  (T1 base, T2 exp) const{
        return std::pow(base, exp);
    }
};

#endif //UNTITLED_FUN_H
