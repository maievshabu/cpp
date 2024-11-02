//
// Created by xiaowei003 on 2024/11/1.
//

#ifndef UNTITLED_CONTAINER_H
#define UNTITLED_CONTAINER_H
#include <iostream>
#include <chrono>
using namespace std;

class Container {

};

template <typename T, T val>
struct Integeral_constant{
    static constexpr T value = val;
    typedef T value_type;
    typedef Integeral_constant<T, val> type;
    constexpr operator value_type(){
        return value;
    }

    typedef Integeral_constant<bool, true> TRUE_TYPE;
    typedef Integeral_constant<bool, false> FALSE_TYPE;
};

class X{
public:
    int _x;
    X(int x):_x(x){}
    bool operator==(const X& other) const{
        return other._x == _x;
    }

    bool operator<(const X& other) const{
        return _x < other._x;
    }
};

template <typename V, typename R>
std::ostream& operator<<(ostream& s, const std::chrono::duration<V,R>& d){
    s << "[" << d.count() << " of " << R::num << "/" << R::den << "]";
    return s;
}


#endif //UNTITLED_CONTAINER_H
