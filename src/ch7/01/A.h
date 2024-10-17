//
// Created by xiaowei003 on 2024/9/22.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H
#include <string>
#include <array>
#include <cassert>
#include <unordered_set>

namespace ch701 {
    class A {

    };

    class Myclass {
    public:
        int x;

        Myclass(int val) : x(val) {}

        const int &get() const { return x; }

        int &get() { return x; }
    };

    void print(const Myclass &arg) {
        cout << arg.get() << endl;
    }

    template<typename T>
    class mypair {
    private:
        T a, b;
    public:
        mypair(T first, T second) : a(first), b(second) {}

        T getMax();
    };

    template<typename T>
    T mypair<T>::getMax() {
        return a > b ? a : b;
    }

    template<typename T>
    class mycontainer {
    private:
        T element;
    public:
        mycontainer(T arg) { element = arg; }

        T increase() { return ++element; }
    };

    template<>
    class mycontainer<char> {
        char element;
    public:
        mycontainer(char arg) : element(arg) {}

        char uppercase(); // Declare the method as uppercase
    };

    char mycontainer<char>::uppercase() { // Define the method as uppercase
        if ((element >= 'a') && (element <= 'z')) {
            element += 'A' - 'a'; // Convert to uppercase
        }
        return element;
    }

    template<typename T>
    void prval(T val) {
        cout << "generic template::" << val << endl;
    }

    template<>
    void prval<int>(int val) {
        cout << "specilized template::" << val << endl;
    }

    void test();

    class Example {
    public:
        Example() = default;
        Example(int x);
        Example(const Example & );
        int total;
        void accumulate(int x);
        ~Example(){cout << "~Example::" << typeid(*this).name() <<endl;}
    };

    Example::Example(int x){
        total = x;
    }

    Example::Example(const Example & ex)
    {
        total = ex.total;
    }

    void Example::accumulate(int x) {
        int total = this->total;
        cout << "total:" << total  << '\n'
             << "x:" << x  << '\n'
             << "total+ x = " << ( total + x ) << endl;
    }

    class Example4{
    public:
        int *ptr;
        Example4(int *p):ptr(p){}
        Example4(const Example4& ex);
        Example4& operator=(const Example4&);
        ~Example4() { cout <<"~Example4" << endl; delete ptr;}

        void pr(){
            cout << typeid(*this).name() << "::*ptr: " << *ptr << endl;
        }
    };

    Example4& Example4::operator=(const Example4& ex) {
        cout << "copy assign " << endl;
        ptr = new int(*ex.ptr);

        return *this;
    }

    Example4::Example4(const Example4& ex)
    {
        cout << "copy construct" << endl;
        ptr = new int(*ex.ptr);
    }

    class Example5 {
    private:
        string *ptr;
    public:
        const string& content() const { return *ptr;}
        Example5(const string& str) :ptr(new string(str)){}
        Example5(const Example5& ex){
            cout << "copy construct" << endl;
            ptr = new string(ex.content());
        }
        Example5& operator=(const Example5& ex) {
            cout << "copy assign" << endl;
            ptr = new string(ex.content());

            return *this;
        }

        ~Example5(){cout << "~Example5" << endl;delete ptr;}
    };

    class Example6 {
    private:
        string* ptr;
    public:
        Example6(const string& str): ptr(new string(str)){cout << "contruct::" << endl;}
        ~Example6(){ delete ptr;}

        Example6(Example6&& ex){
            cout << "move construct::" << endl;
            ptr = ex.ptr;
            ex.ptr = nullptr;
        }

        Example6& operator=(Example6 && ex){
            cout << "move assign::";
            delete ptr;
            ptr = ex.ptr;
            ex.ptr = nullptr;

            return *this;
        }

        const string& content() const { return *ptr;}
//
//        void asq(const Example6& ex){
//            string name = *ex.ptr;
//            cout << "asq::" << *(ex.ptr)<< endl;
//        }

        Example6 operator+(const Example6& rhs){
            return Example6(content() + rhs.content());
        }
    };

    class Square;

    class Rectangle{
    private:
        int width, height;
    public:
        Rectangle(){}
        Rectangle(int w, int h): width(w), height(h){}
        int area() { return width * height;}
        friend Rectangle duplicate(const Rectangle&);
        void convert(Square);
    };

    class Square{
        friend class Rectangle; //rectangele is a friend of square
    private:
        int side;
    public:
        Square(int a): side(a) {}
    };

    void Rectangle::convert(Square a) {
        width = a.side;
        height = a.side;
    }

    Rectangle duplicate(const Rectangle& rhs)
    {
        Rectangle tmp;
        tmp.width = rhs.width;
        tmp.height = rhs.height;

        return tmp;
    }

    class Polygon{
    private:
        int _h;
    protected:
        int width, height;
        int _getH(){
            return _h;
        }
    public:
        void set_values(int a, int b){
            width = a;
            height = b;
            _h = a + b;
        }
    };

    class Recttangle: protected Polygon{
    public:
        void set_v(int a, int b)
        {
            set_values(a, b);
        }
        int area() {
            cout << "_h::" << _getH() << endl;
            return width *height;
        }
    };

    class X : protected Recttangle{
    public:
        X() = default;
        X (int a ,int b) {
            width = a;
            height = b;
        }
        int area(){
            return width + height;
        }
    };

    class Triangle: public Polygon{
    public:
        int area() { return width * height / 2;}
    };

    class Mother{
    public:
        Mother(){
            cout << "Mother::no params:" << endl;
        }
        Mother(int a){
            cout << "Mother::int param:" << endl;
        }
    };

    class Daughter : public Mother{
    public:
        Daughter(int a){ cout << "daughter int param:" << endl;}
        void getD() {cout << "Daughter: i speak!!!" << endl;}
    };

    class Son : public Mother{
    public:
        Son(int a): Mother(a){ cout << "son int param:" << endl;}
        void getS() {cout << "Son: i speak!!!" << endl;}
    };

    class Xs: public Daughter, Son{
    public:
        Xs(int a): Daughter(a), Son(a) {cout << "Xs int param:" << endl;}
    };

    template<typename T>
    T sux(T a, T b)
    {
        return a + b;
    }

    template <class T, int N>
    T fix_sux(T val)
    {
        return val * N;
    }

    template<typename T>
    struct ValueWithComment{
        T value;
        std::string comment;
    };

    template<typename T, std::size_t Maxsize>
    class Stack{
    private:
        std::array<T, Maxsize> elems;
        std::size_t numElems;
    public:
        Stack();
        void push(T const& elem);
        void pop();
        T const& top() const;
        bool empty() const{
            return numElems == 0;
        }
        std::size_t size() const{
            return numElems;
        }
    };

    template<int val, typename T>
    T addValue(T x)
    {
        return x + val;
    }

//    template<auto val, typename T = decltype(val)>
//    T foo();

    template<typename T, T val = T{}>
    T bar();

    char const s11[] = "hi";

    template <char const* name>
    struct Messge{
        void pr() { cout << "name:" << name <<endl;}
    };

    template<int I ,bool B>
    class C;

    class s{};
//    void printx(){}
    template<typename T>
    void printx(T arg)
    {
        cout << " value:" << arg << endl;
    }

    template<typename T, typename ...Types>
    void printx(T firstArg, Types... args)
    {
        cout << "type:" <<sizeof ...(Types)
                << " and args:" << sizeof ...(args)
                << endl;
        printx(firstArg);
        printx(args...);
    }

//    template<typename ...Args>
//    int sum(Args... args)
//    {
//        return (args + ...);
//    }

    class Customer
    {
    private:
        std::string name;
    public:
        Customer(std::string const &n) : name(n){}
        std::string getName() const { return name;}
    };

    struct CustomerEq{
        bool  operator() (Customer const& c1, Customer const & c2) const{
            return c1.getName() == c2.getName();
        }
    };

    struct CustomerHash{
        std::size_t operator()(Customer const& c){
            return std::hash<std::string>()(c.getName());
        }
    };

//    c++ 17
//    template<typename... Bases>
//    struct Overloader : Base...{
//        using Bases::operator()...;
//    };

//    template<typename T>
//    class My{
//    public:
//        void foo(){
//            typename T::subtype* ptr;
//        }
//    };

    template <typename T>
    void printcoll(T const& coll)
    {
        typename T::const_iterator pos;
        typename T::const_iterator end(coll.end());
        for( pos = coll.begin(); pos != end; +pos) {
            cout << * pos <<endl;
        }
    }

    class B{
    public:
        void bar(){cout << "B :"<< endl;}
    };

    class BB : B{
    public:
        void foo(){
            bar();
        }
    };

    template<typename T>
    class Base{
        public:
            void bar();
    };

    template<typename T>
    class Derived: Base<T>{
    public:
        void foo(){
            this->bar();
            Base<T>::bar();
        }
    };

    template<typename T, int N, int M>
    bool less(T(&a)[N] , T (&b)[M] )
    {
        for(int i = 0; i < N && i < M; i++){
            if (a[i] < b[i]) return true;
            if (a[i] > b[i]) return false;
        }

        return N < M;
    }

    template<typename T>
    struct MyClass;

    template<typename T, std::size_t SZ>
    struct MyClass<T[SZ]>{
        static void pr() {cout << "pr() or T[" << SZ << "]" <<endl;}
    };

    template<typename T, std::size_t SZ>
    struct MyClass<T(&)[SZ]>{
        static void pr() {cout << "pr() or T(&)[" << SZ << "]" <<endl;}
    };

    template<typename T>
    struct MyClass<T[]>
    {
        static void pr() {cout << "pr() or T[]" <<endl;}
    };

    template<typename T>
    struct MyClass<T(&)[]>
    {
        static void pr() {cout << "pr() or T(&)[]" <<endl;}
    };

    template<typename T>
    struct MyClass<T*>
    {
        static void pr() {cout << "pr() or T*" <<endl;}
    };

    void fx(int a[10])
    {
        cout << __FUNCTION__<< endl;
        auto i = a;
        for(auto i = a; i < a+ 10; i ++ ){
            cout << *i << endl;
        }
    }

    template <typename T1>
    class St{
    private:
        T1 _a;
    public:
        St(int a ) : _a(a){};

        void pr() { cout << "_a :" << _a << endl;}

        template <typename T2>
        St& operator= (St<T2>const & );
        template<typename> friend class St; //to get access private of st<T2> or any type T2?????????
    };

    class Boolstring
    {
    private:
        std::string value;
    public:
        Boolstring(std::string &s) : value(s) {}
        template <typename T = std::string>
        T get() const{
            return value;
        }
    };
}





#endif //UNTITLED_A_H
