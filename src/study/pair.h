//
// Created by redredmaple on 2025/12/10.
//

#ifndef STUDY_PAIR_H
#define STUDY_PAIR_H
#include "inc.h"

namespace __pair{

    class Foo{
    public:
        Foo(tuple<int, float>){
            std::cout << "Foo::Foo(tuple)" << std::endl;
        }
        template<typename ...Args>
        Foo(Args... args){
            cout << "Foo::Foo(args...)" << std::endl;
        }
    };

    void test(){
        std::pair<int,int> p1(1,1);
        std::cout << p1.first << p1.second << std::endl;

        p1.first = 10;
        p1.second = 10;

        std::pair<int,int> p2(p1);
        std::cout << p2.first << p2.second << std::endl;

        using intPair = std::pair<int,int>;
        intPair p3 = std::make_pair(1,1);
        std::cout << get<0>(p3) << p3.second << std::endl;

        std::cout << std::tuple_size<intPair>::value << std::endl;
        using pt = std::tuple_element<0,intPair>::type;
        std::cout << typeid(pt).name() << std::endl;

        swap(p3, p2);
        std::cout << "after swap :" << std::endl;
        std::cout << get<0>(p3) << p3.second << std::endl;
//        std::cout << type(t).name() << std::endl;

        tuple<int,float> t(1,2.22);
        pair<int, Foo> p11(42, t);
        pair<int, Foo> p22(piecewise_construct, make_tuple(42), t);

        int i = 0;
        auto p = make_pair(std::ref(i), std::ref(i));
        ++p.first;
        ++p.second;

        std::cout << "I: " << i << std::endl;
    }

}

#endif //STUDY_PAIR_H
