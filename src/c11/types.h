//
// Created by redredmaple on 2026/1/17.
//

#ifndef C11_TYPES_H
#define C11_TYPES_H

#include "common.h"

template<typename T, typename U = int, U N = 0>
struct Foo{
    //#...
};

template<typename T = int>
T Func(T z){}

/**
 * 这是个转换运算符 operator 类型名
 * 这里有个通用写法
 * operator<type>()const{
 *      return ...;
 * }
 * operator type(); 转换成typ类型
 */

template<typename Type>
struct GetLeftSize{
    static const int value = 1;
};

template<typename Type>
struct GetLeftSizex{
    enum {value = 1};
};

template<typename Type>
struct GetLeftSize1 : std::integral_constant<int, 1>{};

namespace maiev{
    namespace{
        template<class T, T v>
        struct integral_constant{
            static const T value = v;
            typedef T value_type;
            typedef integral_constant<T,v> type;
            operator value_type(){ return value;}
        };

        typedef integral_constant<bool, true> true_type;
        typedef integral_constant<bool, false> false_type;

        template<class T>
        struct is_integral : false_type{};

        template<>
        struct is_integral<char> : true_type{};

        template<>
        struct is_integral<bool> : true_type{};

        template<>
        struct is_integral<char16_t> : true_type{};

        template<>
        struct is_integral<char32_t> : true_type{};

        template<>
        struct is_integral<wchar_t> : true_type{};

        template<>
        struct is_integral<short> : true_type{};

        template<>
        struct is_integral<int> : true_type{};

        template<>
        struct is_integral<long> : true_type{};

        template<>
        struct is_integral<long long> : true_type{};

        template<class T>
        struct is_float_point : false_type {};

        template<>
        struct is_float_point<float> :true_type {};

        template<>
        struct is_float_point<double> :true_type {};

        template<class T>
        struct is_void : false_type{};

        template<>
        struct is_void<void> : true_type {};

        template<class T>
        struct is_array : false_type{};

        template<typename T>
        struct is_array<T[]> : true_type{};
    }
}

#endif //C11_TYPES_H
