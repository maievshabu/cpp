//
// Created by redredmaple on 2026/1/9.
//

#include <memory>
#include "empty.h"
#include "01.h"
//using namespace d109;
using namespace ::std;
using namespace d113;

void xyz(){
    std::cout << "global xyz()" << std::endl;
}

void outOfMem(){
    std::cerr << "no enough mem!!!" << std::endl;
    std::abort();
}

void d109::test() {
    {
        std::set_new_handler(outOfMem);
        int * pBig = new int[1000000000000];
    }

#ifdef MAIEV
    {
        std::cout << Factorial<5>::value << std::endl;
        std::cout << Factorial<10>::value << std::endl;
    }
    {
        d113::Rational<int> oneHalf(1,2);
        d113::Rational<int> result = oneHalf * 2;
        d113::Rational<int> result1 = 2* oneHalf;
    }

    {
        SmartPtr<d112::A> s1(new d112::A1);
        SmartPtr<d112::A> s2(new d112::A2);

        SmartPtr<d112::A1> a1(new d112::A1);

//        std::cout << xyz << std::endl;
//        A a;
//        a.xyz();

//        SquareMatrix<double, 5> s1;
//        SquareMatrix<double, 10> s2;
//
//        s1.invert();
//        s2.invert();
//        MsgInfo info;
//        LoggingMsgSender<CompanyZ> zMsgSender;

//        LoggingMsgSender<CompanyA> l1;
//        l1.sendClearMsg(info);
//
//        LoggingMsgSender<CompanyB> l2;
//        l2.sendClearMsg(info);
//        MsgSender<CompanyA> s1;
//        MsgSender<CompanyB> s2;
//        s1.sendClear(info);
//        s2.sendSecret(info);
//        std::vector<int> vc{1,2,3,4};
//        f(vc, vc.begin());
    }
    {
//        Mp3Player mp;
//        mp.checkout();
    }
    {
        d113::Person p;
        d113::Student s;
        eat(p);
//        eat(s);

        Set<int> s1;
        s1.insert(1);
        s1.insert(2);
        s1.insert(3);
        s1.insert(1);

        std::cout << s1.member(1) << std::endl; //1
        std::cout << s1.size() << std::endl; //3
        s1.remove(3);
        std::cout << s1.size() << std::endl; //2
    }

    {
        Shape *ps;
        Shape* pc = new Circle;
        Shape* pr = new Rectangle;
        pr->draw();
        pc->draw();
    }

    {
        D x;
        B* pb = &x;

        pb->mf();

        D* pd = &x;
        pd->mf();
    }

    {
        auto fast = [](const GameCharacter& gc){
            return 50;
        };

        auto slow = [](const GameCharacter& gc){
            return 10;
        };

        auto dynamic = [](const GameCharacter& gc){
            static int counter = 0;
            return 100 - (++counter * 10);
        };

//        auto fast = std::make_shared<FastHealthLoss>();
//        auto slow = std::make_shared<SlowHealthLoss>();
//
        GameCharacter hero(fast);
        GameCharacter villain(slow);
        GameCharacter boss(dynamic);

        std::cout << "hero health: " << hero.healValue() << std::endl;
        std::cout << "villain health: " << villain.healValue() << std::endl;
        std::cout << "boos health(1th): " << boss.healValue() << std::endl;
        std::cout << "boos health(2th): " << boss.healValue() << std::endl;

//        EvilBadGuy ebg1(loseHealthQuickly);
//        EvilBadGuy ebg2(loseHealthSlowly);

//        GameCharacter gc;
//        std::cout << gc.healValue() << std::endl;
//        A a;
//        int val = a.healValue();
//        std::cout << val << std::endl;
    }

    {
        d112::A1 a1;
        a1.zi(1);
        a1.x();
        a1.y();
        a1.z();
        std::cout << "--------" << std::endl;

        d112::A *d1 = new d112::A1;
        d1->x();
        d1->A::x();
        d1->y();
        d1->z();

        std::cout << "---------" << std::endl;

        d112::A *d2 = new d112::A2;
        d2->x();
        d2->y();
        d2->z();

        std::cout << "------------" << std::endl;
    }

    {
        d112::Foo foo;
        string name = foo.getName();
        std::cout << "name: " <<  name << std::endl;
        name = string("qqqq");
        std::cout << "name: " <<  name << std::endl;
    }

    {
        Widget<int> w1;
        Widget<int> w2;
//        w2 = w1;
        swap(w1, w2);
    }


    {

        Rational a(1,2);
        Rational b(3,5);
//        Rational c = a * b;
        Rational d = 2 * a;
        cout << "xx" << endl;
    }
    {
        Empty e1; //默认构造
        Empty e2(e1); //拷贝构造
        e2 = e1; //拷贝赋值

//        using namespace std;
//        std::cout << "size of Empty: " << sizeof(Empty) << std::endl;
//        std::cout << "size of e1: " << sizeof(e1) << std::endl;
//        std::cout << "size of e2: " << sizeof(e2) << std::endl;
    }

    {
        shared_ptr<Invest> sp(new Invest);
    }

    {
        BuyTransaction b;
    }

    {
        TimeKeeper *ptr = getTimeKeeper();
        delete ptr; //需要主动释放 [如果没有虚基类,子类的析构不调用]
    }

//    HomeForSale h1;
//        HomeForSale h2(h1);
//        h2 = h1;

#endif

}