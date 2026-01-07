#include <iostream>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
#include "clock.h"

class Shape{};
class Circle: public Shape{};
class RectAngle : public Shape{
public:
    void setDimension(double l, double w){
        length = l;
        width = w;
    }

    double getLength() const{
        return length;
    }

    double getWidth() const{
        return width;
    }

    double area() const{
        return length * width;
    }

    double perimeter() const{
        return 2*(width+length);
    }
    void print() const{
        std::cout << "width: " << width;
        std::cout << "length: " << length;
        std::cout << std::endl;
    };
    void test();
    RectAngle(){
        width = 0;
        length = 0;
    };
    RectAngle(double l, double w):width(w),length(l){};
private:
    double width;
    double length;
};

void RectAngle::test() {
    std::cout <<"test" << std::endl;
}

class Square : public RectAngle{};

class BoxType: public RectAngle{
public:
    void setDimension(double l, double w, double h);
    double getHeight() const  {return height;}
    double area() const;
    double volume() const;
    void print() const;
    BoxType();
    BoxType(double w, double l, double h);
private:
    double height;
};

void BoxType::print() const {
    RectAngle::print();
}

BoxType::BoxType() :height(0), RectAngle(0,0) {}

double BoxType::volume() const {
    return height * RectAngle::area();
}

double BoxType::area() const {
    return 2*(getLength() * getWidth()
              + getLength() * height
              + getWidth() * height
    );
}

BoxType::BoxType(double w, double l,double h):height(h), RectAngle(l,w) {}

class PersonType{
public:
    void print()const;
    void setName(string first, string last);
    PersonType& setFirstName(string first);
    PersonType& setLastame(string last);
    string getFristName()const;
    string getLastName()const;
    PersonType(string firstName="", string lastName="");
private:
    string lastName;
    string firstName;
};

class clsFriend;

class B{
public:
    int showAge(const clsFriend& cls);
};

class clsFriend{
public:
    clsFriend():_age(0){}
    clsFriend(int age):_age(age){}
    clsFriend(const clsFriend& cls):_age(cls._age){}
    clsFriend& operator=(int age){
        _age = age;
        return *this;
    }
    friend int showAge(clsFriend);
    friend class A;
    friend int B::showAge(const clsFriend&);
    int showAge(){return _age;}
private:
    int _age;
};

int B::showAge(const clsFriend &cls) {
    return cls._age;
}

class A{
public:
    A(){}
    A(int age);
    int showAge(const clsFriend& cls){return cls._age;}
    int showAge(){return _cls._age;}
private:
    clsFriend _cls;
};

A::A(int age) {
    _cls = age;
}

int showAge(clsFriend cls){

    clsFriend cls2(109);
    std::cout << cls2._age << std::endl;

    return cls._age;
}

template<typename T>
void printSecret(const T& t);

class Mystery{
    int secret = 42;
    template<typename T>
    friend void printSecret(const T& t){
        std::cout << " secret: " << t.secret << std::endl;
    }
};

#include <typeinfo>

class TestType{
public:
    TestType():_num(0){std::cout << "TestType() " << std::endl;}
    ~TestType(){std::cout << "~TestType()" << std::endl;}
    TestType(int i):_num(i){ std::cout << "TestType(int)" << std::endl;}
    TestType(const TestType& other):_num(other._num){std::cout << "TestType(const TestType&)" << std::endl;}
    int operator+(const TestType& other) const{
        return _num + other._num;
    }
    TestType& operator=(const TestType& other){
        std::cout << "TestType(const TestType&): " << typeid(other).name()<< std::endl;
        if (this == &other){
            return *this;
        }

        _num = other._num;
        return *this;
    }
private:
    int _num;
};

TestType func(const TestType& a, const TestType& b){
    TestType tmp = a + b;

    return tmp;
}

class maiev{
    virtual ~maiev() = 0;
};

class test{
public:
    test(int ma = 0):_ma(ma){std::cout << "test()" << std::endl;}
    test(const test&& t1):_ma(t1._ma){ std::cout << "test(const test&&)" << std::endl;}
    ~test() {std::cout << "~test()" << std::endl;}
    int operator()(){
        return _ma;
    }
    void show() const {std::cout <<"show()" << std::endl;}
private:
    friend ostream& operator<<(ostream& os, const test& t){
        os << t._ma;
        return os;
    }

    friend istream& operator>>(istream& is, test& t){
        is >> t._ma;
        return is;
    }
    int _ma;
};

template<typename T>
class myRAII{
public:
    myRAII(T* mt):_mt(mt){
    }
    ~myRAII(){
        delete _mt;
    }
    myRAII(T&& mt) = delete;
private:
    T *_mt;
};

void func(test *t) {
    throw string("123");
}
#include <memory>

class complexType{
    friend ostream& operator<<(ostream& os, const complexType& complex){
        os << "(";
        os << complex.realPart;
        os << ",";
        os << complex.imaginaryPart;
        os << ")";

        return os;
    }
    friend istream& operator>>(istream& is, complexType& complex){
        char ch;
        is >> ch;
        is >> complex.realPart;
        is >> ch;
        is >> complex.imaginaryPart;
        is >> ch;

        return is;
    }
public:
    complexType(){}
    complexType(double real, double image):realPart(real),imaginaryPart(image){
        std::cout << "complexType(double, double)";
        std::cout << "(" <<realPart <<","<< imaginaryPart <<")";
        std::cout << std::endl;
    }
    complexType(const complexType& other):realPart(other.realPart),imaginaryPart(other.imaginaryPart){
        std::cout << "complexType(const complexType&)";
        std::cout << "(" <<realPart <<","<< imaginaryPart <<")";
        std::cout << std::endl;
    }
    complexType operator+(const complexType& other){
        return complexType(realPart+other.realPart, imaginaryPart+other.imaginaryPart);
    }
    complexType operator*(const complexType& other){
        return complexType(realPart*other.realPart, imaginaryPart*other.imaginaryPart);
    }
    ~complexType(){
        std::cout << "~complexType()";
        std::cout << "(" <<realPart <<","<< imaginaryPart <<")" << std::endl;
    }
    bool operator==(const complexType& other){
        return realPart == other.realPart && imaginaryPart == other.imaginaryPart;
    }
    void setComplex(const double &real, const double& image){
        realPart = real;
        imaginaryPart = image;
    }
    void getComplex(double &real, double& image) const{
        real = realPart;
        image = imaginaryPart;
    }
private:
    double realPart;
    double imaginaryPart;
};

template<typename T>
void showFunc(T& t){
    std::cout << t << std::endl;
}

template<typename T>
T larger(T a, T b){
    return a > b;
}

#include <vector>
#include <array>
#include <optional>

template<typename elemType>
class listType{
public:
    bool isEmpty(){
        return length == 0;
    }
    bool isFull(){
        return length == maxLength;
    }
    void search(const elemType& searchItem, bool& found);
    void insert(const elemType& newElement);
    void remove(const elemType& removeElement);
    void destroyList();
    void printList();
    listType():length(0){}
    constexpr static int maxLength = 10;
private:
//    elemType list[maxLength];
    array<elemType, maxLength> list;

    vector<elemType> vc;

    int length;
};

template<typename elemType>
void listType<elemType>::search(const elemType &searchItem, bool &found) {
    auto it = std::find(list, list+length, searchItem);
    found = (it != list+length);
}

template<typename elemType>
void listType<elemType>::insert(const elemType &item) {
    if (isFull()){
        std::cout << "list full" << std::endl;
        return;
    }

    list[length++] = item;

//    list[length++] = new elemType(item);
}

template<typename elemType>
void listType<elemType>::remove(const elemType &item){
    bool found = false;
    search(item, found);
}

template<typename elemType>
void listType<elemType>::destroyList() {
    if (isEmpty()){
        std::cout << "empty" << std::endl;
        return;
    }

    length = 0;
}

template<typename elemType>
void listType<elemType>::printList() {
    for(int i = 0; i < length;i ++){
        std::cout << list[i] << std::endl;
    }
}

void sx(complexType( c)){
    std::cout << c << std::endl;
}

class mystery{
public:
    mystery(int mi = 0):i(mi){}
    void * operator new(size_t size){
        std::cout << "new:" << size << std::endl;
        void * my = malloc(size);
        return my;
    }

    void * operator new[](size_t size){
        std::cout << "new[]:" << size << std::endl;
        void * my = malloc(size);
        return my;
    }
    void operator delete[](void *ptr){
        std::cout << "delete[]" << std::endl;
        free(ptr);
    }

    void operator delete(void *my){
        std::cout << "delete" << std::endl;
        free(my);
    }
    ~mystery(){
        std::cout << "~my:" << i << std::endl;
    }
    void show(){std::cout << "i: " << i << std::endl;}
private:
    int i;
};

class vbase{
public:
    virtual void print() = 0;
};

class baseCls : vbase{
public:
    virtual void print();
    baseCls(int u = 0):x(u){}
    ~baseCls(){}
private:
    int x;
};

void baseCls::print() {
    std::cout << "base::print " << x << std::endl;
}

class derivedCls : public baseCls{
public:
    void print();
    derivedCls(int u = 0, int v = 0):a(v), baseCls(u){}
    ~derivedCls(){}
private:
    int a;
};

void derivedCls::print() {
    std::cout << "derived::print " << a << std::endl;
}

void print(baseCls base){
    base.print();
}

//template<typename T>
//class myIterator{
//public:
//    using value_type = T;
//    using reference  = T&;
//    using pointer = T*;
//    using difference_type = ptrdiff_t;
//    using iterator_category = input_iterator_tag;
//
//    value_type operator*();
//    value_type operator->();
//    reference operator()(int i);
//    reference operator++();
//    reference operator++(int i);
//    reference operator--();
//    reference operator=(reference);
//    bool operator==(reference);
//    bool operator<(reference);
//    pointer begin();
//    pointer end();
//    pointer rbegin();
//    pointer rend();
//};

#include "sample.h"
#include "polynomialType.h"

#include <vector>

int func(const int& pa){
    int b = 20;
    return pa;
}

int* func(){
    int *pa = new int(10);
    return pa;
}


int showA(int* a){
    cout << "(int*)a->" << *a << endl;
    return *a;
}

int showA(const int& a){
    cout << "(int&)a->" << a << endl;
    const int b = 100;
    return b;
}

template<typename T>
T showA(T& a){
    cout << "(T&)a->" << a << endl;
    return a;
}
template<>
double showA(double& a){
    cout << "hello world: " << a << endl;

    return 1.01;
}

#include <iterator>
#include <deque>
#include "course.h"
#include <fstream>

#include "../web/Application.h"
#include "../web/Http.h"
#include "entity/User.h"
#include "entity/Money.h"
#include "Pool.h"

template<typename T, typename U= double>
struct MyType{
public:
    MyType();
    pair<T, U> getType();
};

template<typename T, typename U>
MyType<T,U>::MyType(){
    std::cout<< "MyType()" << std::endl;
}

template<typename T, typename U>
pair<T,U> MyType<T,U>::getType(){
    return make_pair(T(), U());
}

// 👇 你的特化版本
template<>
struct MyType<int, int> {
public:
    MyType();
    void getType();
};

MyType<int, int>::MyType() {
    std::cout << "MyType<int,int>" << std::endl;
}

void MyType<int, int>::getType() {
    std::cout << "MyType<int,int>::getType()" <<std::endl;
}

template<typename T>
struct MyType<T, int>{
public:
    MyType();
    void getType();
};

template<typename T>
MyType<T, int>::MyType() {
    std::cout << "MyType<int,int>" << std::endl;
}

template<typename T>
void MyType<T,int>::getType() {
    std::cout << "MyType<int,int>::getType()" <<std::endl;
}

//template<>
//struct MyType<int,int>{
//public:
//    MyType();
//    void getType();
//};
//
//template<>
//MyType<int,int>::MyType(){
//    cout << "Mytype<int,int>" << std::endl;
//}
//
//template<>
//void MyType<int,int>::getType(){
//    std::cout << "MYtype<int,int>::getType()" << std::endl;
//}

#include "CTest.h"
#include "../study/array.h"
#include "Vector.h"
#include <forward_list>
#include <fstream>
#include <stdexcept>
#include <cstdint>
#include <type_traits>

class MessageBuf{
public:
    template<typename T>
    void write(const T& value){
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&value);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(T));
    }
   template<typename T>
    T read(){
       T value;
       memcpy(&value, buffer.data() + readPos, sizeof(T));
       readPos += sizeof(T);

       return value;
    }
    template<typename T>
    T read(size_t readPos){
        T value;
        memcpy(&value, buffer.data() + readPos, sizeof(T));

        return value;
    }
    void reset(){
        buffer.clear();
    }

    size_t position()const{
        return readPos;
    }

    size_t remaining() const{
        return buffer.size() - readPos;
    }
private:
    std::vector<uint8_t> buffer;
    int readPos = 0;
};

class Buff{
public:
    Buff():mAge(0){}
    Buff(int age):mAge(age){}
    Buff(const Buff& b1){
        Buff(b1.mAge);
    }
    Buff operator=(const Buff& bf){
       Buff(bf.mAge);
    }

//    void serialize(MessageBuf& buff)const{
//        buff.write(mAge);
//    }

//    size_t serialize(MessageBuf& buff)const{
//        buff.write(mAge);
//        return buff.position();
//    }
//
//    void deserialize(MessageBuf& buff, size_t pos){
//        int age = buff.read<int>(pos);
//        std::cout << age << std::endl;
//    }

//    void deserialize(MessageBuf& buff){
//        int age = buff.read<int>();
//        std::cout << age << std::endl;
//    }
private:
    int mAge;
};

struct Message{
    uint8_t  type;
    std::string payload;

    Message(uint8_t t, const std::string& p): type(t), payload(p){}
};

class Protocol{
public:
    static std::vector<uint8_t> encode(const Message& msg){
        std:vector<uint8_t > buffer;
        buffer.push_back(msg.type);

        uint32_t len = msg.payload.size();
        for(int i = 0; i < 4; i++){
            buffer.push_back((len >> (8 * (3 - i))) & 0xFF);
        };

        buffer.insert(buffer.end(), msg.payload.begin(), msg.payload.end());
    }

    static Message decode(const std::vector<uint8_t>& raw){
        uint8_t  t = raw.at(0);
        uint32_t len = 0;

        for(int i = 0 ; i < 4; ++i){
            len = (len << 8) | raw[i + 1];
        }

        std::string payload(raw.begin() + 5, raw.begin() + 5 + len);

        return Message(t, payload);
    }
};

#include <bitset>
#include <thread>

//class Int{
//public:
//    Int(int x): mx(x){};
//    int show()const{
//        ++mx;
//        return mx;
//    }
//private:
//    mutable int mx;
//};

#include <sstream>
#include <string>

namespace maiev1{
    class Stu{
    public:
        Stu(int no, string name, int age, int grade,double money):
        mNo(no), mAge(age), mGrade(grade), mName(name),mMoney(money) {}
        Stu(): mAge(0), mGrade(0), mName(""){}
        bool cmp(const Stu& other){
            return mGrade > other.mGrade;
        }

        void setAge(int age){
            mAge = age;
        }
        void setName(string name){
            mName = name;
        }
        void setGrade(int grade){
            mGrade = grade;
        }
        void setNo(int no){
            mNo = no;
        }

        string toString()const{
           std::ostringstream oss;
           oss << mGrade << " " << mName << " " << mAge;

           return oss.str();
        }

        friend std::ostream& operator<<(std::ostream& os, const Stu& other){
            os << other.mGrade << " " <<  other.mName << " " << other.mAge;
            return os;
        }
    private:
        void _xx(string str){
             str.find(" ");
        }
        int mAge;
        string mName;
        int mGrade;
        int mNo;
        double mMoney;
    };
}

namespace maiev1{
    int age = 10;
    class Base{
    public:
        Base(int m): m1(m){ std::cout << "Base(int)" << std::endl;}
        virtual void pr(){
            std::cout << "Base::pr()" << std::endl;
        }

        void pr(int){
            std::cout << "Base::pr(int)" << std::endl;
        }

        virtual ~Base(){
            std::cout << "~Base()" << this << m1 << std::endl;
        }
    private:
        int m1;
    };
    class Derived : public Base{
    public:
        Derived(int m):Base(m), m2(m){std::cout << "Derived(int)" << std::endl;}
        void pr(){
            std::cout << "Derived::pr()" << std::endl;
        }

        virtual ~Derived(){
            std::cout << "~Derived()"  << m2 << this << std::endl;
        }
    private:
        int m2;
    };

    class Third : public Derived, public virtual Base{
    public:
        Third(int m): Base(m), m3(m), Derived(1){std::cout<< "Third(int)"<< std::endl;}
        void pr(){
            std::cout << "Third::pr()" << std::endl;
        }
        ~Third(){
            std::cout << "~Third()" << this << m3 << std::endl;
        }
    private:
        int m3;
    };
}

class xx{
public:
    int show(){return 1;}
private:
    int a = 42;
};

#include <cstddef>

class Leg{
public:
    Leg(){}
    Leg(int num):mNum(num){}
    void operator=(const Leg& leg){
        mNum = leg.mNum;
    }
    int show(){
        return mNum;
    }
private:
    int mNum;
};

class Face{
public:
    Face(){}
    Face(string name):mName(name){}
    void operator=(const Face& face){
        mName = face.mName;
    }
    string show(){
        return mName;
    }
private:
    string mName;
};

class Person{
public:
    Person(){}
    Person(Leg _leg, Face _face):leg(_leg),face(_face){}
    Person setLeg(const Leg& _leg){
        leg = _leg;
        return *this;
    }
    Person setFace(const Face& _face){
        face = _face;
        return *this;
    }
    void show(){
        std::cout << "Person has Face: " << face.show()
                << " and Leg:" << leg.show()
                << std::endl;
    }
    ~Person(){}
private:
    Leg leg;
    Face face;
};

class Animal{
public:
    Animal(){}
    Animal setLeg(const Leg& _leg){
        leg = _leg;
        return *this;
    }
    Animal setFace(const Face& _face){
        face = _face;
        return *this;
    }
    void show(){
        std::cout << "Animal has " << face.show() << " and leg:" << leg.show() << std::endl;
    }
    ~Animal(){}
private:
    Leg leg;
    Face face;
};

template<typename T, typename U>
struct HasFace{
    static constexpr bool value = false;
};

template<typename T>
struct HasFace<T,Face>{
    static constexpr bool value = true;
};

template<typename T>
struct HasLeg{
private:
    template<typename U>
    static auto test(int) -> typename std::enable_if< std::is_same<decltype(std::declval<U>().leg) ,Leg>::value, std::true_type>::type;

    template<typename U>
    static constexpr std::false_type test(...);
public:
    static constexpr bool value = decltype(test<T>(0))::value;
};

struct A1{
};

class B1{
public:
    B1(int i=0):m1(i){}
    void show(){
        std::cout << "B1::show()" << std::endl;
    }
    ~B1(){std::cout << "~B1()" << this << " " << m1 << std::endl;}
private:
    int m1;
};
class B2{
public:
    B2(int i=0):m1(i){}
    void show(){
        std::cout << "B2::show()" << std::endl;
    }
    ~B2(){std::cout << "~B2()" << this << " " << m1 << std::endl;}
private:
    int m1;
};

#include <memory>
#include <functional>

void func(int, int){
}

struct foo{
    int f_count;
    pthread_mutex_t  f_lock;
    int f_id;
};

struct foo* foo_alloc(int id){
    struct foo* fp;
    if ((fp=(struct foo*)malloc(sizeof(struct foo))) != nullptr){
       fp->f_count = 1;
       fp->f_id = id;

       if (pthread_mutex_init(&fp->f_lock, nullptr) != 0){
            free(fp);
            return nullptr;
       }

       return fp;
    }
}

void foo_hold(struct foo* fp){
    pthread_mutex_lock(&fp->f_lock);
    fp->f_count += 1;
    pthread_mutex_unlock(&fp->f_lock);
}

void foo_rele(struct foo* fp){
    pthread_mutex_lock(&fp->f_lock);
    if (--fp->f_count == 0){
        pthread_mutex_unlock(&fp->f_lock);
        pthread_mutex_destroy(&fp->f_lock);
        free(fp);
    }else{
        pthread_mutex_unlock(&fp->f_lock);
    }
}

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex countMutex;

void verifyOrder(int orderId){
    std::lock_guard<std::mutex>lock(countMutex);
    std::cout << "order: " << orderId << "verify by thread-A!" << pthread_self() << std::endl;
}

void packOrder(int orderId){
    std::lock_guard<std::mutex>lock(countMutex);
    std::cout << "order: " << orderId << "packed by thread-B!" << pthread_self() << std::endl;
}

void shipOrder(int orderId){
    std::lock_guard<std::mutex>lock(countMutex);
    std::cout << "order: " << orderId << "shiped by thread-C!" << pthread_self() << std::endl;
}

void processOrder(int orderId){
    std::thread t1(verifyOrder, orderId);
    std::thread t2(packOrder, orderId);
    std::thread t3(shipOrder, orderId);

    t1.join();
    t2.join();
    t3.join();
}

#include <bitset>
#include <numeric>
template <typename T>
class Pro{
public:
    T operator()(T a, T b){
        return a + b;
    }
};

template <typename T>
class Proy{
public:
    bool operator()(T a){
        return static_cast<int>(a) > 10;
    }
};

namespace x1{
    struct Pos{
        int x;
        int y;
        Pos(int mx, int my): x(mx),y(my){}
        string to_string(){
            ostringstream os;
            os << "x = " << x << "and y = " << y;
            return os.str();
        }
    };

    struct PosCriterion{
        bool operator()(const Pos& p1, const Pos& p2)const{
            return (p1.x) > (p2.x);
        }
    };
}

using namespace x1;

template<typename T>
class Seq{
public:
    Seq(T v): val(v){}
    T operator()(){
        return val++;
    }
private:
    T val;
};

class MeanValue{
public:
    MeanValue():sum(0),num(0){}
    long operator()(int elem){
        ++num;
        sum += elem;
    }

    double value(){
        return static_cast<double>(sum) / static_cast<double>(num);
    }

private:
    long sum;
    long num;
};

namespace x1{
    template<typename T>
    class GreaterThan : public std::unary_function<T,T>{
    public:
//        using argument_type = T;
        GreaterThan(T mv): val(mv){}
        bool operator()(T elem)const{
            return elem > val;
        }
    private:
        T val;
    };
//    template<typename T>
//    class GreaterThan {
//    public:
//        using argument_type = T; // 关键补充！
//
//        GreaterThan(T t) : threshold(t) {}
//
//        bool operator()(T value) const {
//            return value > threshold;
//        }
//    private:
//        T threshold;
//    };
}
namespace x1{
    template<typename T>
    struct GG{
        GG(int mv) : val(mv){
        }
        int operator()(int elem){
            elem *= val;
        }
        int val;
    };
}

namespace x1{
    void xx(int ){
        std::cout << "xx(int)" << std::endl;
    }

    struct xa{
        void xx(){
            std::cout << "xa::xx()" << std::endl;
        }
        void xx(int){
            std::cout << "xa::xx(int)" << std::endl;
        }
    };

    void xx(xa){
        std::cout << "xx(xa)" << std::endl;
    }
}

void pxy(int){
    std::cout << "pxy(int)" << std::endl;
}

class Printer{
public:
    void print()const{
        std::cout << "print()" << std::endl;
    }
    void print(const string& msg )const{
        std::cout << "print(string)" << std::endl;
    }
    void print(int a){
        ma = a;
        std::cout << "print(int)" << std::endl;
    }
private:
    int ma;
};

struct Multiply {
    int operator()(int a, int b) const {
        return a * b;
    }
};

#include <functional>
#include <list>
#include <forward_list>
#include <iterator>

void pr(const int* pa){
    std::cout << pa << std::endl;
}

template<typename T>
class Int{
public:
    Int(std::shared_ptr<T> pa):_pa(pa){}
    T& show(){
        return *_pa;
    }

    ~Int(){
        std::cout << "~Int()" << std::endl;
    }

    friend ostream& operator<<(ostream& os, const Int& other){
        os << &other;
        return os;
    }
private:
    shared_ptr<T> _pa;
};

template<typename T>
class Mode{
public:
    Mode() = default;
    Mode(T* p):_p(p){}
    T show() const{
        return *_p;
    }
    ~Mode(){
        delete _p;
    }
private:
    T* _p;
};

template<>
class Mode<int> : public std::enable_shared_from_this<int> {
public:
    Mode(std::shared_ptr<int> p) : _p(std::move(p)) {}
    int show() const { return *_p; }
private:
    std::shared_ptr<int> _p;
};

template<>
class Mode<CTest> : public std::enable_shared_from_this<CTest> {
public:
    Mode(std::shared_ptr<CTest> p) : _p(std::move(p)) {}
    CTest show() const { return *_p; }
private:
    std::shared_ptr<CTest> _p;
};

const shared_ptr<CTest> abc(){
    return make_shared<CTest>(20);
}

CTest abc(int){
    return CTest(20);
}

class Int2{
public:
    Int2() = default;
    Int2(weak_ptr<int> pa) :_pa(pa){}
    int show(){
        auto a = _pa.lock();
        return *a;
    }

    void operator+(){
        auto a = _pa.lock();
    }

    Int2 operator=(const Int2& other){
        if (&other == this){
            return *this;
        }
        _pa = other._pa;
    }

    ~Int2(){
        std::cout << "~Int2()" << this << ":" << _pa.lock() << std::endl;
    }
private:
    std::weak_ptr<int> _pa;
};

#include <thread>
#include <mutex>

int g_num = 0;
std::mutex g_mutex;

void show_increment(int id){
    for(int i= 0; i < 3; i++){
        g_mutex.lock();
        ++g_num;
        std::cout << std::this_thread::get_id() <<": " <<  id << "=>" << g_num << std::endl;
        g_mutex.unlock();

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

class Parent{
public:
    virtual void virtualFunc() = 0;
    void helper(){
        virtualFunc();
    }
    virtual ~Parent(){
        helper();
    }
};

class Child : public Parent{
public:
    void virtualFunc(){
        cout << "child" << std::endl;
    }

    virtual ~Child(){}
};

class Xyz{
public:
    Xyz() = default;
    Xyz(const Xyz& other){std::cout << "copy ctor" << std::endl;}
    Xyz& operator=(const Xyz& other){std::cout << "assign ctor" << std::endl;}
    ~Xyz(){
        std::cout << "~Xyz()" << std::endl;
    }
};

#include <cstdarg>
#include <iostream>
void simple_printf(const char* fmt, ...){
    va_list args;
    va_start(args, fmt);

    while (*fmt != '\0')
    {
        std::cout << "*fmt: " << *fmt << std::endl;
        if (*fmt == 'd')
        {
            int i = va_arg(args, int);
            std::cout << i << '\n';
        }
        else if (*fmt == 'c')
        {
            // note automatic conversion to integral type
            int c = va_arg(args, int);
            std::cout << static_cast<char>(c) << '\n';
        }
        else if (*fmt == 'f')
        {
            double d = va_arg(args, double);
            std::cout << d << '\n';
        }
        ++fmt;
    }

    va_end(args);
}

struct Foo{
    int n;
};

bool operator==(const Foo& lhs, const Foo& rhs){
    return lhs.n == rhs.n;
}

bool operator<(const Foo& lhs, const Foo& rhs){
    return lhs.n < rhs.n;
}

int* sum(){
//    int* pa = new int(10);
//    return pa;
    return new int(20);
}

int sum(int &a){
    a = 20;

    return a;
}

bool myPredicate(int i, int j){
    return (i==j);
}

int* xyz(const void* y){
    int ab = 10;
    std::cout << &ab << std::endl;
    auto py = const_cast<void*>(y);
//    return static_cast<int*>(py);
    return &ab;
}

template<typename T>
struct hasComp{
    static constexpr bool value = false;
};

struct MM;

template<>
struct hasComp<MM>{
    static constexpr bool value = true;
};

template<typename T>
class CompareAble{
public:
    virtual bool lt(const T& a) const = 0;
    virtual bool gt(const T& a) const = 0;
    virtual bool eq(const T& a) const = 0;
    virtual ~CompareAble() = default;
};
template<typename T>
struct NoCopyAble{
    NoCopyAble() = default;
    ~NoCopyAble() = default;
    NoCopyAble(const NoCopyAble<T>&) = delete;
    NoCopyAble& operator=(const NoCopyAble<T>&) = delete;
};

template<typename T>
class CopyAble{
};

namespace maiev1206{
    class A1 : public NoCopyAble<A1>{
    public:
        A1(){
            std::cout << "A1()" << std::endl;
        }
        ~A1(){
            std::cout << "~A1()" << std::endl;
        }
    };

    class B1 : public CopyAble<B1>{
    public:
        B1(){
            std::cout << "B1()" << std::endl;
        }
        ~B1(){
            std::cout << "~B1()" << std::endl;
        }
    };
}

class Complex : public CompareAble<Complex>{
public:
    Complex() = default;
    Complex(double i1, double i2):mI1(i1), mI2(i2){
        std::cout << "complex(double, double)" << std::endl;
    }
    Complex& operator=(const Complex& other){
        std::cout << "operator=" << std::endl;
        if (this == &other){
            std::cout << "the same" << std::endl;
            return *this;
        }
        mI1 = other.mI1;
        mI2 = other.mI2;

        return *this;
    }
    Complex(const Complex& other){
        std::cout << "complex(const complex&)" << std::endl;
        mI1 = other.mI1;
        mI2 = other.mI2;
    }
    ~Complex(){std::cout << "~Complex()" << std::endl;}
    friend ostream& operator<<(ostream& os, const Complex& other){
        os << other.mI1 << other.mI2;
        return os;
    }
    bool operator==(const Complex& other){
        return mI1 == other.mI1 && mI2 == other.mI2;
    }
    bool lt(const Complex& other) const {
        return mI1 < other.mI1;
    }
    bool gt(const Complex& other) const {
        return mI1 > other.mI1;
    }
    bool eq(const Complex& other) const {
        return mI1 == other.mI1 && mI2 == other.mI2;
    }
private:
    double mI1; //实部
    double mI2; //虚部
};

template<>
struct hasComp<Complex>{
    static constexpr bool value = true;
};

template<typename T>
void showComplex(const T& o){
    std::cout << o << std::endl;
}

namespace x1206{
    class A{
    public:
        int ma;
        A(int v = 0) : ma(v){}
        void showA(){
            std::cout << "ma in A: " << ma << std::endl;
        }
    };
    class B: virtual public A{
    public:
        int mb;
        B(int v = 0, int u = 0) : A(v), mb(u){}
        void showB(){
            std::cout << "ma in B: " << ma << std::endl;
            std::cout << "mb in B: " << mb << std::endl;
        }
    };
    class C: virtual public A{
    public:
        int mc;
        C(int v = 0, int u = 0) : A(v), mc(u){}
        void showC(){
            std::cout << "ma in C: " << ma << std::endl;
            std::cout << "mc in C: " << mc << std::endl;
        }
    };
    class D: public B, public C{
    public:
        int md;
        D(int u = 0, int v = 0, int w = 0) : A(u+v+w), C(u, u), B(v, v), md(w){}
        void showD(){
            std::cout << "ma in D: " << ma << std::endl;
            std::cout << "mb in D: " << mb << std::endl;
            std::cout << "mc in D: " << mc << std::endl;
            std::cout << "md in D: " << md << std::endl;
        }
    };
}

int main(){
    {
        {
            maiev1206::A1 a1;
//        maiev1206::A1 a2(a1);
//        maiev1206::A1 a3 = (a1);

            maiev1206::B1 b1;
            maiev1206::B1 b2(b1);
            maiev1206::B1 b3 = b1;
        }

        x1206::D d(1,2,3);
        d.showA();
        d.showB();
        d.showC();
        d.showD();

        bool constexpr a = hasComp<Complex>::value;
        std::cout << a << std::endl;

        vector<Complex> vc{{1,2}, {1,1}, {3,1}};
        Complex target(3,1);

        auto it = std::find(vc.begin(), vc.end(),target);
        std::cout << *it << std::endl;

        Complex c1(1,2);
        Complex c2(2,1);
        if (c1.eq(c2)){
            std::cout << "c1 eq c2" << std::endl;
        }else if (c1.lt(c2)){
            std::cout << "c1 < c2" << std::endl;
        }else if (c1.gt(c2)){
            std::cout << "c1 > c2" << std::endl;
        }
    }

    {
//        int a1 = 10;
//        int* result = xyz(&a1);
//        std::cout << result << std::endl;
//
//        std::cout << "------------"  << std::endl;
//
//        vector<int> vc{1,2,3,4,5,6,7,8};
//        vector<int> vc2{1,2,3,9,5,6,7,10};
//        auto minvc = std::min(1,1);
//        auto m1 = std::min_element(vc.begin(), vc.end());
//        std::cout << *m1 << std::endl;
//        std::cout << minvc << std::endl;
//
//        auto x = std::mismatch(vc2.begin(), vc2.end(),vc.begin());
//
//        auto a = x.first;
//        auto b = x.second;
//
//        ++x.first;
//        ++x.second;
//
//        auto y = std::mismatch(x.first, vc2.end(), x.second, myPredicate);
//        auto c = y.first;
//        auto d = y.second;

//        int a = 10;
//        int b = 20;
//
//        const int *pa = &a;
//        const int* &ra = pa;
//
//        int * const pc = &a;
//        int * const &rc = pc;
//
//        int * pb = &a;
//        int * const &rd = pb;
//
//        std::cout << pc << std::endl;
//        std::cout << rc << std::endl;

//        const int &ra = a;
//        int const &rb = b;
//
//        const int* &rra = pa;
//        int * &rrb = pb;
//
//        std::cout << pb << std::endl;
//        std::cout << rrb << std::endl;
//
//        rrb = new int(20);
//
//        std::cout << pb  << " "  << *pb << std::endl;
//        std::cout << rrb << " " << *rrb << std::endl;


//        std::cout << "pa: " << pa << std::endl;
//        std::cout << "*pa: " << *pa << std::endl;
//
//        pa = &b;
//        std::cout << "pa: " << pa << std::endl;
//        std::cout << "*pa: " << *pa << std::endl;

//        Int<int> i1(make_shared<int>(10));
//        std::cout << i1.show() << std::endl;

//        Foo f1{1};
//        Foo f2{2};
//
//        using namespace std::rel_ops;
//        std::cout << std::boolalpha
//            << "{1} != {2}: " << (f1 != f2) << '\n'
//                << "{1} > {2}: " << (f1 > f2) << '\n'
//                << "{1} <= {2}: " << (f1 <= f2) << '\n'
//                << "{1} >= {2}: " << (f1 >= f2) << '\n';
//        simple_printf("dfcf", 3, 1.11,'a', 42.5f);
//        Xyz x1;
//        Xyz x2(x1);
//        Xyz x3;
//        x3 = x1;
//
//        return 0;

//        std::thread t1(show_increment, 1);
//        std::thread t2(show_increment, 2);
//        t1.join();
//        t2.join();

//        auto s1 = abc();
//        shared_ptr<CTest> c1 = make_shared<CTest>(abc());
//        std::cout << "----------" << std::endl;
    }
//    {
//        CTest c{abc(0)};
//        std::cout << "----------" << std::endl;
//    }

    {
//        Mode<int> m1(make_shared<int>(10));
//        Mode<int> m2(make_shared<int>(10));
//        Mode<CTest> m3(make_shared<CTest>(30));
//        std::cout << "m1: " << m1.show() << std::endl;
//        std::cout << "m2: " << m2.show() << std::endl;
//        std::cout << "m3: " << m3.show() << std::endl;

//        int b = 20;
//        int *pb = &b;
//
//        Mode<int> m2(new int(20));
//        std::cout << m2.show() << std::endl;

//        CTest c1(10);
//        CTest c2;
//        c2 = c1;
//        CTest c3(c2);
//
//        std::cout << "c1" << c1 << std::endl;
//        std::cout << "c2" << c2 << std::endl;
//        std::cout << "c3" << c3 << std::endl;
//
//        std::cout << "--------" << std::endl;
    }

//    int *pa = new int(100);
//    std::cout << "pa:" << pa << std::endl;
//    {
//        std::cout << "------------" << std::endl;
//        shared_ptr<CTest> s1(new CTest(1));
//        shared_ptr<CTest> s2(make_shared<CTest>(10));
//        std::cout << "------------" << std::endl;
//        Int<CTest> ci(s1);
//        std::cout << "show: " << ci.show() << std::endl;
//        std::cout << "------------" << std::endl;
//    }

//    {
//        std::cout << "------------" << std::endl;
//        shared_ptr<int> s1(make_shared<int>(10));
//        Int<int> i1(s1);
//        std::cout << i1.show() << std::endl;
//    }
//
//    {
//        std::cout << "------------" << std::endl;
//        shared_ptr<int> s1(pa);
//        {
//            weak_ptr<int> w1(s1);
//            auto w = w1.lock();
//            std::cout << "w1:" << w << std::endl;
//
//            shared_ptr<int>s2(w1);
//
//            std::cout << "s2:" << s2 << std::endl;
//        }
//
//        Int2 i2(s1);
//        std::cout << "s1:" << s1 << std::endl;
//
//        i2.operator+();
//
//        std::cout << "pa:" << *pa << std::endl;
//    }

//    Int2 i2(s1);
//    Int2 i1;
//    i1 = i2;
//
//    i1.operator+();

//    std::cout << i1.show() << std::endl;
//    std::cout << i2.show() << std::endl;


//    int a = 10;
//    int *pa = new int(100);
//
//    std::cout << pa << std::endl;
//    pr(pa);
//
//    Int ia(pa);
//    std::cout << ia.show() << std::endl;
//
//    *pa = 100;
//    std::cout << ia.show() << std::endl;

}

#ifdef TRUE
int main(){

    vector<int> vc(10,0);
    back_inserter(vc) = 22;
//    front_inserter((vc)) = 11;

    std::cout << vc.at(0) << std::endl;
    std::cout << vc.at(vc.size() - 1) << std::endl;

    std::forward_list<int> first;
    std::forward_list<int> second(3, 77);
    std::forward_list<int> third(second.begin(), second.end());
    std::forward_list<int> four(third);
    std::forward_list<int> five(std::move(four));
    std::forward_list<int> sixth = {1,2,3,5};

    std::cout << "first:" ; for(int& x : first) std::cout << " " << x; std::cout << '\n';
    std::cout << "second:"; for (int& x : second) std::cout << " " << x; std::cout << '\n';
    std::cout << "third:";  for(int& x : third) std::cout << " " << x; std::cout << '\n';
    std::cout << "four:";   for(int& x : four) std::cout << " " << x; std::cout << '\n';
    std::cout << "five:";   for(int& x : five) std::cout << " " << x; std::cout << '\n';
    std::cout << "six:";    for(int& x : sixth) std::cout << " " << x; std::cout << '\n';

    std::cout << "---------" << std::endl;

    list<int>col1{1,2,3,4,5,6,7,8,9,10};
    list<int>::iterator pos;
    int count = 0;
    pos = std::remove_if(col1.begin(), col1.end(),
                    [count](int) mutable{
        return ++count == 3;
    });

    std::cout << *pos << std::endl;

    col1.erase(pos,col1.end());
    for(int _a : col1){
        std::cout << _a;
    }
    std::cout << std:: endl;

//    Printer p;
//    auto f = std::mem_fn(static_cast<void(Printer::*)(int)>(&Printer::print));
//    f(p, 10);
}

int main(){
    if (0){
        using pf = void(*)(int);
        pf ppf = pxy;
        ppf(123);

        auto ppxx = std::bind(static_cast<void(x1::xa::*)(int)>(&x1::xa::xx), std::placeholders::_1, 10);

//    auto pzf = pxy;
//    pzf(123);

        std::cout << "---------" << std::endl;

        Multiply m;
        auto fm = std::bind(m, std::placeholders::_1, std::placeholders::_2);
        std::cout << fm(1,2) << std::endl;

        Printer pp;

        auto f1 = std::bind(static_cast<void(Printer::*)() const>(&Printer::print), &pp);
        auto f2 = std::bind(static_cast<void(Printer::*)(const string&) const>(&Printer::print), &pp, std::placeholders::_1);

        auto f3 = [&pp](int){pp.print(10);};
        f1();
        f2("hello bind!!");
        f3(100);

        equal_to<int> equalTo;

        auto c = std::not2(equal_to<int>());
        std::cout << c(5, 5) << std::endl;
        std::cout << c(5, 1) << std::endl;

        auto p1 = std::bind(plus<int>(), placeholders::_1, placeholders::_1);
        std::cout << p1(11) << std::endl;

        auto pow = std::bind(std::multiplies<int>(), placeholders::_1,
                             std::bind(std::plus<int>(), placeholders::_1,placeholders::_2));
        std::cout << pow(2, 1) << std::endl;


//    auto b = std::not1(GreaterThan<int>(10));
//    auto gl = std::bind(std::greater<int>(), std::placeholders::_1, 10);
//    auto b = std::not1(gl);
//    std::cout << b(5) << std::endl;

        std::cout << "-------" << std::endl;

        std::vector<int> vc;
        std::vector<int> vc2;
        vc.resize(10);
        vc2.resize(10);

        generate(vc.begin(), vc.end(), Seq<int>(1));
//    generate_n(back_inserter(vc2),5, Seq<int>(20));


        //Unary, Binary
        auto c1 = std::count_if(vc.begin(), vc.end(), GreaterThan<int>(10));
        std::cout << " vc begin > 5 has : " << c1 << std::endl;

        auto p = for_each(vc.begin(), vc.end(), [](int elem){
            std::cout << elem << std::endl;
        });
        std::cout << p << std::endl;

        std::transform(vc.begin(), vc.end(), vc2.begin(), GG<int>(2));
        MeanValue mv = for_each(vc2.begin(), vc2.end(), MeanValue());

        vector<int> vc3(10);
        std::transform(vc.begin(), vc.end(), vc2.begin(), vc3.begin(), std::plus<int>());

        std::cout << "-----------" << std::endl;
        std::cout << mv.value() << std::endl;

        Pos p1(1,2);
        Pos p2(2,3);

        set<Pos, PosCriterion> s1{p1, p2}; //逆序！！

        for(auto p : s1){
            std::cout << p.to_string() << std::endl;
        }

        bool big10 = Proy<double>()(10.000000000000000000000001);
        std::cout << big10 << std::endl;

        vector<int> vc{1,2,3,4,5};
        std::cout << accumulate(vc.begin(), vc.end(), 0) << std::endl;
        std::cout << accumulate(vc.begin(), vc.end(), 10, Pro<int>()) << std::endl;


        cout << "267 as binary short: "
             << bitset<numeric_limits<unsigned short>::digits>(267)
             <<endl;

        cout << "267 as binary long: "
             << bitset<numeric_limits<unsigned long>::digits>(267)
             <<endl;

        cout << "10000000 with 24 bits : "
             << bitset<24>(1e7)
             <<endl;

        string s = bitset<42>(12345678).to_string();
        cout << "12,345,678 with 42 bits: " <<  s << endl;

        cout << "\"1000101011\" as number:"
             << bitset<100>("1000101011").to_ullong() << endl;

        enum color{red,yellow,green,blue,white,black,numColors};
        bitset<numColors> usedColors;
        usedColors.set(red);
        usedColors.set(blue);

        cout << "bitfield of used colors:" << usedColors << endl;
        cout << "num of used colors:" << usedColors.count() << endl;
        cout << "bitfield of unused colors:" << ~usedColors << endl;

        if (usedColors.any()){
            std::cout << "used color:";
            for(int c = 0; c < numColors; ++c){
                if (usedColors[(color)c]){
                    std::cout << " " << c;
                }
            }

            cout << endl;
        }
    }
}


int main(){
    int * pa = new int();
    shared_ptr<int> s1(pa);

    *s1 = 20;
    shared_ptr<int> s2(s1);

    std::cout << s1.use_count() << std::endl;
    s2.reset();
    std::cout << s1.use_count() << std::endl;
    s1.reset();

    weak_ptr<int> w1(s1);
    weak_ptr<int> w2(s2);

    if (s1.use_count() != 0){
        std::cout << *s1 << std::endl;
    }

    if (auto locked = w2.lock()){
        std::cout << "has resouces" << *locked << std::endl;
    }else{
        std::cout << "no resouces" << std::endl;
    }

    if (!w1.expired()){
        std::cout << "no" << std::endl;
    }else{
        std::cout << "yes" << std::endl;
    }
}

int main() {
    {
        std::vector<int> orderId{101, 102, 103};
        for(auto & id : orderId){
            processOrder(id);
        }
    }
    vector<shared_ptr<string>> vc;
    shared_ptr<string> s1(new string("hello world"));
    vc.push_back(s1);

    s1 = make_shared<string>("can can help");
    vc.push_back(s1);
    std::cout << s1.use_count() << std::endl; // 2 s1, vc1

    weak_ptr<string> s2(s1);
    std::cout << s2.use_count() << std::endl; //s1,vc1

//    for(auto& tmp : vc){
//        std::cout << tmp->data() << " : " << tmp.use_count() << std::endl;
//    }

//    weak_ptr<string> w1(s1);
//    weak_ptr<string> w2(s2);

//    std::cout << "------" << std::endl;
//    auto ap = new string("xxyz");
//    shared_ptr<string> pp(ap);
//    vc.push_back(pp);

    {
        std::cout << HasFace<Person, Face>::value << std::endl;
        std::cout << HasFace<Person, Leg>::value << std::endl;

        Person person;
        Animal animal;

        Leg leg1(3);
        Leg leg2(2);

        Face face1("p1");
        Face face2("p2");

        person.setLeg(leg1).setFace(face1).show();
        animal.setLeg(leg2).setFace(face2).show();
    }

    {
        xx x1;
        std::cout << sizeof(xx) << std::endl;
        std::cout << sizeof(x1) << std::endl;
                  x1.show();
//        maiev1::Third th(3);
//        maiev1::Third th0(4);
//
//        th.pr();
//        th0.pr();

//        maiev1::Base *pb = new maiev1::Base();
//        maiev1::Derived *pd = new maiev1::Derived();

//        pb = pd;
//        pb->pr();
//        pb->pr(1);

//        std::cout << "------------" << std::endl;
//
//        maiev1::Base b;
//        maiev1::Derived d;

//        b.pr(); //base::pr()
//        d.pr(); //drived::pr();
//        b.pr(1); //base::pr();
    }

    std::ifstream fs("./hello");
    vector<maiev1::Stu> container;
    std::string line;

    auto f = [](string line){
        std::istringstream iss(line);
        std::vector<string> tokens;
        std::string token;
        while(iss >> token){
            if (token.at(0) == ';'){
                continue;
            }
            auto pos = token.find("=");
            auto key = token.substr(0, pos);
            auto val = token.substr(pos+1);
            tokens.push_back(key);
            tokens.push_back(val);
        }

        return tokens;
    };

    while(std::getline(fs, line)){
        std::istringstream iss(line);
        auto tokens = f(line);
        if (!tokens.empty()){
            auto key = tokens.at(0);
            auto val = tokens.at(1);
            std::cout << key << "=" << val << std::endl;
        }
//        int no = stoi(tokens.at(0));
//        string name = tokens.at(1);
//        int age = stoi(tokens.at(2));
//        int grade = stoi(tokens.at(3));
//        double money = stof(tokens.at(4));
//
//        maiev1::Stu st(no,name,age,grade,money);
//        std:: cout << "st: " << st.toString() << std::endl;
//        container.push_back(st);
    }

    std::cout << "-------------" << std::endl;
    std::cout << container.size() << std::endl;

//    std::ofstream os("./hello");
//    os<<"hello world\r\n"
//            <<"maiev can can\r\n";
//    os.close();

    std::ifstream fs("./hello");
    //这里会过滤掉空格换行等字符
    int num = 0;
    while(!fs.eof()){
        string str;
//        std::getline(fs, str); //read line
        fs >> str; //read one world
        ++num ;
        std::cout << str << std::endl;
    }
    std::cout << "the result is :" << num << "words" << std::endl;
    std::cout << "---------------" << std::endl;

    const Int m1(0);
    m1.show();
    m1.show();
    m1.show();
    m1.show();
    std::cout << m1.show() << std::endl;

    {
        int x = 0b1100000000000011001000;
        int a1 = x >> 24 & 0XFF;
        int a2 = x >> 16 & 0XFF;
        int a3 = x >> 8 & 0XFF;
        int a4 = x & 0XFF;
        std::cout << bitset<8>(a1) << std::endl;
        std::cout << bitset<8>(a2) << std::endl;
        std::cout << bitset<8>(a3) << std::endl;
        std::cout << bitset<8>(a4) << std::endl;
        std::cout << bitset<8>(0xFF) << std::endl;

        uint8_t *pr = reinterpret_cast<uint8_t*>(&x);
        for(int i = 0; i < 4; i++){
            std:cout << bitset<8>(pr[i]) << " ";
        }

        std::cout << "------------" << std::endl;

        uint32_t len = 0x12345678;
        std::cout << len << std::endl;
        vector<uint8_t > buffer;

        uint8_t  p1 = len >> 24 & 0xFF;
        uint8_t  p2 = len >> 16 & 0xFF;
        uint8_t  p3 = len >> 8 & 0xFF;
        uint8_t  p4 = len & 0xFF;

        buffer.push_back(p1);
        buffer.push_back(p2);
        buffer.push_back(p3);
        buffer.push_back(p4);

        uint32_t b1 = (p1 << 24) | (p2 << 16) | (p3 << 8) | p4;
        std::cout << b1 << std::endl;
    }



    {
        Buff bf(20);
        Buff bf1(30);

        Buff bf2;

        MessageBuf buff;

        buff.write(bf);
        buff.write(bf1);
        buff.write(bf2);

        string name("maiev");
        buff.write(name);

        auto p1 = buff.read<Buff>();
        auto p2 = buff.read<Buff>();
        auto p3 = buff.read<Buff>();
        auto p4 = buff.read<string>();

        std::cout << p4 << std::endl;


//        bf.serialize(buff);
//        bf1.serialize(buff);
//        bf2.serialize(buff);
//
//        bf1.deserialize(buff); // ??
//        bf2.deserialize(buff); // ??
//        bf.deserialize(buff); // ??
    }

    {
        MessageBuf buff;
        buff.write<int>(12);
        int id = buff.read<int>();
        std::cout << id << std::endl;

        buff.reset();

        char* msg = "hello world";
        buff.write(msg);
        auto pm = buff.read<char*>();
        std::cout << pm << std::endl;

        buff.reset();
    }
    {
        std::vector<int> vc{1,2,3,4,5};
        auto pc = vc.data();
        std::cout << *pc << std::endl;
        std::cout << *(pc + 4) << std::endl;
    }
    {
        std::ofstream os("./out.bin", std::ios::binary);
        if (!os){
            std::cout << "error";
            return - 1;
        }

        std::vector<char> data = {0x75,0x79, 0153, 65, 97};
        for( int i = 0;  i< data.size() ; i ++ ){
            std::cout << data[i] << std::endl;
        }

        os.write(data.data(), data.size());

        os.close();
    }

    {
        vectorTest();
    }

    {
        arrayTest();
    }

    {
        shared_ptr<string> sp(new string("new usu"));
        cout << *sp<< endl;
        string* pname = new string("abc");
        sp.reset(pname);
        cout << *sp<< endl;
    }

    {
        std::vector<CTest> vc;
        vc.reserve(3);
        cout << "size of : " << vc.size() << endl;

        CTest c1 = -1;
        CTest c2 = 5;
        CTest c3 = 9;

//        vc.at(0) = c1;
//        vc.at(1) = c2;
//        vc.at(3) = c3;

//        vc.emplace_back(c1);
//        vc.emplace_back(c2);
//        vc.emplace_back(c3);

        vc.push_back(c1);
        vc.push_back(c2);
        vc.push_back(c3);

        cout << "size of : " << vc.size() << endl;

        cout << "elem: ";
        for(auto xx : vc){
            cout << xx << " ";
        }

        cout << endl;

        std::vector<CTest>::iterator it;

        std::vector<CTest> vc2;
        vc2.reserve(3);

//         it = std::find_if(vc.begin(), vc.end(), [](const CTest& cTest){
//             return cTest.getI() < 9;
//         });
        it = std::find(vc.begin(), vc.end(), 5);

        if (it == vc.end()){
            cout << "no found" <<endl;
        }else{
            cout << "has found:" << *it << endl;
        }

        auto find = [](int elem)->int{
            return 1;
        };

        auto f = find(10);
        cout << "f: " << f << endl;

        std::replace(vc.begin(), vc.end(), 1, 2);
        std::cout << "count: " << std::count(vc.begin(), vc.end(), 3);
        std::cout << "count: " << std::count_if(vc.begin(), vc.end(), [](CTest ctest){
            return ctest > 0;
        });

        std::for_each(vc.begin(), vc.end(), [](const CTest& cTest){
             cout << cTest.getI() << " ";
         });
         cout << endl;

//         std::copy_if(vc.begin(), vc.end(), std::back_inserter(vc2), [](CTest cTest)->bool{
//             return cTest.getI() < 3;
//         });

        cout << "-------------" << endl;
        std::remove_copy(vc.begin(), vc.end(), back_inserter(vc2), 5);
        std::copy(vc2.begin(), vc2.end(), ostream_iterator<CTest&>(std::cout, " "));

//        CTest* cp1 = new CTest;
//        std::shared_ptr<CTest> sp(cp1);
//
//        cout << *sp << endl;
//        cout << sp.use_count() << endl;
//        cout << "sp :" << sizeof(sp) << " pa: " << sizeof(cp1) << endl;
//        cout << "sp:" <<  sp.get() << " pa: " << cp1 << endl;
//
//        {
//            std::weak_ptr<CTest> cp(sp);
//            cp.lock();
//            cout << "sp_count: " << sp.use_count() << endl;
//            if (!cp.expired()){
//                cout << "expired" << endl;
//            }
//        }
    }

    {
        /**
        int * pa = new int(100);
        std::shared_ptr<int> sp(pa);

        cout << *sp << endl;
        cout << sp.use_count() << endl;
        cout << "sp :" << sizeof(sp) << "pa: " << sizeof(pa) << endl;
        cout << "sp:" <<  sp.get() << " pa: " << pa << endl;
         **/
    }

    {
        User user(string("name"), 12);
        ConnectionPool<Mysql<User>> pool(10);
        auto* conn = pool.acquire();
        conn->insert(user);
        pool.release(conn);
    }

//    List<User> userList;
//
//    User user(string("name"), 12);
//    Query<User> query;
//    query.select("name,age").eq("name", user);
//
//    Model<User> userModel;
//    User result = userModel.getOne(query);
//    cout << result << endl;
//
//    userList = userModel.getList(query);
//    cout << userList << endl;
//
//    int flag = userModel.insert(user);
//    std::cout << "flag: " << flag << std::endl;
//
//    HttpRequest request;
//    HttpResponse response;
//
//    Application app("myapp");
//    app.start(request, response);
//
//    string url = "http://localhost:9200/user/getUser";

//    Result<Model<User>> userResult = request.get<userModel>(url);
//    Result<Model<Money>> moneyResult = request.post(url, moneyModel);

    vector<TestType> vc;
    vc.reserve(20);

    vc.push_back(TestType());
    std::cout << vc.size() << std::endl;

    vector<studentType> studentList;
    double tuitionRate;
    ifstream infile;
    ofstream outfile;

    infile.open("../stData.txt");
    if (!infile){
        cout << "Input file not exists!!";
        return 1;
    }

    cout << "file has open" << endl;

    outfile.open("../stDataOut.txt");
    infile >> tuitionRate;
    getStudentData(infile, studentList);
    printGradeReports(outfile, studentList, tuitionRate);

    deque<int> dq;
    istream_iterator<int> is(cin);
    istream_iterator<int> end;

    copy(is, end, front_inserter(dq));

//    copy_n(is, 10, back_inserter(dq));

    ostream_iterator<int> screen(cout, " ");
    copy(dq.begin(), dq.end(), screen);

    vector<int> intList;
    int arr[] = {1,2,3,4,5};
    vector<int> intList2(arr, arr+5);


    intList.resize(intList2.size());
    intVecIt it1 = intList.begin();

    it1++;
    it=
    *it1;
    it1!=it2;
    it1.begin();
    it2.end();

    it1 = it; ???

    copy(intList2.begin(), intList2.end(), it1);

    ostream_iterator<int> screen(cout, " ");
    copy(intList.rbegin(), intList.rend(), screen);



    double f = 1.1;
    double da = showA(f);

    int a = 10;
    const int& ca = a;
    int* pa = &a;

    int b = showA(a); //const int -> int;???
    cout << "b->" << b << endl;
    showA(ca);
    showA(pa);

    cout << "------------" << endl;


    polynomialType p(8);
    polynomialType q(4);
    polynomialType t;

    cin >> p;
    cout << endl << "Line 10:p(x):" << p << endl;
    cout << "Lin 11: p(5):" << p(5) << endl << endl;

    cin >> q;
    cout << endl << "Line 13:q(x):" << q << endl;

    t = p + q;

    cout << "Lint 15: p(x) + q(x) " << t << endl;
    cout << "Lint 16: p(x) - q(x) " << p - q << endl;

    arrayListType<string> stringList;
    string str;
    cout << "list 10 : enter 5 integers:";

    for(int counter = 0; counter < 5; counter++){
        cin >> str;
        stringList.insert(str);
    }

    cout << endl;
    cout << "list 19: thi list you enter is :";
    stringList.print();
    cout << endl;

    cout << "Line 20: enter the item to be deleted!";
    cin >> str;
    stringList.remove(str);
    cout << "Line 23: after removing" << str << "the line is " << endl;
    stringList.print();
    cout << endl;


    arrayListType<int> intList(100);
    int number;
    cout << "list 10 : enter 5 integers:";

    for(int counter = 0; counter < 5; counter++){
        cin >> number;
        intList.insert(number);
    }

    cout << endl;
    cout << "list 19: thi list you enter is :";
    intList.print();
    cout << endl;

    cout << "Line 20: enter the item to be deleted!";
    cin >> number;
    intList.remove(number);
    cout << "Line 23: after removing" << number << "the line is " << endl;
    intList.print();
    cout << endl;

    baseCls base(10);
    derivedCls dr(10,20);

    print(base);
    print(dr);

//    dr.print();
//    base.print();

    {
        {
            mystery* myt = ::new mystery(10);
            myt->show();
            delete myt;
        }

        int len = 5;
        mystery *my = new mystery[len]; //只调用默认的构造函数
        mystery *ptr = my;

        for(int i = 0; i < len; i ++){
//            my[i].show();
            ptr->show();
            ++ptr;
        }

        delete[] my;
    }

    //    listType<complexType> testList;
    int len = listType<complexType>::maxLength;
//    array<complexType, 10> arr;
    {
        vector<complexType> vec;
        vec.reserve(3);
        for(int i = 0; i < 3; i++){
            vec.push_back(complexType(i,i));
        }
    }

    for(int i = 0; i < 10; i++){
    }

    listType<int> myList;
    for(int i = 0; i < 10; i++){
        myList.insert(i);
    }

    bool found;
    myList.printList();
    int searchItem;
    cin >> searchItem;
    myList.search(searchItem, found);
    std::cout << "myList has <" << searchItem <<" :" << found << std::endl;

    complexType c1, c2;
    std::cin >> c1 >> c2;

    complexType c3 = c1 + c2;
    complexType c4 = c1 * c2;

    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "c1 + c2 = " << c3 << std::endl;
    std::cout << "c1 * c2 = " << c4 << std::endl;

    complexType c5(1,1);
    std::cout << "c5 = " << c5 << std::endl;

    double real, image;
    c1.getComplex(real, image);

    complexType c6;
    c6.setComplex(real, image);
    std::cout << "c6 = " << c6 << std::endl;

    bool equal = c1 == c6;
    if (equal){
        std::cout << "c1 == c6" << std::endl;
    }else{
        std::cout << "c1 != c6" << std::endl;
    }

    showFunc(c1);
    showFunc(c2);
    showFunc(c3);
    showFunc(c4);
    showFunc(c5);
    showFunc(c6);

    {
        {
            test t1;
            operator>>(std::cin, t1);
            operator<<(std::cout, t1);
            std::cout << t1 << std::endl;
        }
        {
            int a = 10;
            int *pa = &a;
        }
        std::cout << "------------" << std::endl;
        {
            test *mq = new test();
            myRAII<test> myRaii1(mq); //处理内存泄露问题!!!

            int ma = (*mq)();
            std::cout << ma << std::endl;

            try{
                func(mq);
            }catch (const int& a){
                std::cout << a << std::endl;
            }catch(...){
            }

            mq->show();
        }
        std::cout << "------------" << std::endl;
        {
            test mt(100);
            std::cout << mt() << std::endl;
            mt.show();
        }
    }

    std::cout << sizeof(maiev) << std::endl;

    TestType t1 = 1;
    TestType t2 = 2;

    TestType t4 = t1 + t2;
//    TestType t3 = func(t1, t2);

    Mystery mystery;
    printSecret(mystery);

    clsFriend cls(10);
    clsFriend cls2;
    cls2 = 10;
    clsFriend cls3;
    cls3 = cls2;

    B b;
    b.showAge(cls3);

    int age = showAge(cls);
    cls.showAge();
    A a(10);
    a.showAge(cls3);

    BoxType boxType(1,2,3);
    assert(22 == boxType.area());
    std::cout << boxType.area() << std::endl;
    assert(5 < boxType.volume());
    std::cout << boxType.volume() << std::endl;
    boxType.print();

    ClockType myclock(1,2,3);
    ClockType myclock2(1);
    myclock2.printTime();
    for(int i = 0; i < 20; i++){
        myclock.incrementSeconds();
    }
    myclock.printTime();

    assert(myclock.equalTime(myclock));
    for(int i = 0; i < 50; i++){
        myclock.incrementMinutes();
    }
    myclock.printTime();

    for(int i = 0; i < 10; i++){
        myclock.incrementHours();
    }
    myclock.printTime();
}
#endif
