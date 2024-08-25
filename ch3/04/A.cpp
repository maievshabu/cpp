//
// Created by xiaowei003 on 2024/8/25.
//

namespace A04{
    using namespace std;
    #include "A.h"
    struct Rational1{
        int num;
        int den;
        Rational1(int n = 0, int d = 1): num(n), den(d){
            cout << __func__<< "(" << num << "/" << den << "}" <<endl;
        }
    };

    struct Rational2{
        int num;
        int den;
        explicit Rational2(int n = 0, int d = 1): num(n), den(d){ //禁止隐式构造
            cout << __func__<< "(" << num << "/" << den << "}" <<endl;
        }
    };

    void display1(Rational1 ra){
        cout << "Numberator" << ra.num << "Denominator" << ra.den << endl;
    }

    void display2(Rational2 rb){
        cout << "Numberator" << rb.num << "Denominator" << rb.den << endl;
    }

    void test(){
//        Rational1 r1_1 = 11;
//        Rational1 r1_2(12);
//
//        Rational2 r2_1 = 11;
//        Rational2 r2_2(12);
//
//        display1(1);
//        display2(2);
//        display2(Rational2(2));

        B c;
        A ct(c);
//        A ct2 = c;
        A ct3 = static_cast<A>(c);

//        Func(c);
        Func(ct);

    }
}
