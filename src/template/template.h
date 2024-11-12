//
// Created by xiaowei003 on 2024/11/12.
//

#ifndef UNTITLED_MAIN_H
#define UNTITLED_MAIN_H

#include <iostream>
#include <type_traits>
#include <deque>
#include <iterator>

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
    getI(const C<I, false>& c) const { return c._i;}
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





#endif //UNTITLED_MAIN_H

