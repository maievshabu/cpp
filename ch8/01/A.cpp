//
// Created by xiaowei003 on 2024/9/28.
//

#include "A.h"
#include <iostream>
#include <functional>
#include <sstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <functional>
#include <memory>

using namespace std;

namespace ch801{

    void maiev_const()
    {
        std::string cx1 = "hi";
        std::string cx2 = "hi";

        std::string const c1 = "c1";
        const std::string c2 = "c2";

        cx1 = "HI";  //ok
//        c1 = "HI"; //error
//        c2 = "HI"; //error

        std::string const & c3 = c1;
//        std::string & const c32 = cx1; //这是一种错误的写法
        std::string &cx3 = cx1; //
//        c3[0] = "H"; //error c3 is const
        cx3[0] = 'H'; //ok
        cx3 = "H"; //ok

        std::string const * c41 = &c1; //常量指针, 指针可以改，指向不可改
        c41 = &c2; //ok
        c41 = &cx1; //ok ? 非const -> const;
//        *c41 = "qqqqq"; //error

        std::string * const c42 = &cx1; // 指针是不可改
        cout << *c42 << endl;
//        c42 = &c2; //error
        *c42 = "HH";
        cout << *c42 << endl;
    }

    static void maiev_print()
    {
        string name("maiev");
        int i = 10;
        int *pi = &i;
        int &ri = i;

//        printV("hello"); // hello
//        printV(name); //maiev
//        printV(i); //i
//        printV(pi); //pi
//        printV(ri); //i
//
//        printV(std::move("hello")); //hello
//        printV(std::move(name)); //maiev
//        printV(std::move(i)); //10
//        printV(std::move(pi)); //pi
//        printV(std::move(ri)); //i
//        printV(returnString());
//        printV("hi");
//        int arr[4]={1,2,3};
//        printV(arr);
//
//        //reference [no tmp, no move]
//        outR(name);
//        outR("hi");
//        outR(ri);
//        outR(returnConstantString());
//        std::string const c ="HI";
//        outR(std::move(c)); //error

//        passR(name);
//        passR(i);
//        passR(pi);
//        passR(ri);
//        passR(move(name));

        std::string s = "Hello";
        printStr(s);
        printStr(std::cref(s));
    }

    void test_trait()
    {
        cout << "is const" <<endl;
        cout << "int:" << is_const<int>::value <<endl;
        cout << "const int:" << is_const<const int>::value <<endl;
        cout << "const int&:" << is_const<const int&>::value <<endl;
        cout << "const int*:" << is_const<const int*>::value <<endl;
        cout << "int* const:" << is_const<int * const>::value <<endl;

        cout << "is same :" << is_same<int, int*>::value<<endl;
        cout << "is same :" << is_same<int*, int*>::value<<endl;

        cout << "is same :" << is_same<int*, int&>::value<<endl;
        cout << "is base of :" << is_base_of<unsigned , int>::value <<endl;
        cout << "is convertible of :" << is_convertible<unsigned , int>::value <<endl;

        struct A{};
        struct B: A {};
        struct C: B {};
        struct D;

        cout << "is base of:" << is_base_of<A, B>::value<<endl;
        cout << "is base of:" << is_base_of<A, C>::value<<endl;
        cout << "is base of:" << is_base_of<D, A>::value<<endl;

        typedef std::conditional<(sizeof(long long) > sizeof(long double)), long long ,long double>::type max_size_t;
        cout << typeid(max_size_t).name() << endl;
    }

    template<typename T, typename U>
    decltype((*(T*)0) ((*(U*)0))) Func(T t, U u){
        return t(u);
    }

    //the same as before!
    template<typename T, typename U>
    auto Func(T t, U u)->decltype(t(u)){
        return t(u);
    }

#include <type_traits>
    class AA
    {
        AA() = delete;

    public:
        int operator()(int i)
        {
            return i;
        }
    };

    int fn(int) {return int();}
    typedef int(&fn_ref)(int);
    typedef int(*fn_ptr)(int);
    struct fn_class{
        int operator()(int i ) {
            return i;
        }
    };

    template<class T>
    typename std::enable_if<std::is_arithmetic<T>::value ,T>::type foo(T t)
    {
        return t;
    }

    template<typename T>
    string toString(T t)
    {
        if (typeid(T) == typeid(int) ||
                typeid(T) == typeid(float) ||
                typeid(T) == typeid(double)){
            std::stringstream ss;
            ss << t;
            return ss.str();
        }else if (typeid(T) == typeid(string)){
            return t;
        }
    }

    template<typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, string>::type toString(T& t)
    {
       return std::to_string(t);
    }

    template<typename T>
    typename std::enable_if<!std::is_same<T, string>::value, string>::type toString(T& t)
    {
        return t;
    }

    template<class ...T>
    void f(T... args){
        cout << sizeof...(args) << endl;
    }

    template<class T>
    void printarg(T t)
    {
        cout << t << endl;
    }

    template<class ...T>
    void expand(T... args)
    {
//        int arr[] = {(printarg(args), 0)...};
//        std::initializer_list<int>{(printarg(args), 0)...};
        std::initializer_list<int>{([&](){cout << args + 1 <<endl;}(), 0)...};
    }

//    template<typename First, typename ...Rest>
//    struct Sum
//    {
//            enum {value = Sum<First>::value + Sum<Rest<Rest...>::value};
//    };
//
//    template<typename Last>
//    struct Sum
//    {
//        enum = {value = sizeof(Last)};
//    };

    template<int...>
    struct IndexSeq{};

    template <int N, int ...Indexes>
    struct MakeIndexes: MakeIndexes<N-1, N-1, Indexes...>{};

    //模板特化
    template<int... Indexes>
    struct MakeIndexes<0, Indexes...>
    {
        typedef IndexSeq<Indexes...> type;
    };

    void test_index()
    {
        using T = MakeIndexes<3>::type;
        cout << typeid(T).name() << endl;
    }

//    void test_xy()
//    {
//        auto t = create_task([]()->int{
//            return 0;
//        });
//
//        auto increment = [](int n) {return n + 1;};
//
//        int result = t.then(increment).then().then(increment).get();
//        cout << result << endl;
//    }

    void test_result()
    {
        expand("1", "2", 3, 4,1.1);
        A a1;
        auto f1 = foo(1);
        auto f2 = foo('2');
//        auto f3 = foo(a1);

        fn_ref ff = fn;
        cout << ff(10) << endl;

        decltype(fn)& f11 = fn;

        cout << *(fn_ptr(1)) <<endl;
        cout << fn_ptr(1) <<endl;

        decltype(std::declval<AA>() (std::declval<int>())) i = 4;
        cout << typeid(i).name() << endl;

        std::result_of<AA(int)>::type ii = 4;
        cout << typeid(ii).name() << endl;

        typedef std::result_of<decltype(fn)& (int)>::type A1;
        typedef std::result_of<decltype(&fn) (int)>::type A2;
        typedef std::result_of<fn_ref(int)>::type B;
        typedef std::result_of<fn_ptr(int)>::type C;
        typedef std::result_of<fn_class(int)>::type D;

        A1 r1 = fn(10);
        A2 r2 = fn(1);

        cout << is_same<A1, A2>::value <<endl;
        cout << is_same<A1, int>::value <<endl;
        cout << is_same<int, A2>::value <<endl;
        cout << is_same<A1, B>::value <<endl;
        cout << is_same<A1, C>::value <<endl;
        cout << is_same<A1, D>::value <<endl;

    }

    std::mutex mx;
    void func1(int a)
    {
        std::lock_guard<std::mutex> locker(mx);
        cout << __FUNCTION__ << " :a" << a << endl;
        cout << "enter thread:" << std::this_thread::get_id() << endl;
    }

    void func2(int a)
    {
        mx.lock();
        cout << __FUNCTION__ << " :a" << a << endl;
        cout << "enter thread:" << std::this_thread::get_id() << endl;
        mx.unlock();
    }

    void test_thread()
    {
        std::thread t2(func2, 11);
        std::thread t1(func2, 22);

//        cout <<"t1 pid:" << t1.get_id() << endl;
//        cout <<"t2 pid:" << t2.get_id() << endl;

        t1.join();
        t2.join();
    }

    template <std::intmax_t Num, std::intmax_t Demon = 1>
    class Ratio;

    template <class Rep, class Period = Ratio<1,1> >
    class Duration;

    void test_chrono()
    {
        std::chrono::minutes t1(10);

        std::chrono::duration<double, std::ratio<9,7> > d1(3);
        std::chrono::duration<double, std::ratio<6,5> > d2(1);

        auto d3 = d1 -d2;
        cout << typeid(d3).name() << endl;
        cout << "cout :" << d3.count() << endl;
        cout << chrono::duration_cast<chrono::seconds>(d3).count() << ": seconds" <<endl;
        cout << chrono::duration_cast<chrono::minutes>(d3).count() << ": minutes" <<endl;
        cout << chrono::duration_cast<chrono::hours>(d3).count() << ": hours" <<endl;

//        typedef duration <Rep, Ratio<3600,1> > hours;
//        typedef Duration <Rep, Ratio<60,1> > minutes;
//        typedef Duration <Rep, Ratio<1,1> > seconds;
    }

    void test_r()
    {
        string php = R"(
<?php
$a=1;$b =2;
function aa()
{
    return $a + $b;
}
aa();
exit;
)";
        cout << php << endl;
    }

    //虚函数才有final, override
    struct A1{
        void fuxx() {}
        virtual void func() final{
            cout << " " << endl;
        }

        virtual void func1();
//        void func1 final; //error
    };

    struct B final : A1{
        void func1() override {
            cout<< "override" << endl;
        }
    };

//    struct C : B{}; //error

    void test_final()
    {
//        A1 a;
//        a.fuxx();
        B b;
        b.func1();
    }

    struct MyStruct{
        char a; //1
        int b; //4
        short c; //2
        long long d; //8
        char e; //1
    };

    void test_map()
    {
//        std::map<char,int> mymap;
//        mymap.emplace('x', 12);
//        mymap.emplace_hint(mymap.cend(), 'y', 12);
//
//        for (auto& x: mymap)
//            std::cout << " [" << x.first << ':' << x.second << ']';
//        std::cout << '\n';

        std::unordered_map<std::string, std::string> mymap;
        mymap.emplace("aa", "11");
        mymap.emplace("bb", "22");
        mymap.emplace("cc", "33");
        mymap.emplace("dd", "44");

        std::cout << "my containers:";
        for(auto it = mymap.begin(); it != mymap.end(); ++it){
            std::cout << " " << it->first << ":" << it->second;
        }
        std::cout << std::endl;

        unsigned len = mymap.bucket_count();
        for(unsigned i = 0; i <len; i++){
            std::cout << "bucket #" << i << " contains:";
            for(auto it = mymap.begin(i); it != mymap.end(i); ++it){
                std::cout << " " << it->first << ":" << it->second;
            }
            std::cout << std::endl;
        }
    }

    void test_pair()
    {
        std::pair<char, int> mypair{'q', 12};
        std::pair<char, int> mypair1 = make_pair('X', 1);
        cout << ">=: " << ( mypair > mypair1) << endl;
        cout << "==: " << ( mypair == mypair1) << endl;
        swap(mypair, mypair1);
        mypair.swap(mypair1);
        cout << mypair.first << ":" << mypair.second << endl;
        cout << get<0>(mypair1) << ": " << get<1>(mypair1) << endl;

        cout << std::tuple_size<std::pair<char, int>>::value << endl;
    }

    void test_align()
    {
        cout << sizeof(MyStruct) << endl;
        cout << sizeof(A) << endl;
    }

    void test_vector()
    {
        std::vector<int> ar(11, 1);
    }

    class QU{
    public:
        explicit QU();
    };

    struct piece_construct_tt {};

// 自定义构造函数
    template<typename T1, typename T2>
    class MyPair : public std::pair<T1, T2> {
    public:
        MyPair(piece_construct_tt, const T1& t1, const T2& t2)
                : std::pair<T1, T2>(t1, t2) { // 直接使用 std::pair 的构造函数
            // 可以在这里添加额外的逻辑
        }
    };

    void test_tuple()
    {
        auto tp = []() -> std::tuple<int, float>{
            return {1,1.1f};
        }();
        cout << get<1>(tp) << endl;

        std::vector<std::tuple<int,float>> v1 { {1,1.1}};
        cout << typeid(tuple_element<1, std::tuple<int, float> >::type).name() << endl;

        piece_construct_tt pc;
        MyPair<int, double> myPair(pc, 1, 1.1f);

        //        ff(std::make_pair<42, "memory">);
//        gg(std::make_pair<42, "memory">);

//        ff({42,"memory"});
//        gg({42,"memory"});
        tuple<int,float> t(1, 22.11);
        pair<int, Foo> p1( 42, t);
        pair<int ,Foo> p2(piecewise_construct, make_tuple(42), t);

        int a1;
        float a2;

        typedef std::tuple<int,float> tif;

        cout << "size of tuple<int,float>: " << tuple_size<tif>::value << endl;
        cout << "type of tuple<int,float>: " << typeid(tuple_element< 1, tif>::type).name() << endl;
        cout << "type of tuple<int,float>: " << typeid(int).name() << endl;
        cout << "typeid int === typeid a1: " << (typeid(int).name()  == typeid(a1).name()) << endl;

        std::vector<std::tuple<int,float>> v{{1,2.11}};

        std::tie(a1, std::ignore, std::ignore) = fx();

        int n ;
        auto tt = std::tuple_cat(t, std::tie(n));
        cout << get<1>(tt) << endl;
    }

    void test_ptr()
    {
        shared_ptr<string> pNico(new string("nico"));
        shared_ptr<string> pJutta(new string("jutta"));

        shared_ptr<int[]> pps(new int[10]);
        unique_ptr<int[]> ppu(new int[10]);

        (*pNico)[0] = 'N';
        pJutta->replace(0,1, "J");

        vector<shared_ptr<string>> whoMadeCoffee;
        whoMadeCoffee.push_back(pJutta);
        whoMadeCoffee.push_back(pJutta);
        whoMadeCoffee.push_back(pNico);
        whoMadeCoffee.push_back(pJutta);
        whoMadeCoffee.push_back(pNico);

        for(auto ptr : whoMadeCoffee){
            cout << *ptr<< endl;
        }

        cout << whoMadeCoffee[0].use_count() << endl;

        shared_ptr<void> sp(new int);
        static_pointer_cast<int*> (sp);

        struct X
        {
            int a;
        };

        unique_ptr<X> sx1(new X);
//        unique_ptr<X> sx2(std::move(sx1));

        shared_ptr<X> sp1(new X);
//        shared_ptr<X> sp2(sp1, new X);

        sp1.reset();
//        shared_ptr<X> sp3(sp1, new X);

        try{
            shared_ptr<string> sp(new string("nico"));
            weak_ptr<string> wp(sp);

            sp.reset();
            cout << wp.use_count() << endl;
            cout << wp.expired() << endl;

            shared_ptr<string> sp2(sp);
//            shared_ptr<string> sp2(wp);
            cout << "sp :: " << *sp << endl;
        }catch (std::exception const &e){
            cerr<< "exception: " << e.what() << endl;
        }
    }


    void test_limit()
    {
        typedef numeric_limits<int> tnl;
        using lnt = numeric_limits<int>;
        cout << tnl::is_signed << endl;
        cout << tnl::is_specialized << endl;
        cout << tnl::is_bounded<< endl;
        cout << tnl::is_modulo<< endl;
        cout << tnl::is_iec559<< endl;
        cout << tnl::is_integer<< endl;
        cout << tnl::min()<< endl;
        cout << tnl::max()<< endl;
        cout << tnl::lowest()<< endl;
        cout << tnl::digits<< endl;
        cout << tnl::digits10<< endl;

        cout << "----------------" <<endl;
        cout << lnt::is_signed << endl;
        cout << lnt::is_specialized << endl;
        cout << lnt::is_bounded<< endl;
        cout << lnt::is_modulo<< endl;
        cout << lnt::is_iec559<< endl;
        cout << lnt::is_integer<< endl;
        cout << lnt::min()<< endl;
        cout << lnt::max()<< endl;
        cout << lnt::lowest()<< endl;
        cout << lnt::digits<< endl;
        cout << lnt::digits10<< endl;
        cout << "----------------" <<endl;

        cout << typeid(tnl).name() <<endl;
        cout << typeid(lnt).name() <<endl;
    }

    void maiev_test()
    {
        test_limit();
        fx2(1);
//        test_ptr();
//        test_tuple();
//        QU qu{};
//        QU qu = {}; //error , explicit construt()
//        test_pair();
//        test_map();
//        test_align();
    }

}