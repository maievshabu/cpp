#include <iostream>

#include "../sum.h"
#include "Game.h"
#include "scene.h"
#include <ctime>

void getScene(const scene& scene)
{
    scene.enter();
    scene.out();
}

//template<typename T>
//class isEqual
//{
//public:
//    bool compare(T x, T y)
//    {
//        std::cout << "typename<T> compare: ";
//        return x == y ? true : false;
//    }
//};

#ifdef false
template<typename T>
class isEqual;

template<>
class isEqual<const int>
{
public:
    bool compare(const int* x, const int* y)
    {
        std::cout << "typename<int> compare: ";
        return x == y ? true : false;
    }
};

template<>
class isEqual<const int*>
{
public:
    bool compare(const int* x, const int* y)
    {
        std::cout << "typename<int*> compare: ";
        return x == y ? true : false;
    }
};

template<>
class isEqual<char>
{
public:
    bool compare(char x, char y)
    {
        std::cout << "typename<char> compare: ";
        return x == y ? true : false;
    }
};
#endif

class MyHome{
public:
    MyHome() = default;
    explicit MyHome(string addr) : _address(addr){};
    ~MyHome() = default ;
    MyHome(const MyHome &m){
        _address = m._address;
    }
    MyHome(MyHome &&m) noexcept{
        _address = std::move(m._address);
    }
    MyHome& operator=(MyHome const  &m){
        if (&m == this){
            return *this;
        }
        _address = m._address;
        return *this;
    }

    MyHome& operator=(MyHome &&m) noexcept{
        _address = std::move(m._address);
        return *this;
    }

    bool operator>(const MyHome& oth) const{
        return !this->operator<(oth);
    }

    bool operator<(const MyHome& oth) const{
        return _address < oth._address;
    }

    bool operator==(const MyHome& oth) const{
        return _address == oth._address;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyHome &m){
        os << m._address;
        return os;
    }
    string show() const { return _address;}
private :
    string _address;
};

class ContainerHome{
public:
    ContainerHome() = delete;
    ContainerHome(MyHome* home) : _home(new MyHome(*home)){
        ++count;
    };

    void show(){
        std::cout << ContainerHome::count << std::endl;
    };

    ~ContainerHome(){
        delete _home;
        count--;
    };
public:
    static int count;
private:
    MyHome* _home;
};

template<typename T>
bool gt1(T a, T b){
    return a > b;
}

template<typename T>
bool lt1(T a, T b){
    return a < b;
}

template<typename T>
bool eq1(T a, T b) {
    return a == b;
}

template<typename T>
class GT{
public:
    bool operator()(T a, T b){
        return a > b;
    }
};

template<typename T>
class LT{
public:
    bool operator()(T a, T b){
        return a < b;
    }
};

template<typename T>
class EQ{
public:
    bool operator()(T a, T b){
        return a == b;
    }
};

template<typename T, typename Comp>
bool compareTo(T a, T b, Comp comp){
    return comp(a, b);
}

int ContainerHome::count = 0;

template<typename T>
void printMy(const T& name) noexcept(false){
    throw 10;
    std::cout << typeid(T).name() << ":"<<  name << std::endl;
}

#include <set>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <cassert>
#include <fstream>

int main() {
    std::ofstream os("out.bin", std::ios::binary);
    if (!os){
        std::cout << "error";
        return - 1;
    }

    std::vector<char> data = {0x11,0x02, 0x13};
    os.write(data.data(), data.size());

    os.close();

#ifdef FALSE
    vector<int> vc{1,2,3,3,4,5,5,6,7,8,9,10};

    bool flag = binary_search(vc.begin(), vc.end(),4);

    auto it = std::find(vc.begin(), vc.end(), 1);

//    auto it2 = std::find_if(vc.cbegin(), vc.cend(), [](int item){
//        return item % 2 == 0;
//    });
//
//    std::cout << *it2 << std::endl;

    set<int> st{1,1,3,24,4,5};

    auto st_it = st.find(1);

    if (st_it != st.end()){
        std::cout << * st_it<< std::endl;
    }

    MyHome maiev("ZJ-HZ-001");
    string home1 = maiev.show();

    try{
        printMy(maiev);
    }catch (int flag){
        std::cout << flag << std::endl;
    }catch(...){
        std::cout << "xxx" << std::endl;
    }

    MyHome m2 = maiev;
    MyHome m3;

    m3 = m2;

    string myhome = "JX-PX-001";
    MyHome m4(myhome);

    const MyHome m1("h1");
    m1.show();

    std::cout << gt1(1,2) << std::endl;

    compareTo(1,2, gt1<int>);
    compareTo(1,2, eq1<int>);

    LT<MyHome> lt;
    GT<MyHome> gt;
    EQ<MyHome> eq;

    compareTo<MyHome, EQ<MyHome>>(m1, m2, eq);
    compareTo<MyHome>(m1, m2, gt);
    compareTo(m1, m2, eq);
    compareTo(m1, m2, lt);
    compareTo(m1, m2, gt);

    std::cout <<lt(m2, m3) << std::endl;
    std::cout <<gt(m2, m4) << std::endl;

    MyHome m5(std::move(m4));

    ContainerHome containerHome1(&m5);
    containerHome1.show();
    ContainerHome containerHome2(&m3);
    containerHome1.show();
    ContainerHome containerHome3(&m2);
    containerHome1.show();
#endif

#ifdef FALSE
    Game g1("g1");
    Game g2 = g1; //这里为啥走的是拷贝构造呢
    Game g3(g2); //拷贝构造
    Game g4(std::move(g1)); //移动构造
    Game g5(Game("g5")); //拷贝构造
    Game g6 = std::move(g5); //移动赋值

    isEqual<char> charEqual;
    isEqual<int> intEqual;
    isEqual<int*> pintEqual;
    isEqual<const int> cintEqual;
    isEqual<const int*> cpintEqual;

    int a = 10;
    int b = 20;
    int c = 100;

    const int ca = a;
    const int cb = b;
    const int cc = c;

    const int* pca = &ca;
    const int* pcb = &cb;
    const int* pcc = &cc;

    const int* & ppca = pca;
    const int* & ppcb = pcb;
    const int* & ppcc = pcc;

    bool equal1 = charEqual.compare('c', 'c');
    std::cout << "char queal :" << equal1 << std::endl;

    bool equal2 = intEqual.compare(a,b);
    std::cout << "int queal :" << equal2 << std::endl;

    bool equal3 = pintEqual.compare(&a, &c);
    std::cout << "pint queal :" << equal3 << std::endl;

    bool equal4 = cintEqual.compare(a,b);
    std::cout << "cpint queal :" << equal4 << std::endl;

    bool equal5 = cpintEqual.compare(ppcb,ppcc);
    std::cout << "cpint queal :" << equal5 << std::endl;
#endif

#ifdef FALSE
    // 设置随机数种子，确保每次运行生成不同的随机数

    std::cout << "-----------" << std::endl;
    skyScene skyScene;
    getScene(skyScene);

    std::cout << "-----------" << std::endl;
    waterScene waterScene;
    getScene(waterScene);

    std::cout << "-----------" << std::endl;
#endif

#ifdef FALSE
    Game g1("g1");
    Game gx(Game("gxx"));
    Game g2 = g1; //这里为啥走的是拷贝构造呢
    Game g3(g2); //拷贝构造
    Game g4(std::move(g1)); //移动构造
    Game g5(Game("g5")); //拷贝构造
    Game g6 = std::move(g5); //移动赋值
#endif

#ifdef FALSE
    int a = 10;
    int b = 20;
    int c = 30;

    const int* pa = &a; //pa (const int*)
    int* const pb = &b; //pb (int*)
    int const* pc = &c; //pc (int const*)
    const int * const pa = &a; //pa(const int* const)
    *pa = 100;

    int * tmp;

    std::cout << *pa << std::endl;
    std::cout << *pb << std::endl;
    std::cout << *pc << std::endl;

    std::cout << "---------------" << std::endl;
    *pa = 30; // error
    *pb = 20; // ok
    *pc = 10; // error
#endif

#ifdef FALSE
    int a = 10;
    int b = 20;
    int c = 30;


    const int& ra = a;
    int & rb = b;
    const int& rc = c;

    std::cout << ra << std::endl;
    std::cout << rb << std::endl;
    std::cout << rc << std::endl;

    std::cout << "-------------" << std::endl;

    ra = b; // error
    rb = c; // ok
    rc = a; // error

    std::cout << ra << std::endl;
    std::cout << rb << std::endl;
    std::cout << rc << std::endl;
#endif

#ifdef FALSE
    int a = 10;
    int b = 20;
    int c = 30;

    const int * cpa = &a;
    const int * cpb = &b;
    const int * cpc = &c;

    int *pa = &a;
    int *pb = &b;
    int *pc = &c;

    const int * const * cppa =  &cpa;
    int const * const * cppb =  &cpa;

    cppb = &cpb; // ok
    *cppb = cpb; //error
    **cppb = 30; //error

    /*
    int* pa = &a;
    int* pb = &b;
    int* pc = &c;

    int** ppa = &pa;
    int** ppc = &pc;
    std::cout << pa << std::endl;
    std::cout << ppa << std::endl;
    std::cout << typeid(pa).name() << std::endl;
    std::cout << typeid(ppa).name() << std::endl;
    std::cout << pb << std::endl;

    int** const ppb = ppa;
    std::cout << *ppb << std::endl;
    *ppb = pb;
    std::cout << *ppb << std::endl;

    std::cout << pa << std::endl;
    std::cout << &pa << std::endl;
    */
#endif

#ifdef FALSE
    int a = 20;
    int && ra = std::move(20);
    std::cout << ra << std::endl;
    ra = a;
    std::cout << ra << std::endl;
    std::cout << &ra << std::endl;
#endif

#ifdef FALSE
    int* pa = new int(20);
    std::cout << *pa << std::endl;
    std::cout << pa << std::endl;
    std::cout << &pa << std::endl;
    delete pa;

    std::cout << *pa << std::endl;
    std::cout << pa << std::endl;
    std::cout << &pa << std::endl;

    int* pb = new int[]{10,20,30,40};
    std::cout << *(pb) << std::endl;
    std::cout << *(pb+1) << std::endl;
    std::cout << *(pb+2) << std::endl;
    std::cout << *(pb+3) << std::endl;
    std::cout << *(pb+4) << std::endl;
    delete[] pb;
    std::cout << *(pb) << std::endl;
    std::cout << *(pb+1) << std::endl;
    std::cout << *(pb+2) << std::endl;
    std::cout << *(pb+3) << std::endl;
    std::cout << *(pb+4) << std::endl;
#endif

    return 0;
}

