//
// Created by redredmaple on 2026/1/17.
//

#include "d117.h"
using namespace d117;


void d117::test(){
    {
        /**
         * P34
         * 1.4 基于范围的for循环
         * std::vector<int> arr={1,2,3}
         *
         * for(auto it=
         *
         * void do_count(int n){
         *      std::cout << n << std::endl;
         * }
         * std::for_each(it.begin(),it.end(),do_count);
         *
         * for(auto n : arr){
         *      std::cout << n << std::endl;
         * }
         *
         * std::map<std::string, int> mm= {
         *      {"1",1},{"2",2,},{"3",3}
         * }
         * for(auto& val: mm){
         *      std::cout << val.first << "->" << val.second << std::endl;
         * }
         *
         * std::set<int> ss{1,2,3};
         * for(auto& val: ss){
         *      std::cout << val ++ << std::endl; //error, val is const int&
         * }
         *
         */
    }

#ifdef MAIEVV
    {
        /**
         *
         * p22 1.3列表初始化
         *
         * int i_arr[3] = {1,2,3};
         * struct A{
         *      int x;
         *      struct B{
         *          int i;
         *          int j;
         *      };b
         * }a={1,{2,3}}; //POD类型
         *
         * //拷贝初始化
         *
         * int i = 0;
         * class Foo{
         * public:
         *  Foo(int){}
         * } foo= 123; //需要拷贝构造函数
         *
         * //直接初始化
         * int j(0);
         * Foo bar(123);
         *
         *
         * class Foo{
         * public:
         *      Foo(int){}
         * private:
         *      Foo(const Foo&);
         * }
         *
         * Foo a1(123);
         * Foo a2 = 123;//error Foo::Foo(const Foo&) is private
         * Foo a3{123};
         * Foo a4 = {1,2,3};
         * int a5={3};
         * int a6{3};
         *
         * int*a = new int{123};
         * double b = double{12.12};
         * int* arr= new int[3]{1,2,3};
         *
         * struct Foo{
         *      Foo(int,double){}
         * };
         * Foo func(){
         *      return {123, 123.00};
         * }
         * struct A{
         *  int x;
         *  int y;
         * } a= {123,123}; //a.x=123,a.y=123;
         * struct B{
         *  int x;
         *  int y;
         *  B(int,int):x(0),y(0){}
         * }a={123,123};//a.x=0,b.x=0;
         * 聚合体类型:
         * 1)类型是一个普通数组(int[10], char[],long[2][3]
         * 2)类型是一个类(class, struct ,union)且
         *  a)无用户自定义的构造函数
         *  b)无私有private/protected的非静态数据类型
         *  c)无基类
         *  d)无虚函数
         *  e)不能有{}和=直接吃哈哈的非静态数据成员
         *
         *  struct ST{
         *  int x;
         *  double y;
         *  protected:
         *  int z;
         *  };
         *
         *  St s={1,2.5,1}; //error
         *  struct Foo{
         *  int x;
         *  double y;
         *  protected:
         *  static int z;
         *  };
         *
         *  struct ST{
         *  int x;
         *  double y;
         *  virtual void f();
         *  };
         *  ST s{1,2.5}//error
         *
         *  struct Base{};
         *  struct Foo : public Base{
         *      int x;
         *      double y;
         *  };
         *
         *  Foo foo{1,2.5};//error
         *
         *  Foo foo{1,2.5};
         *
         *  struct ST{
         *  int x;
         *  double y= 0.0;
         *  };
         *  ST s{1,2.5}; //error
         *
         * struct ST{
         * int x;
         * double y;
         * private:
         * int z;
         * };
         * ST s{1,2.5,1} //error
         *
         * struct Foo{
         *  ST st;
         *  int x;
         *  double y;
         * };
         *
         * Foo foo{{},1.2.5}; //ok....
         *
         * 对于聚合类型，使用初始化列表相当于对其中的每一个元素分别赋值;
         * 而对于非集合类型,则需要先自定义一个合适的构造函数，此时使用初始化列表将调用它对应的构造函数
         *
         * int arr[] {1,2,3};
         * std::map<std::string, int> mm={
         *  {"1",1},{"2", 2},{"3",3}
         * };
         * std::set<int> ss={1,2,3};
         * std::vector<int> arr={1,2,3,4,5};
         *
         * class Foo{
         *  public:
         *  Foo(std::initializer_list<int>{}
         * };
         *
         * Foo foo={1,2,3,4,5}; //ok
         *
         * class FooVector{
         *      std::vector<int> content_;
         * public:
         *      FooVector(std::initializer_list<int>list){
         *          for(auto it =list.begin(); it!=list.end(); it++){
         *              content_.push_back(*it);
         *          }
         *      }
         * }
         * FooVector foo_1={1,2,3,4,5};
         *
         * class FooMap{
         *      std::map<int,int>content_;
         *      using pair_t = std::map<int,int>::value_type;
         * public:
         *        FooMap(std::initializer_list<pair_t>list{
         *          for(auto it =list.begin(); it!=list.end(); it++){
         *              content_.push_back(*it);
         *          }
         *        }
         * }
         *
         * FooMap foo_2={{1,2},{3,6},{4,5}};
         *
         *
         * void func(std::initlializer_list<int>l){
         *      for(auto it = l.begin(); it != l.end(); it++){
         *          std::cout << *i << std::endl;
         *      }
         * }
         *
         * func({});
         * func({1,2,3});
         *
         * size(),begin(),end();
         * std::initializer_list<int> list={1,2,3};
         * size_t n = list.size(); // n== 3;
         *
         * 只能初始化或赋值
         *
         * int a = 1.1; //ok
         * int b = {1.1}; //error
         *
         * float fa=1e40; //ok
         * float fb={1e40}; //error
         *
         * float fc = (unsigned long long) -1; //ok
         * float fd = {(unsigned long long)-1}; //error
         * float fe = (unsigned long long )1; //ok
         * float ff = {(unsigned long long)1}; //ok
         *
         * const int x = 1024, y=1;
         * char c = x; //ok
         * char d = {x}; //error
         * char e = y; //ok
         * char f = {y}; //error
         *
         * 在上面的各种隐式类型转换重，只要遇到了类型收窄的情况,初始化列表就不会允许这种转换发生。
         */
    }
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
         *  void func(typename identity<T>::type val, T = 0){}
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