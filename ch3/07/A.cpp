//
// Created by xiaowei003 on 2024/9/8.
//

#include "A.h"
using namespace std;

namespace A07 {
    int test()
    {
        int si = 1; //int
        int &sj = si; //int &
        int *sp = &si; //int *;
        auto p2 = sp; // int *
        auto *p3 = sp; // int *
        auto *p4 = sp; //int *;

        decltype(sp) p5 = &si; //int *
        decltype(sp) *p6 = &sp; // int **

        cout << "-----------------------" << endl;
        cout << "&si::" << &si << endl;
        cout << "&sj::" << &sj << endl;
        cout << "&sp::" << &sp << endl; //sp 指向 si ,sj
        cout << "&p2::" << &p2 << endl;
        cout << "&p3::" << &p3 << endl;
        cout << "&p4::" << &p4 << endl;
        cout << "&p5::" << &p5 << endl;
        cout << "&p6::" << &p6 << endl;
        cout << "*p6::" << *p6 << endl;
        cout << "**p6::" << **p6 << endl;

        return 0;
    }
}
