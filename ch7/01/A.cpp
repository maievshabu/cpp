//
// Created by xiaowei003 on 2024/9/22.
//

#include "A.h"
#include <iostream>

namespace ch701
{
    void my_pair()
    {
        cout << "------------------" << endl;
        mypair<int> obj(10, 20);
        cout << "pair-max::" << obj.getMax() << endl;
    }

    void my_foo()
    {

        cout << "------------------" << endl;
        Myclass foo(10);
        cout << foo.get() << endl;

        foo.get() = 15;
        cout << foo.get() << endl;

        const Myclass foo2(20);
        print(foo2);

        cout << "test" << endl;
    }

    void my_container()
    {
        cout << "------------------" << endl;
        mycontainer<int> myint(7);
        mycontainer<char> mychar('z');

        cout << "myint-increase::" << myint.increase() << endl;
        cout << "mychar-upperlowd" << mychar.uppercase() << endl;
    }

    void my_pr()
    {
        cout << "------------------" << endl;
        prval(1);
        prval<int>(10);
        prval<char>('a');
        prval<std::string>(std::string("maiev"));
    }

    void my_ptr()
    {
        int *p1 = new int(10);
        int *p2 = p1;

        cout << "p1:" << p1 << endl; //pointer to new int
        cout << "p2:" << p2 << endl; //pointer to new int
        // p1 == p2

        cout << "&p1:" << &p1 << endl; //address of p1
        cout << "&p2:" << &p2 << endl; //address of p2
        // &p1 != &p2;

        cout << "*p1:" << *p1 << endl; //pointer to 10
        cout << "*p2:" << *p2 << endl; //pointer ot 10
        // *p1 == *p2;

        delete p1;
    }

    void my_example()
    {
        /*
        Example4 ex(new int(10));
        Example4 ex2 = ex; //copy constructor
        Example4 ex2(ex); //copy constructor
        cout << "-----------" <<endl;
        Example4 ex3(new int(1));
        ex3.pr(); //1
        ex3 = ex2; //copy assign
        ex3.operator=(ex2);
        ex3.pr(); // *10


        ex3 = ex;
        Example ex(10);
        Example ex2(ex);
        ex2.accumulate(10);

        Example5 foo("exmaple");
        Example5 bar("miaev");
        cout << "bars'content :: " << bar.content() << endl;

        bar = foo;
        cout << "bars'content :: " << bar.content() << endl;
        */

        Example6 foo("Exam"); //default contructor
        Example6 bar = Example6("ple"); //move constrctor ??????????
//        Example6 bar = move(Example6("ple")); //move constrctor
        foo = foo + bar; //moe-assign

        cout << "foo'content :: " << foo.content() << endl;
    };

    void my_rectange()
    {
//        Rectangle foo;
//        Square bar(4);
//        foo.convert(bar);
//
//        cout << "area is ::" << foo.area() << endl;


        Recttangle recttangle;
        Triangle triangle;

        recttangle.set_v(1, 2);
        triangle.set_values(1, 2);

        X x(1,3);

        cout << "rect area::" << recttangle.area() << endl;
        cout << "tri area::" << triangle.area() << endl;
        cout << "x area::" << x.area() << endl;

        Daughter kelly(10);
        Son mike(0);

        Xs xs(10);
        xs.getD();
//        xs.getS();  //private

        cout << "sux::" << sux(1,3) << endl;
        cout << "sux::" << sux<int>(1,3) << endl;

        cout << fix_sux<int, 2>(10) << endl;
        cout << fix_sux<int, 3>(10) << endl;
    }

    template <typename T>
    class MyContainer{
    public:
        void add(const T& item){
            cout << "add item ::" << item << endl;
        }
    };

    template<>
    class MyContainer<std::string>{
    public:
        void add(const std::string& item){
            cout << "item::" << item << endl;
        }
    };

    void my_containerx()
    {
        MyContainer<int> myContainer;
        myContainer.add(10);

        MyContainer<std::string> aa;
        aa.add("uuub");
    }

    int maxx(int a , int b)
    {
        cout << "comon max::" << endl;
        return a > b ? b : a;
    }

    template <typename T>
    T maxx(T a, T b)
    {
        cout << "template max"<<endl;
        return a > b ? b : a;
    }

//    template <typename T1, typename T2>
//    auto max(T1 a , T2 b) ->decltype(b < a ? a : b) {}
//
//    template<typename TR, typename T1, typename T2>
//    TR max(T1 a , T2 b)
//    {
//        return b < a ? a : b;
//    }

    void my_max()
    {
        maxx(7,22);
        ::max(7,12);
        ch701::maxx(7,12);
        ch701::maxx<int>(7,20);
        ch701::maxx<double>(7.0, 20.0);
        ch701::maxx<long double>(7.2, 4);
        ch701::maxx('a', 42);
//        ::maxx('a', 42);
//        std::cout << ::max(7, 22) << std::endl;
//        std::cout << std::max(7, 22) << std::endl;
//        std::cout << ::max<double>(7.0, 22.0) << std::endl;
//        auto b = ::max<long double>(7.2, 4);
//        std::cout << b << std::endl;
    }

    void my_comment()
    {
        ValueWithComment<int> val;
        val.value = 100;
        val.comment = "this is a comment!";
    }

    template<typename T, std::size_t Maxsize>
    Stack<T, Maxsize>::Stack():numElems(0)
    {
        array<T,Maxsize> elems{};
    }

    template<typename T, std::size_t Maxsize>
    void Stack<T, Maxsize>::push(T const& elem)
    {
        assert(numElems < Maxsize);
        elems[numElems] = elem;
        ++numElems;
    }

    template<typename T, std::size_t Maxsize>
    void Stack<T, Maxsize>::pop()
    {
        assert(!elems.empty());
        --numElems;
    }

    template<typename T, std::size_t Maxsize>
    T const& Stack<T,Maxsize>::top() const
    {
        assert(!elems.empty());
        return elems[numElems - 1];
    }

    template<typename T, T val>
    T bar()
    {
        return val;
    }

    template <typename T>
    void Base<T>::bar() {
        cout << "base -bar :" <<endl;
    }

    void my_stack()
    {
        Stack<int, 20> int20stack;
        Stack<int, 40> int40ack;
        Stack<std::string, 40> str40stack;

        int20stack.push(7);
        cout << int20stack.top() << endl;
        int20stack.pop();

        str40stack.push("hello");
        cout << str40stack.top() << endl;
        str40stack.pop();

        cout << addValue<10, int>(20) <<endl;

        cout << bar<int, 20>() << endl;

        Messge<s11> m11;
        m11.pr();

//        C<sizeof(int) + 4, sizeof(int) == 4> c;
    }

    void my_print()
    {
        printx(1,2,"1.2", "hello world");
//        cout << "sum of sum(1,2,3...):" << sum(1,2,3,4,5,6) <<endl;

        Derived<int> derived;
        derived.foo();

        BB bb;
        bb.foo();
    }

    template <typename T1, typename T2, typename T3>
    void foo(
            int a1[7], int a2[],
            int (&a3)[42],
            int (&x0)[],
            T1 x1,
            T2& x2, T3&& x3 )
    {
        MyClass<decltype(a1)>::pr();
        MyClass<decltype(a2)>::pr();
        MyClass<decltype(a3)>::pr();
        MyClass<decltype(x0)>::pr();
        MyClass<decltype(x1)>::pr();
        MyClass<decltype(x2)>::pr();
        MyClass<decltype(x3)>::pr();
    }

    void my_less()
    {
//        int x[] = {1,2,3};
//        int y[] = {1,2,3, 4,5, 6};
//
//        cout << less(x, y) << endl;
//        cout << less("abc", "ab") << endl;

        int a[42];
        MyClass<decltype(a)>::pr();

        extern int xx[];
//        int xx[] = {0, 8, 15};
        MyClass<decltype(xx)>::pr();

        foo(a, a, a, xx, xx,xx, xx);

        int aa[15] = {0};
        fx(aa);
    }

    int xx[] = {0, 8, 15};

    template <typename T1>
    template <typename T2>
    St<T1>& St<T1>::operator=(const St<T2> &st) {
        cout << "operator="<< st._a << endl;
        _a = st._a;
        return *this;
    }

    void my_assign()
    {
        St<int> s1(1), s2(2);
        St<long> s3(3L);

        s1.pr();
        s2.pr();
        s3.pr();

        s1 = s3;
        s2 = s1.operator=(s3);

        s1.pr();
        s2.pr();
        s3.pr();
    }

    template <>
    inline bool Boolstring::get<bool>() const {
        return value == "true" || value == "1" || value == "on";
    }

    void maiev_bool()
    {
        std::string foo("on");
        Boolstring bs(foo);

        cout << bs.get() << endl;
        cout << bs.get<bool>() << endl;
    }

    void test()
    {
        maiev_bool();
    }
}
