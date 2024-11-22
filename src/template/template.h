//
// Created by xiaowei003 on 2024/11/12.
//

#ifndef UNTITLED_MAIN_H
#define UNTITLED_MAIN_H

#include <iostream>
#include <type_traits>
#include <deque>
#include <iterator>
#include <tuple>

class main {

};

template<typename T>
T maxx(const T&a, const T& b)
{
    return a > b ? a : b;
}
template<typename T=std::string>
void f(T = "")
{
    std::cout << "" << std::endl;
}

template<typename RT, typename T1, typename T2>
RT maxx(const T1 &a, const T2 &b)
{
    return a > b ? a : b;
}

//template<typename T1, typename T2, typename RT = std::common_type_t<T1, T2>>
//RT maxx(const T1 &a, const T2 &b)
//{
//    return a > b ? a : b;
//}

//template<typename T1, typename T2>
//        std::common_type_t<T1,T2> maxx(T1 a , T2 b)
//{
//return a > b ? a : b;
//}

/**
template<typename T1, typename T2>
auto maxx(const T1 &a, const T2 &b) -> decltype(a > b ? a : b)
{
    return a > b ? a : b;
}
 **/

//template<typename T1, typename T2>
//auto maxx(const T1 &a, const T2 &b) -> typename std::decay<decltype(a > b ? a : b)>::type
//{
//    return a > b ? a : b;
//}

template<typename T1, typename T2>
auto maxx(const T1 &a, const T2 &b) -> typename std::decay<decltype(true ? T1() : T2())>::type
{
    return a > b ? a : b;
}

template<typename T>
class MAIEV{
public:
    MAIEV() = default;
    MAIEV(T _v): val(_v){}

    MAIEV<T> operator<<(std::ostream& os){
        os << val << std::endl;
        return *this;
    }

    //这里可以直接定义友元函数啊！！！！！！
    friend void xx(const MAIEV<T>& m)
    {
        std::cout << m.val<< std::endl;
    }

    MAIEV<T>& operator=(const MAIEV<T>& m){
        std::cout << "copy MAIEV<T>" << std::endl;
        val = m.val;
        return *this;
    }

    void xxyz(const MAIEV<T> m1, const MAIEV<T> m2)
    {
        std::cout << "----" << std::endl;
        std::cout << m1.val << std::endl;
        std::cout << m2.val << std::endl;
        std::cout << "----" << std::endl;
    }

//    template<typename T2>
//    MAIEV<T>& operator=(MAIEV<T2> const& m);

    //申明MAIEV<T2> for any type T2;
    template<typename> friend class MAIEV;
//    template<typename X> friend class MAIEV; //效果同上

    template<typename T2>
    MAIEV<T>& operator=(MAIEV<T2> const& m){
        val = static_cast<T>(m.val);
//        val = static_cast<T>(m.getVal());
        return *this;
    }

    //输出必须是友元的！！！！
    friend std::ostream& operator<<(std::ostream& os, MAIEV<T> const& m)
    {
        m.printOn(os);
        return os;
    }
    T getVal() const
    {
        return val;
    }
private:
    std::ostream& printOn(std::ostream& os) const
    {
        os << val;
        return os;
    }
    T val;
};

//template<typename T>
//    template<typename T2>
//MAIEV<T>& MAIEV<T>::operator=(MAIEV<T2> const& m){
//    val = static_cast<T>(m.getVal());
//    return *this;
//}

template<>
class MAIEV<std::string>{
public:
    MAIEV(std::string n): name(n){}

    MAIEV<std::string> operator<<(std::ostream& os){
        os <<this->name << std::endl;
        return *this;
    }

    MAIEV<std::string>& operator=(MAIEV<std::string> const& m){
        this->name = m.name;
        return *this;
    }

    //这里可以直接定义友元函数啊！！！！！！
    friend void xx(const MAIEV<std::string>& m)
    {
        std::cout << m.name << std::endl;
    }

    //输出必须是友元的！！！！
    friend std::ostream& operator<<(std::ostream& os, MAIEV<std::string> const& m)
    {
        m.printOn(os);
        return os;
    }
private:
    std::ostream& printOn(std::ostream& os) const
    {
        os <<this->name;
        return os;
    }
    std::string name;
};

//特化不能用默认模板参数
template<typename T>
class MAIEV<T*>{
public:
    MAIEV(T* n): val(n){}

    MAIEV<T*> operator<<(std::ostream& os){
        os << *(this->val) << std::endl;
        return *this;
    }

    MAIEV<T*>& operator=(MAIEV<T*> const& m){
        this->val = static_cast<T*>(m.val);
        return *this;
    }

    //这里可以直接定义友元函数啊！！！！！！
    friend void xx(const MAIEV<T*>& m)
    {
        std::cout << *(m->val) << std::endl;
    }

    //输出必须是友元的！！！！
    friend std::ostream& operator<<(std::ostream& os, MAIEV<T*> const& m)
    {
        m.printOn(os);
        return os;
    }
private:
    std::ostream& printOn(std::ostream& os) const
    {
        os << * (this->val);
        return os;
    }
    T* val;
};

class C1;

template<int I, bool B>
class C;

class B1{
public:
    template<int I, bool B>
    bool getB(const C<I, B>& c) const {
        return c._b;
    };
};

template<int I, bool B>
class C{
public:
    C() : _i(I),_b(B){}

    template <int II, bool BB>
    friend std::ostream& operator<<(std::ostream& os, C<II,BB> const& m);
    friend class C1; //友元类

    template <int II, bool BB>
    friend bool B1::getB(const C<II,BB> &m) const; //友元函数
private:
    int _i;
    int _b;
};

template<int I, bool B>
std::ostream& operator<<(std::ostream& os, C<I,B> const& m)
{
    os << m._i << m._b << std::endl;
    return os;
}

class C1{
public:
    template<int I>
    int getI(const C<I, false>& c) const { return c._i;}
};

/**
//c17
template <auto T>
class Message{
public:
    void print(){
        std::cout << T << std::endl;
    }
};
 **/

//template<int I, bool B>
//bool B1::getB(const C<I,B>& c) const{
//    return c._b;
//}

template <typename T>
struct MyClass{
    static constexpr int max = 1000;
};

template<typename T, std::size_t SZ>
struct MyClass<T[SZ]>{
    static void print() { std::cout << "print() for T[" << SZ << "]" << std::endl;}
};

template<typename T, std::size_t SZ>
struct MyClass<T(&)[SZ]>{
    static void print() { std::cout << "print() for T(&)[" << SZ << "]" << std::endl;}
};

template<typename T>
struct MyClass<T[]>{
    static void print() { std::cout << "print() for T[]" << std::endl;}
};

template<typename T>
struct MyClass<T(&)[]>{
    static void print() { std::cout << "print() for T&[]" << std::endl;}
};

template<typename T>
struct MyClass<T*>{
    static void print() { std::cout << "print() for T* " << std::endl;}
};

template<typename T1, typename T2, typename T3>
void foo(int a1[7], int a2[],
         int (&a3)[42],
         int(&x0)[],
         T1 x1,
         T2& x2,
         T3&& x3 )
{
    MyClass<decltype(a1)>::print(); //Myclass<T*>
    MyClass<decltype(a2)>::print(); //Myclass<T*>
    MyClass<decltype(a3)>::print(); //Myclass<T(&)[42]>
    MyClass<decltype(x0)>::print(); //Myclass<T(&)[]>
    MyClass<decltype(x1)>::print(); //MyClass<T*>
    MyClass<decltype(x2)>::print(); //Myclass<T&[]>
    MyClass<decltype(x3)>::print(); //Myclass<T&[]>
}

template<typename T1, typename T2, typename T3>
class Foo2
{
public:
    Foo2(T1 _a, T2 _b, T3 _c): a(_a), b(_b),c(_c){}
    friend std::ostream& operator<<(std::ostream& os, const Foo2<T1, T2, T3>& foo2)
    {
        os << "a = " << foo2.a
           << "b = " << foo2.b
           << "c = " << foo2.c
           << std::endl;
        return os;
    }
private:
    T1 a;
    T2 b;
    T3 c;
};

/**
 * c14
template<typename T>
int myMax = MyClass<T>::max;
 **/

template<typename T1,
        typename T2,
        typename T3,
        template<typename> typename Cont,
        template<typename, typename, typename> class Foo>
void ff(T1 elem, Cont<T1> c, Foo<T1, T2, T3> f)
{
//    std::cout << typeof(int) << std::endl;
    std::cout << typeid(T1).name() << std::endl;
    std::cout << typeid(T2).name() << std::endl;
    std::cout << typeid(T3).name() << std::endl;
    std::cout << elem << std::endl;
    std::cout << c.getVal() << std::endl;
    std::cout << f << std::endl;
}

template<typename T,
        template <typename Elem> typename Cont = std::deque>
class Stackk{
private:
    Cont<T> elems;
public:
    void print()
    {
        std::copy(elems.begin(), elems.end(), std::ostream_iterator<T>(std::cout, " "));
    }
};

template<typename T,
        template <typename Elem, typename = std::allocator<Elem>> class Cont = std::deque>
class Stackkk
{
private:
    Cont<T> elems;
public:
    void print()
    {
        std::copy(elems.begin(), elems.end(), std::ostream_iterator<T>(std::cout, " "));
    }

    template<typename, template<typename,typename>class>
    friend class Stackkk;

    template<typename T2,
            template<typename Elem2,
            typename = std::allocator<Elem2>>
            class Cont2 = std::deque>
    Stackkk<T,Cont>& operator=(const Stackkk<T2,Cont2>& st);
};

template<typename T, template <typename, typename > class Cont>
    template<typename T2, template<typename, typename> class Cont2>
Stackkk<T,Cont>& Stackkk<T, Cont>::operator=(const Stackkk<T2,Cont2>& st)
{
    elems.clear();
    elems.insert(elems.begin(), st.elems.begin(), st.elems.end());

    return *this;
}

//template <typename T>
//void printV(T arg)
//{
//    std::cout << "arg:" << arg << std::endl;
//}

template <typename T>
void printV(T& arg)
{
    if (std::is_array<T>::value){
        std::cout << "is_array" << std::endl;
    }

    if (std::is_integral<T>::value){
        std::cout << "is int" << std::endl;
    }

    std::cout << "arg[&]:" << arg << std::endl;
}

template <typename T>
void printV(T const& arg)
{
    std::cout << "arg[const&]:" << arg << std::endl;
}

template <typename T>
void outR(T & arg)
{
    static_assert(!std::is_const<T>::value, "out parameter of foo<T>(T&) us const");
    std::cout << "arg[const&]:" << arg << std::endl;
}

template <typename T, typename = typename std::enable_if<!std::is_const<T>::value>::type>
void outR(T & arg)
{
//    static_assert(!std::is_const<T>::value, "out parameter of foo<T>(T&) us const");
    std::cout << "arg[const&]:" << arg << std::endl;
}

//c20
//template <typename T>
//requires !std::is_const<T>::value
//void outR(T & arg)
//{
//    static_assert(!std::is_const<T>::value, "out parameter of foo<T>(T&) us const");
//    std::cout << "arg[const&]:" << arg << std::endl;
//}

template <typename T>
void passR(T&& arg){
    std::cout << "T&& arg" << arg << std::endl;
}

template<typename T>
class Func{
public:
    bool operator()(T & arg){
        std::cout << "T&& arg" << arg << std::endl;
        return false;
    }
};

template<typename T, T Z= T{}>
class RefMem{
private:
    T zero;
public:
    RefMem() : zero{Z}{}
};

template<typename T>
class Node{
    using Type = T;
    using Pointer = T*;
    using Rerfence = T&&;
    Node *next;
    Node<Type>* previous;
    Node<T*>* parent;

};

class Factory;

template<typename T>
class Tree{
    friend class Factory;
    friend class Node<T>;
};


template <typename T1, typename T2>
void combine(T1, T2);

template <typename XX>
class Mixer{
    friend void combine<>(int&,int &);
    friend void combine<int, int>(int,int);
    friend void combine<char>(char,int &);
//    friend void combine<char>(char&,int &);
    friend void combine<>(long, long);
    using ELement = XX;
};

template class Mixer<int>;

template<typename T>
typename T::ElementT at(T a ,int i)
{
    return a[i];
}

template<char...> int operator "" _B7();

//template<char... cs>
//int operator"" _B7()
//{
//    std::array<char, sizeof...(cs)> chars{cs...};
//    for(char c : chars){
//        std::cout << "'" << c << "'";
//    }
//
//    std::cout << std::endl;
//    return ...;
//}
template<typename T>
int ff(T, T x= 42)
{
    std::cout << " template<T>" << std::endl;
    return x;
}

//template<>
//int ff(int, int x= 33)
//{
//    std::cout << " template<int>" << std::endl;
//    return x;
//}

class A11{
public:
    void assign()
    {
        std::cout << "A! assign" << std::endl;
    }
};

class B11 : public A11{
public:
    void assign()
    {
        std::cout << "B! assign" << std::endl;
    }
};

void readData() {
    std::string data;
    std::getline(std::cin, data);
    std::cout << "Data entered: " << data << std::endl;
}

bool action() { // 你的动作逻辑
    return true; // 示例返回值
}
template <typename T>
struct AccumulationTraits;

template <>
struct AccumulationTraits<int>
{
    using AccT = int;
    static constexpr AccT zero()
    {
        return 0;
    }
};

template <>
struct AccumulationTraits<float>
{
    using AccT = float;
    static constexpr AccT zero()
    {
        return 0.0f;
    }
};

class SumPolicy{
public:
    template<typename T1, typename T2>
    static void accumulate(T1&total, T2 const& value){
        std::cout << "value:" << value << std::endl;
        total += value;
    }
};

class MultPolicy{
public:
    template<typename T1, typename T2>
    static void accumulate(T1&total, T2 const& value){
        total *= value;
    }
};

template<typename T,
        typename Policy = SumPolicy,
        typename Traits = AccumulationTraits<T>>
typename Traits::AccT accum(T const* beg, T const*end)
{
    using AccT = typename Traits::AccT;
    AccT total = Traits::zero();
    while(beg != end){
        Policy::accumulate(total, *beg);
        ++beg;
    }

    return total;
}

template<typename T>
struct RemoveRefenenceT{
    using Type = T;
};

template<typename T>
struct RemoveRefenenceT<T&>{
    using Type = T;
};

template<typename T>
struct RemoveRefenenceT<T&&>{
    using Type = T;
};

template<typename T>
using RemoveRefenence = typename RemoveRefenenceT<T>::Type;

template<unsigned N>
struct bbinary
{
    static unsigned const value = bbinary<N/10>::value * 2 + N % 10;
};

template<>
struct bbinary<0>
{
    static unsigned const value = 0;
};

template<typename T, typename U>
void printx(T rem, U const& pair)
{
    std::cout << rem << "(" << pair.first << ", " << pair.second << ")\n";
}

struct Foo
{
    Foo(std::tuple<int, float> tp)
    {
        std::cout << "(" << std::get<0>(tp) << "," << std::get<1>(tp) << ")"<< std::endl;
        std::cout << "从元组构造Foo\n";
    }

    Foo(int f1, float f2)
    {
        std::cout << "(" << f1 << "," << f2 << ")"<< std::endl;
        std::cout << "从 int和float 构造Foo\n";
    }
};

template<>
struct std::hash<std::pair<int,int>>
{
    std::size_t operator()(const std::pair<int, int> p) const
    {
        std::hash<int> f1;
        return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
//        return f1(p.first) ^ f1(p.second);
    }
};


#endif //UNTITLED_MAIN_H

