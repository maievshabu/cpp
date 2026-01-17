//
// Created by redredmaple on 2026/1/17.
//

#include "d117.h"
using namespace d117;


void d117::test(){
    {

        /**
         * 函数模板的默认模板参数
         * 在使用规则上和其他的默认参数也有一些不同，它没有必须写在参数表最后的限制
         *
         *  template<typename T = int, typename U>
         *  T Funcx(U val){
         *       return val;
         *  }
         *  template<typename T>
         *  struct identity{
         *      typedef T type;
         *  }
         *
         *  template<typename T = int>
         *  void func(typename identity<T>::type val, T = 0{}
         *  func(123) // T -> int;
         *  func(123,123.0)//T->double;
         *
         */
    }
    {
        /**
         * 模板的别名
         * typede unsigned int uint_t;
         * void func(unsigned int);
         * void func(uint_t);
         *
         *
         * typedef unsigned int uint_t;
         * using uint_t_1 = unsigned int;
         * typedef int int32;
         *
         * void func(unsigned int){}
         * void func(uint_t_1){}
         * typedef std::map<std::string, int> map_int_t;
         * using map_int_t1 = std::map<std::string, int>;
         * typedef std::map<std::string, std::string> map_str_t;

         * template<typename Val>
         * struct str_map{
         *   typedef std::map<std::string, Val> type;
         *  };
         * str_map<int>::type map1;
         * template<typename Val>
         * using str_map_t = std::map<std::string, Val>;
         * str_map_t<int> map2;
         * typedef void(*func_t)(int,int);
         * using func_tx = void(*)(int ,int);
         *
         * template<typename T>
         * struct func_t1{
         *      typedef void(*type)(T, T);
         * };
         *
         * //使用func_t1模板
         * func_t1<int>::type xx_1;
         * template<typename T>
         * using func_t2 = void(*)(T, T);
         * func_t2<int> xx2;
         *
         * using,typedef一样，并不会创造新的类型
         * using === typedef
         */
    }
#ifdef MAIEVV
    {
//        auto x = add<decltype(1+1.0)>( 1, 1.0);
        auto x = add( 1, 1.0);
        auto y = add2(1, 2.1);
        std::cout << x << std::endl;
        std::cout << y << std::endl;

        /**
         * decltype 关键字
         * decltype(exp)
         *
         * int x = 0;
         * decltype(x) y = 1; //int
         * decltype(x+y) z = 0; //int
         *
         * const int& i = x;
         * decltype(i) j = y; //const int&
         *
         * const decltype(z) * p = &z; //const int*
         * decltype(z) * pi = &z; //int*
         * decltype(pi) ** pp = &pi; //int **
         *
         */

        /**
         * decltype 推导规则:
         *
         * 1) exp 是标识符，类访问表达式，decltype(exp) 和exp 类型一致
         * 2) exp 是函数调用,decltype(exp) 和返回值类型一致
         * 3) 若exp是一个左值,则decltype(exp)是exp类型的左值引用，否则和exp类型一致
         *
         *
         * (1): 标识符和类访问表达式
         * class Foo{
         * public:
         *      static const int Number = 0;
         *      int x;
         * }
         *
         * int n = 0;
         * volatile const int & x = n;
         *
         * decltype(n) a = n; //int
         * decltype(x) b = n; //const volatile int &
         *
         * decltype(Foo::Number) c = 0 // const int;
         *
         * Foo foo;
         * decltype(foo.x) d = 0; //int 类访问表达式
         *
         * (2)函数调用
         *
         * int& func_int_r(void); //左值(lvalue,可简单理解为可寻址值)
         * int&& func_int_rr(void); //x值(xvalue, 右值本身是一个xvalue
         * int func_int(void); //纯右值(prvalue)
         *
         * const int& func_cint_r(void); //左值
         * const int&& func_cint_rr(void); //x值
         * const int func_cint(void); //右值
         *
         * const Foo func_cfoo(void); //纯右值
         *
         * int x = 0;
         * decltype(func_int_r(x)) a1 = x; // a1 -> int&
         * decltype(func_int_rr(x)) a1 = x; //a1 -> int &&
         * decltype(func_int(x)) a1 = x; //a1 -> int
         *
         * decltype(func_cint_r(x)) a1 = x; //a1 -> const int&
         * decltype(func_cint_rr(x)) a1 = x; //a1 -> const int&&
         * decltype(func_cint(x)) a1 = x; //a1 -> int ??? 返回的是纯右值(只有类类型可以携带cv限定符，此外则一般忽略掉cv限定)
         *
         * decltype(func_cfoo()) a1 = x; //a1 -> const Foo;
         *
         * (3) 带括号的表达式和加法运算表达式
         *
         * struct Foo{int x;}
         * const Foo foo = Foo();
         *
         * delctype(foo.x) a = 0; //a -> int
         * decltype((foo.x)) b = a; // a -> const int & ??
         *
         * int n =0, m=0;
         * decltype( n+m) c = 0; // c -> int
         * decltype((n+ m)) d = c; //d -> int &
         *
         * typedef const std::vector<int> container_t;
         * conatiner_t arr;
         *
         * Foo<container_t> foo;
         * foo.func(arr);
         *
         * typedef decltype(nullptr) nullptr_t;
         * typedef decltype(sizeof(0)) size_t;
         *
         */
    }

    {
        int x = 0;
        auto * a = &x; //int *
        auto b = &x; //int*
        auto &c = x; //int &
        auto d = c; //int

        const auto e = x; //const int
        auto f = e; //int
        const auto& g = x; //const int&
        auto &h = g; //const int&

        /**
         * auto推导规则:
         * 1)当不声明为指针或引用时，auto的推导结果和初始化表达式抛弃引用和cv限定后类型一致
         * 2)当申明为指针或引用时, auto的推导结果将保持初始化表达式的cv属性
         */

        /**
         * auto的限制
         *
         * void func(auto a = 1) {} //error
         *
         * struct Foo
         * {
         *      auto var1_ = 0;  //error 不能用于非静态成员变量
         *      static const auto var2_ = 0; //ok
         *  }
         *
         * template<typename T>
         * struct Bar{}
         *
         * int arr[10] = {0}
         * auto aa = arr; //ok aa -> int*;
         * auto rr[10] = arr; //error..
         *
         * Bar<int> bar;
         * Bar<auto> bb = bar; //error
         *
         *
         */


        /**
         *  什么时候用auto
         *
         * #icluce <map>
         *
         * std::map<double,double>resultMap;
         *
         * std::map<double, double>::iterator it = resultMap.begin();
         * for(;it != resultMap.end();it++)
         * {
         *      // do something..
         * }
         *
         * for (auto it = resultMap.begin(); it != resultMap.end(); it++){
         *      //do something..
         * }
         *
         *
         */

        class Foo{
        public :
            static int get(void){
                return 0;
            }
        };

        class Bar{
        public:
            static const char* get(void){
                return "0";
            }
        };

       func<Foo>();
       func<Bar>();
    }

#endif
}