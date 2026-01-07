//
// Created by redredmaple on 2025/12/12.
//

#include "inc.h"

#ifndef STUDY_TRAIT_H
#define STUDY_TRAIT_H
namespace __trait{
    template<typename T>
    void foox(const T& val){
        if (std::is_pointer<T>::value){
            std::cout << "foo() called for a pointer" << std::endl;
        }else{
            std::cout << "foo() called for a value" << std::endl;
        }
    }

    template<typename T>
    void foo_impl(const T& val, std::true_type){
        std::cout << "foo() called for a pointer: " << *val << std::endl;
    }

    template<typename T>
    void foo_impl(const T& val, std::false_type){
        std::cout << "foo() called for value: "<< val << std::endl;
    }

    template<typename T>
    void foo(const T& val){
        foo_impl(val, std::is_pointer<T>());
    }

//    template<typename T>
//    void foo<T*>(const T& val){
//       foo_impl(val,std::true_type);
//    }

    template<typename T1, typename T2>
    struct common_typex {
        using type = decltype(true ? std::declval<T1>() : std::declval<T2>());
    };

    template<typename T1, typename T2>
    typename common_typex<T1, T2>::type min(const T1& t1, const T2& t2){
        return  t1 > t2 ? t2 : t1;
    }

    template<size_t XX>
    struct Cz{};

    typedef int C1;

    template<C1 s>
    struct xyz{};

    void func(int x, int y){
        std::cout << "func(int,int)" << std::endl;
    }

    class C{
    public:
        C(){
            std::cout << "C() called" << std::endl;
        }
        ~C(){
            std::cout << "~C() called" << std::endl;
        }
        void memfunc(int* x, int* y)const{
            std::cout << "memfunc(int*,int*)const" << std::endl;
        }
    };


    void test()
    {
        {
            std::vector<std::function<void(int,int)>> tasks;

            tasks.push_back(func);
            tasks.push_back([](int, int){
                std::cout << "[](int,int)" << std::endl;
            });

            for (auto & f :  tasks){
                f(1,1);
            }

            std::function<void(const C&, int*, int*)> mf;
            mf = &C::memfunc;
            int ma= 42;
            int mb = 77;
            mf(C(), &ma, &mb);
//            C c;
//            mf(c, &ma, &mb);

            int a = 10;
            int *pa = &a;

            foox(a);
            foox(pa);

            foo(a);
            foo(pa);

            using ta = common_typex<int, double>::type;
            auto xa = min(1, 1.111);

            std::cout << "ma:" << ma << std::endl;
            std::cout << "mb:" << mb << std::endl;
            swap(ma, mb);
            std::cout << "ma:" << ma << std::endl;
            std::cout << "mb:" << mb << std::endl;

            int ar1[] = {1,1,1};
            int ar2[] = {2,2,2};

            std::cout << ar1[0] << std::endl;
            std::cout << ar2[0] << std::endl;
            swap(ar1, ar2);
            std::cout << ar1[0] << std::endl;
            std::cout << ar2[0] << std::endl;

//            foo_impl(a, std::is_pointer<int>::value);
//            foo_impl(pa, std::is_pointer<int*>::value);
        }

        {
            vector<int> vc1{1,2,3,4};
            vector<int> vc2{1,2,3,4};

            stack<vector<int>> s1;
            s1.push(vc1);
            s1.push(vc2);

            std::cout << s1.size() << std::endl;

            auto p1 = s1.top();
        }

    }

}

#endif //STUDY_TRAIT_H
