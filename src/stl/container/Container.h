//
// Created by xiaowei003 on 2024/11/1.
//

#ifndef UNTITLED_CONTAINER_H
#define UNTITLED_CONTAINER_H


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

#endif //UNTITLED_CONTAINER_H
