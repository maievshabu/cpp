//
// Created by xiaowei003 on 2024/8/25.
//

namespace A03{
    using namespace std;
#include "A.h"
    A getTemp(){
        A tmp;
        std::cout<<"resource from " << __func__ << hex << tmp.d << std::endl;

        return tmp;
    }

    int tx()
    {
        return 1;
    }


    void runCode(int && m) {cout<<"rvalue ref" <<endl;}
    void runCode(int & m) {cout<<"lvalue ref" <<endl;}
    void runCode(const int && m) {cout<<"const rvalue ref" <<endl;}
    void runCode(const int & m) {cout<<"const lvalue ref" <<endl;}

    template <typename T>
    void perfectForward(T && t) { runCode(forward<T> (t));}

    template<typename T, typename U>
    void perfectForward(T && t, U &Func){
        cout << t << "\t forward..." <<endl;
        Func(forward<T> (t));
    }

    void RunCode(double  && m){}
    void RunHome(double  && h){}
    void RunComp(double  && c){}

    int test(void) {

        int a,b;
        const int c = 1;
        const int d = 0;

        perfectForward(a);
        perfectForward(move(b));
        perfectForward(c);
        perfectForward(move(d));

        perfectForward(1.5, RunComp);
        perfectForward(8, RunCode);
        perfectForward(1.5, RunHome);

//        A a;
//        std::cout<<"resource from " << __func__ << hex << a.d << std::endl;
//
//        A b = getTemp();
//        std::cout<<"resource from " << __func__ << hex << b.d << std::endl;
//
//        int && ta = tx();
//        std::cout<<"resource from " << __func__ << hex << ta << std::endl;
//
//        int *pa = new int(1);
//        int *pb = pa;
//
//        std::cout<<"&pa" << pa <<std::endl;
//        std::cout<<"&pb" << pb <<std::endl;

//        delete pa;
//
//        std::cout<<"pb" << *pb <<std::endl;

        return 0;
    }
}
