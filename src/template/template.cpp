//
// Created by xiaowei003 on 2024/11/12.
//

#include "template.h"
#include "variadic.h"
#include <iostream>
#include "../stl/util/Util.h"
#include <vector>

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
}

int x[] = {0,8 ,15};
