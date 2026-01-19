//
// Created by redredmaple on 2026/1/17.
//

#include "d119.h"
using namespace d119;
std::vector<int> arr={1,2,3,4,5};

void d119::output(int x){
    std::cout << x << " ";
}

void d119::output(int x, int y){
    std::cout << x << " " << y << std::endl;
}

void d119::output_add_2(int x) {
    std::cout << x + 2 << " ";
}

void d119::call_when_even(int x, const std::function<void(int)>& f){
    if (!(x & 1)){
        f(x);
    }
}

std::vector<int>& d119::get_range(void){
    std::cout << "get_range -> :" << std::endl;
    return arr;
}

void d119::test(){
    {
        /**
         * P61 1.7 tuple元组
         * tuple<const char*,int> tp = make_tuple(sendPack, nSendSize);
         * struct{
         * char* p;
         * int len;
         * };
         *
         * auto tp = return std::tie(1,"aa", 2); // tp 实际类型std::tuple(int&,string&,int&);
         * auto data = tp.get<0>();
         * int len = tp.get<1>();
         *
         * int x,y;
         * string a;
         * std::tie(x, a, y) = tp;
         * std::tie(std::ignore, std::ignore, y) = tp;
         *
         * std::map<int, std::string> m;
         * m.replace(std::forward_as_tuple(10, std::string("hello ));  //std::tuple(int&&, string&&>类型的tuple;
         *
         *
         * std::tuple<int, std::string,float> t1(10,"Test", 3.14);
         * int n = 9;
         * auto t2 = std::tuple_cat(t1, std::make_pair("FOO", "Bar", t1, std::tie(n));
         * n = 10;
         * print(t2);
         *
         */
    }

#ifdef MAIEVV
    {
        /**
         * P56 1.6 lambda表达式
         * [caputre](params) opt -> ret { body;}
         * auto f = [](int a) {return a + 1;};
         * auto x2 = [](){return {1,2};}; //error无法推断
         *
         * auto f = [](){return 1;};
         * auto f = []{return 1;}; //可以省略空参数表
         *
         * 捕获范围说明:
         * [] 不捕获任何变量
         * [&] 按引用捕获()
         * [=] 按值捕获(副本值)
         * [=,&foo]
         * [bar]
         * [this]
         *
         * class A{
         * public:
         *      int i_ = 0;
         *      void func(int x, int y){
         *          auto x1 = []{return i_;}//error
         *          auto x2 = [=] {return i_ + x + y;}; //ok
         *          auto x3 = [&] {return i_ + x + y;} //ok
         *          auto x4 = [this]{return i_;} //ok
         *          auto x5 = [this]{return i_ +x + y;} //error, no ,x, y
         *          auto x6 = [this, x, y] {return i_ + x + y;} //ok
         *          auto x7 = [this]{return i_++;} //ok
         *      }
         *}
         *
         * int a = 0;
         * auto f = [=]{ return a;}
         *
         * a += 1;
         * std::cout << f() << std::endl; //0
         *
         * int a = 0;
         * auto f1 = [=]{return a++;} //error
         * auto f2 = [=]mutable {return a++;} //ok mutable
         *
         * std::function<int(int)> f1 = [](int a){return a;};
         * std::function<int(int)> f2 = std::bind([](int a){return a;}, 123);
         * using func_t = int(*)(int);
         * func_t f = [](int a) {return a;};
         * f(123);
         *
         * typedef void(*Ptr)(int*);
         * Ptr p1 = [](int* p) {delete p;};
         * Ptr p2 = [&](int* p) {delete p;}; //error, 有状态的lambda不能直接转换为函数指针
         *
         */

        std::vector<int> v = {1,2,3,4,5,6};
        int even_count = 0;
//        for_each(v.begin(), v.end(),CountEven(even_count));
//        std::cout << "The number of even is : " << even_count << std::endl;

        std::for_each(v.begin(), v.end(), [&even_count](int val){
            if (!(val&1)){
                ++even_count;
            }
        });
        std::cout << "The number of even is : " << even_count << std::endl;

        using std::placeholders::_1;
        auto f = std::bind(std::logical_and<bool>(),
                           std::bind(std::greater<int>(),_1, 1),
                           std::bind(std::less_equal<int>(), _1, 3));
//        int count = std::count_if(v.begin(), v.end(), f);

        int count = std::count_if(v.begin(), v.end(), [](int x){
            return x >= 1 && x <= 3;
        });
    }
    {
        /**
         * P47 1.5 std::function,std::bind
         *
         * 可调用对象
         * 1)是一个函数指针
         * void func(void){}
         * 2)是一个具有operator()成员函数的类对象(仿函数)
         * struct Foo{
         *      void operator()(void){}
         * }
         * 3) 是一个可被转换为函数指针的类对象
         * struct Bar{
         *      using fr_t = void(*)(void);
         *      static void func(void){}
         *      operator fr_t(void){
         *          return func;
         *      }
         *     void (*operator()(void)(void){
         *          return func;
         *      }
         * }
         * 4)是一个类成员(函数)指针
         * struct A{
         *      int a_;
         *      void mem_func(void){}
         * }
         *
         * void(* func_ptr)(void) = & func; //函数指针
         * func_ptr();
         *
         * Foo foo; //仿函数
         * foo();
         *
         * Bar bar; //可转换为函数指针的类对象
         * bar();
         *
         * void(A::*mem_func)(void) = &A::mem_func; //类成员函数指针
         * int A::*mem_obj_ptr = &A::a_; //类成员指针
         *
         * A aa;
         * (aa.*mem_func_ptr)();
         * aa.*mem_obj_ptr = 123;
         *
         * void func(void)
         * {
         *      std::cout << __FUNCTION__ << std::endl;
         * }
         *
         * class Foo{
         * public:
         *      static int foo_func(int a){
         *          std::cout << __FUNCTION __ << "(" << a << ") -> :";
         *          return a;
         *      }
         * }
         *
         * class Bar{
         * public:
         *      int operator()(int a){
         *          std::cout << __FUNCTION __ << "(" << a << ") -> :";
         *          return a;
         *      }
         * }
         *
         * std::function<void(void)> fr1 =func; //绑定一个普通函数
         * fr1();
         *
         * std::function<int(int)> fr2 = Foo::foo_func;
         * fr2(2);
         *
         * Bar bar;
         * fr2 = bar;
         *
         */

        Foo foo;
        A aa(foo);
        aa.notify();
//        for(int i = 0; i<10;i++){
//            call_when_even(i, output);
//        }
//        std::cout << std::endl;

        {
            auto fr = std::bind<void(int)>(output, std::placeholders::_1);
            for(int i = 0; i< 10; i++){
                call_when_even(i, fr);
            }
            std::cout << std::endl;
        }

        {
            auto fr = std::bind(output_add_2, std::placeholders::_1);
            for(int i = 0; i < 10; i++){
                call_when_even(i, output_add_2);
            }
            std::cout << std::endl;
        }

        {
            std::bind<void(int,int)>(output, 1,2)(); // 1,2
            std::bind<void(int,int)>(output, std::placeholders::_2, 2)(1, 1); //1,2
        }

        {
            AA a;
            std::function<void(int,int)> fr = std::bind(&AA::output, a, std::placeholders::_2,2);
            fr(3,3);

            std::function<int&(void)> fr_i = std::bind(&AA::i_, &a);
            fr_i() = 123;
            std::cout << a.i_ << std::endl;
        }

    }

    {
        std::cout << "range(15):";
        for(int i: range(15)){
            std::cout << " " << i;
        }
        std::cout << std::endl;

        std::cout << "range(2,6):";
        for(auto i : range(2,6)){
            std::cout <<" " << i;
        }
        std::cout << std::endl;

        const int x = 2, y= 6, z =3;
        std::cout << "range(2,6,3):";
        for(auto i: range(x, y, z)){
            std::cout << " " << i;
        }
        std::cout << std::endl;

        std::cout <<"range(10.5, 15.5):";
        for( auto i : range(10.5, 15.5)){
            std::cout << " " << i;
        }
        std::cout << std::endl;

        std::cout << "range(35,27,-1):";
        for( int i : range(35,27,-1)){
            std::cout << " " << i;
        }
        std::cout << std::endl;

        std::cout << "range(2,8,0.5):";
        for(auto i : range(2,8,0.5)){
            std::cout << " " << i;
        }
        std::cout << std::endl;

        std::cout << "range(8,7, -0.1):";
        for(auto i : range(8,7,-0.1)){
            std::cout << " " << i;
        }
        std::cout << std::endl;

        std::cout << "range('a', 'z'):";
        for(auto i : range('a','z')){
            std::cout << " " << i;
        }
        std::cout << std::endl;

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
#endif

}