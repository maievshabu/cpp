//
// Created by xiaowei003 on 2024/9/4.
//

#include "A.h"
#include <typeinfo>
#include <vector>
#include <string>
#include <map>
#include <type_traits>
#include <algorithm>

using namespace std;

namespace A06{

    typedef double (*func)();

    int hash(char*);

    double ffq()
    {
        cout << "ffq::: run " << endl;

        return 1.1f;
    }

    void OverLoad(int);
    void OverLoad(char);

    int && RvalRef();

    const bool Func(int);

    int action1(int & e) { e *= 2; return e;}
    int action2(int & e) { cout << e << '\t'; return 0;}

    int test() {

        vector<int> vv {1,2,3,4,5};
        for(auto v = vv.begin(); v != vv.end(); v++){
            cout << *v << endl; //迭代器对象,需要引用*
        }

        int ar[5] = {1,2,3,4,5};
        for_each(ar, ar+5, action1);
        for_each(ar, ar+5, action2);
        cout<<endl;

        int *par;
        for(par =ar; par != ar + 5;par++){
            cout << *par <<endl;
        }
        cout << "--------------"<<endl;
        for(auto pi: ar){
            cout << pi <<endl; //解引用后的对象
            break;
        }

        cout << "--------------"<<endl;
        cout << forward(1) << endl;
        cout << forward(1.11f) << endl;

        pf1();

        cout << is_same<decltype(pf), decltype(pf1)>::value<<endl;

        int a1 = 1;
        float a2 = 1.3f;

        auto zz = Sum(a1, a2);
        cout << "zz::" << zz <<endl;

        int si = 1; //int
        int &sj = si; //&sj
        int *sp = &si; //*si;

//        cout << "-----------------------" << endl;
//        int *ppp = &si;
//        auto ppp1 = ppp;
//        auto *ppp2 = ppp;
//
//        cout << "&si::" <<&si<<endl;
//        cout << "int *ppp::" <<&ppp <<endl;
//        cout << "auto ppp1::" <<&ppp1 <<endl;
//        cout << "auto *ppp2::" <<&ppp2 <<endl;

        cout << "-----------------------" << endl;
        cout << "si::" << si << endl;
        cout << "sj::" << sj << endl;
        cout << "*sp::" << *sp << endl;

        cout << "&si::" << &si << endl;
        cout << "&sj::" << &sj << endl;
        cout << "&sp::" << &sp << endl;

//        si = 2;
//        sj = 2;
        *sp = 2;
        cout << "-----------------------" << endl;
        cout << "si::" << si << endl;
        cout << "sj::" << sj << endl;
        cout << "sp::" << *sp << endl;

        cout << "&si::" << &si << endl;
        cout << "&sj::" << &sj << endl;
        cout << "&sp::" << &sp << endl;

        const int k = 1;

        decltype(si) &va1 = si;
        decltype(sj) &va2 = si;

        cout << "-----------------------" << endl;
        cout << "decltype(sj) &va2 is-rvalue" << is_rvalue_reference<decltype(va2)>::value<<endl;
        cout << "decltype(sj) &va2 is-lvalue::" << is_lvalue_reference<decltype(va2)>::value<<endl;

//        decltype(sp) *va3 = &si;
        decltype(sp) *va3 = &sp; //int **

        cout << "-----------------------" << endl;
        auto * v3 = sp; //v3类型是int *
        v3 = &si;
        cout << "v3::" << v3 <<endl;
        cout << "*v3::" << *v3 <<endl;
        cout << "&v3::" << &v3 <<endl;

        cout << "-----------------------" << endl;
        auto v4 = sp; //int *
        cout << "v4::" << v4 <<endl;
        cout << "*v4::" << *v4 <<endl;
        cout << "&v4::" << &v4 <<endl;

        const decltype(k) va4 = 1; //冗余的const

        const int ic = 0;
        volatile int iv;

        struct Si{int i;};
        const Si sa={0};
        volatile Si sb;
        volatile Si* ps= &sb;

        cout << "-----------------------" << endl;
        cout << "is-const ::" << is_const<decltype(ic)>::value <<endl;
        cout << "is-volatile::" << is_volatile<decltype(iv)>::value <<endl;
        cout << "is-const ::" << is_const<decltype(sa)>::value <<endl;
        cout << "is-volatile::" << is_volatile<decltype(sb)>::value <<endl;
        cout << "is-const ::" << is_const<decltype(sa.i)>::value <<endl;
        cout << "is-volatile::" << is_volatile<decltype(ps->i)>::value <<endl;

        int i = 4;
        int arr[5] = {0};
        int *ptr = arr;

        struct S{double d;} s;

        cout << "-----------------------" << endl;
        //判断左值,右值
        cout << "rvalue ::" << is_rvalue_reference<decltype(RvalRef())>::value <<endl;
        cout << "lvalue ::" << is_lvalue_reference<decltype(true ? i : i)> ::value <<endl;

        //规则1: 单个标记符表达式以及访问类成员，推导未本类型
        decltype(arr) var1;
        decltype(ptr) var2;
        decltype(s.d) var3;
//        decltype(OverLoad) var4

        //规则2: decltype 将亡值 ： 推导右值引用
        decltype(RvalRef()) var6 = 1;

        //规则3: decltype 左值 ： 推导未类型的引用
        decltype(true ? i : i) var7 = i;
        decltype((i)) var8 = i;
        decltype((++i)) var9 = i; //++i返回左值
        decltype(arr[3]) var10 = i;
        decltype(*ptr) var11 = i;
        decltype("lval") var12 = "lval";


       //规则4: 以上都不是，推导为本类型
       decltype(1) var13; //int
       decltype(i++) var14; //int i++返回右值
       decltype((Func(1))) var15; //const bool,圆括号可以忽略


        func func1 = ffq;
        func1();

        result_of<func()>::type rf;
        cout << "f:::" << rf << endl;

        f<A>(10);
        f<int>(1.11);
        A a;
        A b;
        int c;
        float e;
        double f;

        cout << "-----------------------" << endl;
        std::cout<< "a::" << typeid(a).name() << std::endl;
        std::cout<< "c::" << typeid(c).name() << std::endl;
        std::cout << typeid(a).hash_code() <<std::endl;
        std::cout << (typeid(a) == typeid(c)  ? 1 : 0) << std::endl; // 0

        auto ii = c;
        decltype(i) j = 0;
        decltype( e + j) h;

        cout << typeid(i).name() << endl; //i
        cout << typeid(j).name() << endl; //i
        cout << typeid(h).name() << endl;

        using size_t = decltype(sizeof(0));
        using ptrdiff_t = decltype((int*)0 - (int*)0);
        using nullptr_t = decltype(nullptr);


        vector<int> vc;

        vc.push_back(1);
        vc.push_back(2);
        vc.push_back(3);

        typedef decltype(vc.begin()) vctype;

        cout << "-----------------------" << endl;
        for(vctype t = vc.begin(); t < vc.end(); t++){
            cout << *t <<endl;
        }

        cout << "-----------------------" << endl;
        for(auto t = vc.begin(); t < vc.end(); t++){
            cout << *t <<endl;
        }

        cout << "-----------------------" << endl;

        string who("maiev");

        char * name("MAIEVVV");
        cout << "name:::" << name << endl;

        cout<< "enum value::k1:::"<< K1 << endl;
        cout<< "kk:::"<< decltype(anon_e)::k2<< endl;

        decltype(anon_s) as;
        as[0].id.key = decltype(anon_e)::K1;
        as[0].id.name = name;

        cout << "as.key::" << (as[0].id.key) << endl;
        cout << "as.name::" << (as[0].id.name) << endl;

//        int aa = 1;
//        float bb = 1.2f;
//        float cc ;
//        Sum(aa, bb, cc);

//        cout << cc << endl;

        Pp person{10};
        Pptr p = &person;
        cout << "person age ::: " << person.age << endl;
        cout << "pptr age ::: " << p->age << endl;

        int a5s[5], b5s[5], c5s[5];
        Sum(a5s,b5s,c5s);

//        map<char*, decltype(hash)> dict_key;
        map<char*, decltype(hash(nullptr))> dict2_key;

        return 0;
    }
}
