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

namespace d112{
    class Point{
    public:
        Point() = default;
        Point (int xVal, int yVal):x(xVal),y(yVal){}
        void setX(int newVal){ x = newVal;}
        void setY(int newVal){ y = newVal;}
    private:
        int x{}, y{};
    };

    struct RectData{
        Point ulhc;
        Point rlhc;
    };

    class Rectangle{
    public:
        const Point& upperLeft() const{return pData->ulhc;}
        const Point& lowRight() const{return pData->rlhc;}
    private:
        shared_ptr<RectData> pData;
    };

    class Foo{
    public:
        const string& getName() const{return name;}
    private:
        string name{"maievvv"};
    };

    class Address{};
    using namespace d109;

    class Person{
    private:
        string theName;
        Date theBirthDate;
        Address theAddress;
    };

    class A {
    public:
        virtual void x() = 0;
        virtual void y(){
            std::cout << "A::y" << std::endl;
        }
        void z(){
            std::cout << "A::z()" << std::endl;
        }
    };

    void A::x() {
        std::cout << "A::x()" << std::endl;
    }

    class A1 : public A{
    public:
        void x(){
            std::cout << "A1::x()" << std::endl;
        }
        void z(){
            std::cout << "A1::z()" << std::endl;
        }

        void zi(int){
            std::cout << "A1::z(int)" << std::endl;
        }
    };

    class A2 : public A{
    public:
        void x(){
            std::cout << "A2::x()" << std::endl;
        }
        void y(){
            std::cout << "A2::y()" << std::endl;
        }
        void z(){
            std::cout << "A2::z()" << std::endl;
        }
        int zi(int){
            std::cout << "A1::z(int)" << std::endl;
            return 1;
        }
    };
}

namespace d113{
//    class GameCharacter{
//    public:
//        int healValue() const{
//            int retVal = doHealValue();
//
//            return retVal;
//        }
//    private:
//        virtual int doHealValue() const{
//            return 1;
//        }
//    };
//
//    class A : public GameCharacter{
//    private:
//        int doHealValue()const{
//            return 100;
//        }
//    };

    class GameCharacter;
//    int defaultHealThCalc(const GameCharacter& gc);
//    class GameCharacter{
//    public:
//        typedef int (*HealCalcFunc)(const GameCharacter&);
//        explicit GameCharacter(HealCalcFunc hcf = defaultHealThCalc):healthFunc(hcf){}
//        int healValue()const{
//            return healthFunc(*this);
//        }
//    private:
//        HealCalcFunc healthFunc;
//    };
//
//    class EvilBadGuy: public GameCharacter{
//    public:
//        explicit EvilBadGuy(HealCalcFunc hcf = defaultHealThCalc) : GameCharacter(hcf){}
//    };
//
//    int loseHealthQuickly(const GameCharacter&);
//    int loseHealthSlowly(const GameCharacter&);

//    class HealthCalcFunc{
//    public:
//        virtual int operator()(const GameCharacter& gc) const = 0;
//        virtual ~HealthCalcFunc(){}
//    };
//
//    class FastHealthLoss: public HealthCalcFunc{
//    public:
//        int operator()(const GameCharacter& gc)const{
//            return 50;
//        }
//    };
//
//    class SlowHealthLoss: public HealthCalcFunc{
//    public:
//        int operator()(const GameCharacter& gc)const{
//            return 10;
//        }
//    };
//
////    HealthCalcFunc defaultHealthFunc;
//    class GameCharacter{
//    public:
//        explicit GameCharacter(std::shared_ptr<HealthCalcFunc> hcf):healthFunc(hcf){}
//        int healValue()const{
//            return (*healthFunc)(*this);
//        }
//    private:
////        HealthCalcFunc* pHealthCalc;
//        std::shared_ptr<HealthCalcFunc> healthFunc;
//    };

    class GameCharacter{
    public:
        using HealthCalcFun = std::function<int(const GameCharacter&)>;
        explicit GameCharacter(HealthCalcFun hcf): healthCalcFunc(hcf){}
        int healValue()const{
            return healthCalcFunc(*this);
        }
    private:
        HealthCalcFun healthCalcFunc;
    };

    class B{
    public:
        void mf(){
            std::cout << "B::mf()" << std::endl;
        }
    };

    class D: public B{
    public:
        void mf(){
            std::cout << "D::mf()" << std::endl;
        }
    };

    class Shape{
    public:
        enum ShapeColor {Red, Green, Blue};
        virtual void draw(ShapeColor color = Red) const = 0;
    };

    class Rectangle: public Shape{
    public:
        virtual void draw(ShapeColor color = Green) const{
            std::cout << color << std::endl;
        }
    };

    class Circle : public Shape{
    public:
        virtual void draw(ShapeColor color = Blue) const{
            std::cout << color << std::endl;
        }
    };

//    class Address{};
//    class PhoneNumber{};
//    class Person{
//    private:
//        string name;
//        Address address;
//        PhoneNumber voiceNumber;
//        PhoneNumber faxNumber;
//    };

    template<typename T>
//    class Set : public std::list<T>{};
    class Set{
    public:
        bool member(const T& item)const;
        void insert(const T& item);
        void remove(const T& item);
        std::size_t size() const;
    private:
        std::list<T> rep;
    };

    template<typename T>
    bool Set<T>::member(const T &item) const {
        return std::find(rep.begin(), rep.end(), item) != rep.end();
    }

    template<typename T>
    void Set<T>::insert(const T &item) {
        if (!member(item)){
            rep.push_back(item);
        }
    }

    template<typename T>
    void Set<T>::remove(const T &item) {
        typename std::list<T>::iterator it = std::find(rep.begin(), rep.end(), item);
        if (it != rep.end()){
           rep.erase(it);
        }
    }

    template<typename T>
    std::size_t Set<T>::size() const {
        return rep.size();
    }

    class Person{};
    class Student: private Person{};
    void eat(const Person& p){}
    void study(const Student& s){}

    class Timer{
    public:
        explicit Timer(int tickFrequency);
        virtual void onTick() const;
    };

//    class Widget: private Timer{
//    private:
//        virtual void onTick() const;
//    };

    class Widget{
    private:
        class WidgetTimer: public Timer{
        public:
            virtual void onTick() const;
        };
        WidgetTimer timer;
    };
    class Empty{};
//    class HoldsAnInt{
//    private:
//        int x;
//        Empty e;
//    };

    class HoldsAnInt : private Empty{
    private:
        int x;
    };

//    class BorrowableItem{
//    public:
//        void checkout(){}
//    };
//
//    class ElectronicGadget{
//    private:
//        bool checkout() const{}
//    };

//    class Mp3Player:
//            public virtual BorrowableItem,
//            public virtual ElectronicGadget{
//    };

    template<typename T>
    void doProcessing(T& w){
        T someEasyWidget;
        if (w.size() > 10 && w != someEasyWidget){
            T temp(w);
            temp.normalize();
            temp.swap(w);
        }
    }

    template<typename C>
    void print2nd(const C& container){
        if (container.size() >= 2){
            typename C::const_iterator it(container.begin());
            ++it;
            int value = *it;
            std::cout << value;
        }
    }

    template<typename C>
    void f(const C& container, typename C::iterator iter){

    }

    template<typename T>
    class Base{};

    template<typename T>
    class Derived: public Base<T>::Nested{

    public:
        explicit Derived(int x): Base<T>::Nested(x){
            typename Base<T>::Nested temp;
        }
    };

    template<typename IterT>
    void workWithIterator(IterT iter){
        typedef typename std::iterator_traits<IterT>::value_type value_type;
        value_type temp(*iter);
    }

    class CompanyA{
    public:
        void sendCleartext(const std::string& msg){
            std::cout << "CompanyA::sendClearText()" << std::endl;
        }
        void sendEncrypted(const std::string& msg){
            std::cout << "CompanyA::sendEncrypted()" << std::endl;
        }
    };

    class CompanyB{
    public:
        void sendCleartext(const std::string& msg){
            std::cout << "CompanyB::sendClearText()" << std::endl;
        }
        void sendEncrypted(const std::string& msg){
            std::cout << "CompanyB::sendEncrypted()" << std::endl;
        }
    };
    class MsgInfo{};

    template<typename Company>
    class MsgSender{
    public:
        void sendClear(const MsgInfo& info){
            std::string msg;
            Company c;
            c.sendCleartext(msg);
        }

        void sendSecret(const MsgInfo& info){
            std::string msg;
            Company c;
            c.sendEncrypted(msg);
        }
    };

    class CompanyZ{
    public:
        void sendEncrypted(const std::string& msg){
            std::cout << "CompanyZ::sendEncrypted()" << std::endl;
        }
    };

    template<>
    class MsgSender<CompanyZ>{
    public:
        void sendSecret(const MsgInfo& info){
            CompanyZ z;
            z.sendEncrypted("xyz");
        }
    };

    template<typename Company>
    class LoggingMsgSender: public MsgSender<Company>{
    public:
        using MsgSender<Company>::sendClear;
        void sendClearMsg(const MsgInfo& info){
            //将"传送前"的信息写至log;
            MsgSender<Company>::sendClear(info);
//            sendClear(info);
//            this->sendClear(info);
            //将"传送后"的信息写至log;
        }
    };

//    template<typename T, std::size_t n>
//    class SquareMatrix{
//    public:
//        void invert(){
//            std::cout << n <<"X" << n << " matrix invert" << std::endl;
//        }
//    };

    template<typename T>
    class SquareMatrixBase{
    protected:
        SquareMatrixBase(std::size_t n, T* pMem):size(n),pData(pMem){}
        void setDataPtr(T* ptr){pData = ptr;}
        void invert(std::size_t n){
            std::cout << n <<"X" << n << " matrix invert" << std::endl;
        }

    private:
        std::size_t size;
        T* pData;
    };

    template<typename T, std::size_t n>
    class SquareMatrix : private SquareMatrixBase<T>{
    public:
        SquareMatrix(): SquareMatrixBase<T>(n, data){}
        void invert(){
            this->invert(n);
        }
    private:
        using SquareMatrixBase<T>::invert;
        T data[n*n];
    };

    template<typename T>
    class SmartPtr{
    public:
        explicit SmartPtr(T* ptr):heldPtr(ptr){}
        template<typename U>
        SmartPtr(const SmartPtr<U>& other) :heldPtr(other.get()){};
        T* get() const{return heldPtr;}
    private:
        T* heldPtr;
    };

    template<typename T>class Rational;
    template<typename T>
    const Rational<T> doMultiply(const Rational<T>& lhs, const Rational<T> & rhs){
        return Rational<T>(lhs.numberator() * rhs.numberator(), lhs.denominator() * rhs.denominator());
    }

    template<typename T>
    class Rational{
    public:
        Rational(const T& numerator =0, const T& denominator = 1){
            num = numerator;
            deno = denominator;
        }
        const T numberator() const{
            return num;
        }
        const T denominator() const{
            return deno;
        }
        friend const Rational<T>operator*(const Rational<T>& lhs, const Rational<T>& rhs){
            return doMultiply(lhs,rhs);
        }
    private:
        T num;
        T deno;
    };

    template<typename IterT, typename DistT>
    void advance(IterT& iter, DistT d);

    template<unsigned n>
    struct Factorial{
        enum {value = n * Factorial<n-1>::value};
    };

    template<>
    struct Factorial<0>{
        enum {value = 1};
    };

}

#endif //EFFECTIVE_01_H
