//
// Created by xiaowei003 on 2024/9/4.
//

#include "A.h"
#include <typeinfo>
#include <vector>
#include <string>

using namespace std;

namespace A06{
    int test() {
        f<A>(10);
        f<int>(1.11);
        A a;
        A b;
        int c;
        float e;
        double f;

        std::cout<< "a::" << typeid(a).name() << std::endl;
        std::cout<< "c::" << typeid(c).name() << std::endl;
        std::cout << typeid(a).hash_code() <<std::endl;
        std::cout << (typeid(a) == typeid(c)  ? 1 : 0) << std::endl; // 0

        auto i = c;
        decltype(i) j = 0;
        decltype( e + j) h;

        cout << typeid(i).name() << endl; //i
        cout << typeid(j).name() << endl; //i
        cout << typeid(h).name() << endl;

        using size_t = decltype(sizeof(0));
        using ptrdiff_t = decltype((int*)0 - (int*)0);
        using nullptr_t = decltype(nullptr);


        vector<int> vc;

        vc.push_back(1);
        vc.push_back(2);
        vc.push_back(3);

        typedef decltype(vc.begin()) vctype;

        cout << "-----------------------" << endl;
        for(vctype t = vc.begin(); t < vc.end(); t++){
            cout << *t <<endl;
        }

        cout << "-----------------------" << endl;
        for(auto t = vc.begin(); t < vc.end(); t++){
            cout << *t <<endl;
        }

        cout << "-----------------------" << endl;

//        string who("maiev");;;;
//
//        decltype(anon_s) as;
//        as[0].id.key = decltype(anon_e)::K1;
//        as[0].id.name = who;
//
//        cout << "as.key::" << (as[0].id.key) << endl;
//        cout << "as.name::" << (as[0].id.name) << endl;

        int aa = 1;
        float bb = 1.2f;
        float cc ;
        Sum(aa, bb, cc);

        cout << cc << endl;

        return 0;
    }
}
