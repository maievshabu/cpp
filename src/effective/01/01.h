//
// Created by redredmaple on 2026/1/9.
//

#include <iostream>
#include <memory>
#include <mutex>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <algorithm>
#include <utility>

using namespace std;

#ifndef EFFECTIVE_01_H
#define EFFECTIVE_01_H


namespace d109 {
    class TimeKeeper {
    public:
        TimeKeeper() {
            std::cout << "TimeKeeper()" << std::endl;
        }

        virtual ~TimeKeeper() {
            std::cout << "~TimeKeeper()" << std::endl;
        }
    };

    class UnCopyable {
    protected:
        UnCopyable() {}

        ~UnCopyable() {}

    private:
        UnCopyable(const UnCopyable &);

        UnCopyable &operator=(const UnCopyable &);
    };

    class AtomicClock : public TimeKeeper {
    public:
        AtomicClock() {
            std::cout << "AtomicClock()" << std::endl;
        }

        ~AtomicClock() {
            std::cout << "~AtomicClock()" << std::endl;
        }
    };

    class WaterClock : public TimeKeeper {
    };

    class WristClock : public TimeKeeper {
    };

    TimeKeeper *getTimeKeeper() {
        return new AtomicClock;
    }

    class Point{
    public:
        Point(int xCoord, int yCoord);
        ~Point(){}
    private:
        int x, y;
    };

    class AWOV{
    public:
        virtual ~AWOV() = 0;
    };

    class DBConnection{
    public:
        static DBConnection create();
        void close();
    };

    class DBConn{
    public:
        ~DBConn(){
            if (!closed){
                try{
                    db.close();
                }catch(...){
                    std::abort();
                }
            }
        }
    private:
        DBConnection db;
        bool closed;
    };


    class Transaction{
    public:
        Transaction();
        virtual void logTransaction() const = 0;

    protected:
        void init(){
            logTransaction();
        }
    };

    Transaction::Transaction() {
//    init();
    }

    class BuyTransaction : public Transaction{
    public:
        BuyTransaction(){
            init();
        }
        virtual void logTransaction() const{
            std::cout << "buy log transaction " << std::endl;
        }
    };

    class SellTransaction : public Transaction{
    public:
        virtual void logTransaction() const{
            std::cout << "sell log transaction " << std::endl;
        }
    };
    struct Year{
        explicit Year(int y):val(y){}
        int val;
    };
    struct Day{
        explicit Day(int d):val(d){}
        int val;
    };
    struct Month{
        explicit Month(int m):val(m){}
        int val;
    };

    class Month2{
    public :
        static Month2 Jan() {return Month2(1);}
        static Month2 Feb() {return Month2(2);}
        static Month2 March() {return Month2(3);}
        static Month2 April() {return Month2(4);}
    private:
        explicit Month2(int m);
    };

    class Date{
    public:
        Date() = default;
        Date(int month, int day, int year);
    private:
        int month;
        int day;
        int year;
    };

    void logCall(const std::string& funcName){}

    class Customer{
    public:
        Customer() = default;
        Customer(const Customer& rhs);
        Customer& operator=(const Customer& rhs);
    private:
        std::string name;
        Date lastTransaction{};
    };

    Customer::Customer(const Customer &rhs):name(rhs.name) {
        logCall("Customer copy constructor");
    }

    Customer &Customer::operator=(const Customer &rhs) {
        logCall("customer copy assign operator");
        name = rhs.name;
        return *this;
    }

    class PriorityCustomer: public Customer{
    public:
        PriorityCustomer() = default;
        PriorityCustomer(const PriorityCustomer& rhs);
        PriorityCustomer& operator=(const PriorityCustomer& rhs);
    private:
        int priority;
    };

    PriorityCustomer::PriorityCustomer(const PriorityCustomer &rhs):priority(rhs.priority), Customer(rhs) {
        logCall("PriorityCustomer copy constructor");
    }

    PriorityCustomer &PriorityCustomer::operator=(const PriorityCustomer &rhs) {
        logCall("PriorityCustomer copy assign operator");
        Customer::operator=(rhs);
        priority = rhs.priority;

        return *this;
    }

    class Invest{
    public:
        bool isTaxFee() const;
        Invest(){std::cout << "Invest()" << std::endl;}
        ~Invest(){std::cout << "~Invest()" << std::endl;}
    };

    class Person{
    public:
        Person();
        virtual ~Person();
    private:
        std::string name;
        std::string address;
    };

    class Student: public Person{
    public:
        Student();
        ~Student();
    private:
        std::string schoolName;
        std::string schoolAddress;
    };

    bool validateStudent(const Student& s);
//    bool validateStudent(Student s);

    class Rational{
    public:
        Rational(int numerator =0, int denominator= 1):n(numerator),d(denominator){
        }
        int N()const{return n;}
        int D()const{return d;}
    private:
        int n,d;
    };

    const Rational operator*(const Rational& lhs, const Rational& rhs){
        return Rational(lhs.N()* rhs.N(), lhs.D() * rhs.D());
    }

    class WebBrowser{
    public:
        void clearCache(){}
        void clearHistory(){}
        void removeCookie(){}

        void clearEverything(){
            clearCache();
            clearHistory();
            removeCookie();
        }
    };

    //better
    void clearBrowser(WebBrowser& wb){
        wb.clearCache();
        wb.clearHistory();
        wb.removeCookie();
    }

    Rational fx(int num, const Rational& rhs){
        return rhs * num;
    }

//    namespace std{
//        template<typename T>
//        void swap(T a, T b){
//            T tmp(a);
//            a = b;
//            b = tmp;
//        }
//    }

    template<typename T>
    class WidgetImpl{
    public:
        WidgetImpl() = default;
    private:
        int a,b,c;
        vector<double> v;
    };

    template<typename T>
    class Widget{
    public:
        Widget() = default;
        Widget(const Widget& rhs);
        Widget& operator=(Widget& rhs){
            swap(rhs);
            return *this;
        }
        void swap(Widget& oth)noexcept{
            std::cout << "swap" << std::endl;
            using std::swap;
            ::swap(pImpl, oth.pImpl);
        }
    private:
        WidgetImpl<T>* pImpl;
    };
}

using namespace d109;
namespace std{
    template<typename T>
    void swap(Widget<T>& a, Widget<T>& b) noexcept{
        std::cout << "template<>swap()" << std::endl;
        a.swap(b);
    }
}

#endif //EFFECTIVE_01_H
