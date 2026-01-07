//
// Created by redredmaple on 2025/12/11.
//

#include "inc.h"

#ifndef STUDY_TUPLE_H
#define STUDY_TUPLE_H
namespace __tuple{
    std::tuple<int, int, int> foo(){
//        return {1,1,2}; //ok ?? 编译器不出错，书上说不可以这样写！！
        return make_tuple(1,1,2);
    }

    template<int IDX, int MAX, typename... Args>
    struct PRINT_TUPLE{
        static void print(std::ostream& strm, const std::tuple<Args...>& t){
            strm << std::get<IDX>(t) << (IDX + 1 == MAX ? "" : ",");
            PRINT_TUPLE<IDX+1,MAX, Args...>::print(strm, t);
        }
    };

    template<int MAX, typename... Args>
    struct PRINT_TUPLE<MAX,MAX,Args...>{
        static void print(std::ostream& strm, const std::tuple<Args...>&t){
        }
    };

    template<typename... Args>
    std::ostream& operator<<(std::ostream& strm, const std::tuple<Args...>& t){
        strm << "[";
        PRINT_TUPLE<0, sizeof...(Args), Args...>::print(strm, t);
        return strm << "]";
    }

    void test(){
        tuple<string, int,int, complex<double>> t;
        tuple<int,float,string> t1{4,6.3,"nico"};

        std::cout << get<0>(t1) << " ";
        std::cout << get<1>(t1) << " ";
        std::cout << get<2>(t1) << " ";
        std::cout << std::endl;

        float ab = 1.123;

        auto t2 = make_tuple(4, 1.111, "hello");
        std::cout << get<0>(t2) << " ";
        std::cout << get<1>(t2) << " ";
        std::cout << get<2>(t2) << " ";
        std::cout << std::endl;

        get<1>(t2) = ab;

        std::tie(std::ignore, ab, std::ignore) = t2;

        if (t1 < t2){
            std::cout << "t1 < t2" << std::endl;
        }else if (t1 == t2){
            std::cout << "t1 = t2" << std::endl;
        }else{
            std::cout << "t1 > t2" << std::endl;
        }

        std::cout << ab << std::endl;

//        std::vector<std::tuple<int,float>> v{{1,1.0}, {2.2,0}}; //书上说不可以，编译器可以这样写???
        std::vector<std::tuple<int,float>> v{ std::make_tuple(1,1.0), {2.2,0}}; //书上说不可以，编译器可以这样写???
        auto tt = v.at(1);
        std::cout << get<0>(tt) << " ";
        std::cout << get<1>(tt) << " ";
        std::cout << std::endl;

        auto tt1 = foo();
        std::cout << get<0>(tt1) << " ";
        std::cout << get<1>(tt1) << " ";
        std::cout << get<2>(tt1) << " ";
        std::cout << std::endl;

        typedef std::tuple<int,float,string> TupleType;

        std::cout << std::tuple_size<TupleType>::value << std::endl;
        using ty1 = std::tuple_element<2, TupleType>::type;
        ty1 ss("hello world");
        std::cout << ss << std::endl;

        int n;
        auto ttz = std::tuple_cat(std::make_tuple(42, "hello"), std::tie(n));
        get<2>(ttz) = 10;

        std::cout << ttz << std::endl;
    }

}

#endif //STUDY_TUPLE_H
