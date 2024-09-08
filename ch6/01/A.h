//
// Created by xiaowei003 on 2024/9/8.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H


namespace ch601{
    class A {
    };

    int test();

    constexpr int GetConst() { return 1;}

    void ConstLess(int cond){
        int arr[GetConst()] = {0};

        enum {e1 = GetConst(), e2};

        switch(cond) {
            case GetConst():
                break;
            default:
                break;
        }
    }

//    template <int i = v0 | v1>
//            void likeConst(){}

    enum bitSet{
        vo = 1 << 0,
        v1 = 1 << 1,
        v2 = 1 << 2,
        vMAX = 1 << 3
    };

    const bitSet operator |(bitSet x, bitSet y){
        return static_cast<bitSet> ( ( (int) x| y) & (vMAX- 1));
    }

    constexpr int f();
    int a = f();
    const int b = f();
//    constexpr int c = f(); //先调用了，f定义未知
    constexpr int f() {return 1;}
    constexpr  int d =  f();

    const int e() { return 1;}
//    constexpr int g() { return e();} //不能调用函数

    int g = 3;
//    constexpr int h () { return g;} //error
//    constexpr int k(int x) { return x = 1;} error

    struct Date{
        constexpr Date(int y, int m , int d):year(y),month(m),day(d){}
        constexpr int GetYear() { return year;}
        constexpr int GetMonth() { return month;}
        constexpr int GetDay() { return day;}

    private:
        int year;
        int month;
        int day;
    };

    struct NoLiteral{
        NoLiteral(){ i = 5;}
        int i;
    };

    template <typename T> constexpr T ConstExp(T t){ return t;}

    void gg(){
        NoLiteral n1;
        NoLiteral nl1 = ConstExp(n1);
//        constexpr NoLiteral n2 = ConstExp(n1);
        constexpr int a = ConstExp(1);
    }

    constexpr int Fibonacci(int n){
        return (n == 1) ? 1 : ((n == 2) ? 1 : Fibonacci( n -1 ) +Fibonacci( n -2));
    }

    template <long num>
    struct Fibo{
            static const long val = Fibo<num -1 > ::val + Fibo<num -2>::val;
    };

    template<> struct Fibo<2>{ static const long val = 1;};
    template<> struct Fibo<1>{ static const long val = 1;};
    template<> struct Fibo<0>{ static const long val = 0;};

};

#endif //UNTITLED_A_H
