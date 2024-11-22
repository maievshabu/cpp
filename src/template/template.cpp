//
// Created by xiaowei003 on 2024/11/12.
//

#include "template.h"
#include "variadic.h"
#include <iostream>
#include "../stl/util/Util.h"
#include <vector>
#include <limits>
#include <type_traits>
#include <iterator>
#include <complex>
#include <tuple>
#include <utility>
#include <set>
#include <algorithm>
#include <sstream>
#include <numeric>

int main(void)
{
    std::cout << "Hello world!!" << std::endl;
    /**
    int a = 10;
    int b = 10;

    int*pa = &a;
    int*pb = &a;

    std::cout << "pa: " << pa << std::endl;
    std::cout << "pb: " << pb << std::endl;

    int&ra = a;
    int&rb = b;

    std::cout << "ra: " << ra << std::endl;
    std::cout << "rb: " << rb << std::endl;

//    auto c = maxx(a, b);
//    auto c = maxx(pa, pb);
    auto c = maxx(ra, rb);

//    f(1);
//    f();

    auto d = maxx<double>(4,4.2);
    auto f = maxx(4,4.2);

    std::cout << "maxx(a,b) = " << c << std::endl;
     **/

    std::string name = "MAIEV";
    MAIEV<std::string> m = name;
//    MAIEV<int> m("MAIEV");
//    auto m = MAIEV<int>("maiev");
//    std::cout << m << std::endl;
//    m.operator<<(std::cout);
    std::cout << m << std::endl;
    m.operator<<(std::cout);

    MAIEV<double> md(10.71), md1;
    md1 = md;
    std::cout << md << std::endl;
    md1.operator<<(std::cout);

    MAIEV<int> mi;
    mi = md;
    std::cout << mi << std::endl;
    mi.operator<<(std::cout);

//    std::cout << "----------------" << std::endl;
//    MAIEV<int> md2;
//    md2 = md;
//    std::cout << md2 << std::endl;
//    md2.operator<<(std::cout);
//    std::cout << "----------------" << std::endl;

    MAIEV<int*> mm(new int(11));
    std::cout << mm << std::endl;
    mm.operator<<(std::cout);

    std::cout << "------------" << std::endl;
    C<10, false> cc;

    C1 c1;
    std::cout << c1.getI(cc) << std::endl;

    B1 b1;
    std::boolalpha;
    std::cout << b1.getB(cc) << std::endl;

    int ab[42];
    MyClass<decltype(ab)>::print(); //MYclass<T[42]>

    extern int x[];
    MyClass<decltype(x)>::print(); //Myclass<T[]>

//    foo(ab, ab, ab, x, x, x, x);

    /**
     * c14
    arr<10>[0] = 1;
    arr<10>[1] = 1;
    arr<10>[2] = 1;
    arr<10>[3] = 1;
    arr<10>[4] = 1;
    PRINT_CONTAINER(arr<10>, "arr: ");
    std::cout << myMax<int> << std::endl;
     **/

    std::vector<int> vc{1,2,3};
    Foo2<int, std::string, double> foo2(1,"cout", 1.1);
    ff(1, mi, foo2);

    /** c17
    Message<41> msg_i;
    msg_i.print();

//    Message<1.11> msg_f;
//    msg_f.print();

    static char const s[] = "hello";
    Message<s> msg_char;
    msg_char.print();

//    Message<std::string("uuuu")> msg_str;
//    msg_str.print();
     **/

    my_print(1,1.1, 1.1e10, "fff", mm);

    std::cout << "---------" << std::endl;
    printV(1);
    printV(name);
    printV(std::move(name));

    Func<int> func;
    int fa = 100;
    int a = func.operator()(fa);
    int b = func(fa);

    Mixer<int> mixer_i;
    Mixer<double> mixer_d;
    Mixer<RefMem<int>> mixer_o;

//    int ax = 121_B7;

    ff(1, 33);
    ff(10);

    std::cout << "-------------" << std::endl;
    A11 * a11 = new A11;
    A11 * b11 = new B11;
    B11 * b12 = new B11;

    a11->assign(); //A1
    b11->assign(); //A1
    b12->assign(); //B1


    unsigned const one = bbinary<011>::value;
    unsigned const three = bbinary<11>::value;

    std::cout << one << std::endl;
    std::cout << three << std::endl;

//    auto print = [](auto rem, auto const& pair){
//        std::cout << rem << "(" << pair.first << ", " << pair.second << ")\n";
//    };

    std::pair<int, float> p1;
    printx("(1) 值初始化: ", p1);

    std::pair<int, double> p2{42, 3.1415};

    auto p3 = std::make_pair(1, 1.34);
    std::cout << std::get<0>(p3) << std::endl;
//    std::cout << std::get<int>(p3) << std::endl;

    p3.swap(p2);
    std::swap(p2, p3);

    std::cout << std::get<1>(p2) << std::endl;

    printx("(2) 2个值进行初始化: ", p2);

//    std::pair<char, int> p4{p2};
    std::pair<char, int> p4;
    p4 = p2;
    printx("(3) 隐式转换: ", p4);

    std::pair<std::complex<double>, std::string> p6{
        std::piecewise_construct, std::forward_as_tuple(0.13, 7.7),
        std::forward_as_tuple(10, 'a')};
    printx("(4) 逐段构造:", p6);

    auto t1 = std::make_tuple(1, 2,3,3,4);
//    auto size = std::tuple_size<std::pair<int,double>>::value;
    auto val = std::tuple_size<decltype(t1)>();
    std::cout << val() << std::endl;
    std::cout << std::size_t(val) << std::endl;

    using elem = std::tuple_element<0, std::pair<int,double>>::type ;
    std::cout << typeid(elem).name() << std::endl;

    std::tuple<int,float> t{1,1.34};

    std::cout << "创建p1...\n";
    std::pair<Foo, Foo> p11(t,t);

    std::cout << "创建p2...\n";
//    std::pair<Foo, Foo> p12(std::piecewise_construct, std::tuple(1,2), std::tuple(1,3));
    std::pair<Foo, Foo> p12(std::piecewise_construct, std::forward_as_tuple(1,2), std::forward_as_tuple(1,1.111));

    std::pair<std::string,
            std::vector<int>> myPair(std::piecewise_construct,
                                     std::forward_as_tuple("niyou"),
                                     std::forward_as_tuple(5)
    );

    std::cout << std::get<0>(myPair) << std::endl;
    auto vcx = std::get<1>(myPair);
    std::cout << vcx.size() << std::endl;

    using tt = std::pair<int,int>;
    std::hash<tt> hash_fn;

    tt mx = std::make_pair(10, 20);
    auto hashValue = hash_fn(mx);

    std::cout << "hashvalue : " << hashValue << std::endl;

    std::cout << "-------------------" << std::endl;
    std::multiset<int> s{1,2,3};
    std::fill_n(std::inserter(s,s.begin()), 5, 2);
//    std::fill_n(std::insert_iterator(s,s.begin()), 5, 2);
//    std::fill_n(std::back_inserter(s),5, 2); //multiset no push_back
    for( auto n : s){
        std::cout << n << " ";
    }

    std::istringstream str("0.1 0.2 0.3 0.4");

    std::partial_sum(std::istream_iterator<double>(str),
                     std::istream_iterator<double>(),
                     std::ostream_iterator<double>(std::cout, " ")
    );

//    std::istringstream str2("1 3 5 7 8 9 10");
//    auto it = std::find_if(std::istream_iterator<int>(str2),
//            std::istream_iterator<int>(),
//                    [](int i ){ return i % 2 == 0;}
//            );
//
//    if (it != std::istream_iterator<int>()){
//        std::cout << "第一个偶数是 " << *it << std::endl;
//    }


    std::istringstream in{"hello, world"};
    std::istreambuf_iterator<char>it{in}, end;
    std::string ss{it,end};

    std::copy(ss.begin(), ss.end(), std::ostreambuf_iterator<char>(std::cout));

//    std::cout << "ss has size: " << ss.size() << "and is :" << ss << std::endl;

    std::istringstream sx{"abc"};
    std::istreambuf_iterator<char> ix1{sx}, ix2{sx};

    std::cout << " i1 : " << *ix1 ;
    std::cout << " i2 : " << *ix2 << std::endl;

    ++ix1;
    std::cout << " i1 : " << *ix1 ;
    std::cout << " i2 : " << *ix2 << std::endl;

    ++ix2;
    std::cout << " i1 : " << *ix1 ;
    std::cout << " i2 : " << *ix2 << std::endl;

    std::cout << ix1.equal(ix2) << std::endl;


//    std::tuple<int, int> x1 = std::forward_as_tuple(5, 10);
//    std::cout << std::get<0>(x1) << std::endl;
//    std::cout << std::get<1>(x1) << std::endl;

//    while(true) { // 清除输入流中的遗留字符
//        std::cout << "enter your data for actions:" << std::endl;
//        std::cin.clear();
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        std::string data;
//        std::getline(std::cin, data);
//        std::cout << "Data entered: " << data << std::endl;
//
//        bool flag = action();
//        if (!flag) { break; }
//        std::cout << "next loop : " << std::endl;
//    }

//    std::array<int, 3> ar{1,2,3};
//    std::cout << accum<int>(ar.begin(), ar.end()) << std::endl;
//    std::cout << accum<int, MultPolicy>(ar.begin(), ar.end()) << std::endl;
//
//    static_assert(std::is_same<RemoveRefenence<int>, int>::value);
//    static_assert(std::is_same<RemoveRefenence<int&>, int>::value);
//    static_assert(std::is_same<RemoveRefenence<int&&>, int>::value);
//
//    std::cout << std::integral_constant<int, 10>::value << std::endl;
//    std::cout << std::integral_constant<unsigned, 10>::value << std::endl;
//
//    std::pair<int,int> p1 = std::make_pair(100,10);
//    std::cout << p1.first << p1.second << std::endl;
//
//    std::cout << std::tuple_size<std::pair<int,int>>::value << std::endl;
//    std::cout << typeid(std::tuple_element<1, std::pair<int,int>>::type).name() << std::endl;
//
//    std::iterator_traits<std::vector<int>::iterator>::iterator_category posx;
}

int x[] = {0,8 ,15};
