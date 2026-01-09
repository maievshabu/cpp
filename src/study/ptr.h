//
// Created by redredmaple on 2025/12/10.
//

#ifndef WEB_PTR_H
#define WEB_PTR_H

#include "inc.h"
using namespace  std;

#define COUT(str) std::cout << '\n' << str << '\n'
#define DEMO(...) std::cout << #__VA_ARGS__ << " = " << __VA_ARGS__ << '\n'

namespace ptr{
    struct MyObj{
        MyObj() {std::cout << "MyObj() constructed "<< std::endl;}
        ~MyObj() {std::cout << "~MyObj() destructed "<< std::endl;}
    };

    struct Container: std::enable_shared_from_this<Container>{

        std::shared_ptr<MyObj> memberObj;
        void createMember(){
            memberObj = make_shared<MyObj>();
        }

        shared_ptr<MyObj> getAsMyObj(){
            return shared_ptr<MyObj>(shared_from_this(), memberObj.get());
        }
    };
    struct Base
    {
        Base() { std::cout << "Base::Base()\n"; }

        // Note: non-virtual destructor is OK here
        ~Base() { std::cout << "Base::~Base()\n"; }
    };

    struct Derived : public Base
    {
        Derived() { std::cout << "Derived::Derived()\n"; }

        ~Derived() { std::cout << "Derived::~Derived()\n"; }
    };

    struct Myxx{
        int a{0};
        Myxx(int i = 0): a(i){std::cout << "Myxx()" << std::endl;}
        ~Myxx(){std::cout << "~Myxx()" << std::endl;}
    };

    struct D{
        void operator()(Myxx* p){
            std::cout << "~" << std::endl;
            delete p;
        }
    };

    void print(const char*, std::shared_ptr<Base>const&);
    void thr(std::shared_ptr<Base>);
    void xy(shared_ptr<MyObj>const&);
//    void xy(shared_ptr<MyObj>);
    std::shared_ptr<MyObj> xy();

    void test();
    void test(int);

    namespace d108{
        class Person{
        public:
            //构造
            Person() = default;
            //构造
            Person(int age): pAge(make_shared<int>(age)){
                std::cout << "Person(int)" << std::endl;
            }
            //拷贝构造
            Person(const Person& oth){
                std::cout << "Person const(Person&)" << std::endl;
                pAge = oth.pAge;
            }
            //移动构造
            Person(Person&& oth) noexcept{
                std::cout << "Person (Person&&)" << std::endl;
                pAge = move(oth.pAge);
            }
            //拷贝赋值
            Person& operator=(const Person& oth){
                std::cout << "Person& operator=(const Person&)" << std::endl;
                if (this != &oth){
                    pAge = oth.pAge;
                }

                return *this;
            }
            //移动赋值
            Person& operator=(Person&& oth) noexcept{
                std::cout << "Person& operator=(Person&&)" << std::endl;
                if (this != &oth){
                    pAge = move(oth.pAge);
                }

                return *this;
            }
            //析构
            ~Person(){
                std::cout << "~Person(): " << "use_count: " << pAge.use_count() << std::endl;
            }
            int showAge()const{
                return pAge ? *pAge : -99999;
            }
        private:
            shared_ptr<int> pAge;
        };
    }
    namespace d108{
        struct Child;
        struct Parent{
            Parent(){std::cout << "Parent()" << std::endl;}
            ~Parent(){std::cout << "~Parent()" << std::endl;}
            shared_ptr<Child> child;
        };

        struct Child{
            Child(){std::cout << "Child()" << std::endl;}
            ~Child(){std::cout << "~Child()" << std::endl;}
            weak_ptr<Parent> parent;
        };

        struct xyz{
            shared_ptr<Parent> createFamily(){
                auto p = make_shared<Parent>();
                auto c = make_shared<Child>();
                p->child = c;
                c->parent = p;

                return p;
            }
        };
    }
}

#endif //WEB_PTR_H
