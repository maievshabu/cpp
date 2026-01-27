//
// Created by redredmaple on 2026/1/27.
//

#include "d127.h"

using namespace d127;
using namespace placeholders;

template<typename T>
T* d127::Singleton<T>::m_pInstance = nullptr;

void print(int a, int b) {cout << a << "," << b << endl;}


#if 0
//template<typename Receiver>
//void d127::SimpleCommand<Receiver>::Execute() {
//    (_receiver->*_action)(); //这里书上有问题把？？
//}

void dummy(){
    MyClass * receiver = new MyClass;
    Command * aCommand = new SimpleCommand<MyClass>(receiver, &MyClass::Action);
    aCommand->Execute();
}
#endif

void Print(shared_ptr<BigObject>p, const string& str){
    if (p != nullptr)
        p->Print(str);
}

#if 0
void testObjPool(){
    ObjectPool<BigObject> pool;
    pool.Init(2);
    {
        auto p = pool.Get();
        Print(p, "p");
        auto p2 = pool.Get();
        Print(p2, "p2");
        cout << "-------" << endl;
    }

    auto p = pool.Get();
    auto p2 = pool.Get();
    Print(p, "p");
    Print(p2, "p2");

    pool.Init(2,1);
    auto p4 = pool.Get<int>();
    Print(p4, "p4");
    pool.Init(2,1,2);
    auto p5 = pool.Get<int,int>();
    Print(p5, "p5");
}
#endif

void testVisitor(){
#if 0
    PrintVisitor vis;
    stA a;
    a.val = 8.97;
    stB b;
    b.val = 8;
    Base* base = &a;
    base->Accept(vis);
    base = &b;
    base->Accept(vis);
#endif
}

void d127::test(){
#if 0
    ConcreteVisitor v;
    std::unique_ptr<Element> emt1(new ConcreteElement1());
    std::unique_ptr<Element> emt2(new ConcreteElement2());

    emt1->Accept(v);
    emt2->Accept(v);

    Events<std::function<void(int,int)>> myEvent;

    auto key = myEvent.Connect(print);
    stA t;
    auto lambdaKey = myEvent.Connect([&t](int a, int b){ t.a = a; t.b = b;});

    std::function<void(int,int)> f = std::bind(&stA::print, &t, _1, _2);
    myEvent.Connect(f);
    int a = 1, b= 2;
    myEvent.Notify(a,b);
    myEvent.Disconnect(key);

    string str = "BB";
    Singleton<A>::Instance(str);
    Singleton<B>::Instance(std::move(str));
    Singleton<C>::Instance(1, 1.11);

    Singleton<C>::GetInstance()->Fun();

    Singleton<A>::DestoryInstance();
    Singleton<B>::DestoryInstance();
    Singleton<C>::DestoryInstance();
    Singleton<A>::Instance();
    Singleton<B>::Instance(1);
    Singleton<C>::Instance(1,2);

    Singleton<A>::DestoryInstance();
    Singleton<B>::DestoryInstance();
    Singleton<C>::DestoryInstance();
#endif
}

#if 0
void d127::Subject::Attach(Observer * o) {
    _observers->Append(o);
}

void d127::Subject::Detach(Observer *o) {
    _observers->Remove(o);
}

void d127::Subject::Notify() {
    ListIterator<Observer*> i(_observers);
    for(i.First(); !i.isDone(); i.Next()){
        i.currentItem()->Update(this);
    }
}
#endif
