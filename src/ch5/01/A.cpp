//
// Created by xiaowei003 on 2024/9/8.
//

#include "A.h"
#include <memory>

const static int Male = 0;
const static int Female = 1;

enum class weapon {General, Light, Medium, Heavy} weapon;

int chA01::test(){
    enum weapon w = weapon::General;
    Killer notCool(Type::GENERAL, Category::MACHINEGUN);

    if (notCool.type >= Type::GENERAL){
        cout << "it is not a general!!" << endl;
    }

    if (notCool.category >= Category::MACHINEGUN){
        cout << "it is not a machinegun!!" << endl;
    }

    cout << is_pod<Type>::value <<endl;
    cout << is_pod<Category >::value <<endl;

    cout << sizeof(C::C1) << endl;
    cout << (unsigned int ) D::Dbig << endl;
    cout << sizeof(D::D1) << endl;
    cout << sizeof(D::D2) << endl;

    unique_ptr<int> up1(new int(11));
//        unique_ptr<int> up2 = up1;
    cout << *up1 << endl;

    unique_ptr<int> up3 = move(up1);
//        cout << *up1 << endl;
    cout << *up3 << endl;
    up3.reset();
//        cout << *up3 << endl;
    up1.reset();

    shared_ptr<int> sp1 (new int(12));
    shared_ptr<int> sp2 (sp1);

    cout << "shared ptr::" << *sp1 <<endl;
    cout << "shared ptr::" << *sp2 <<endl;

    weak_ptr<int> wp  = sp1;
    Check(wp);

    sp1.reset();
    cout << "shared ptr::" << *sp2 <<endl;
    Check(wp);

    sp2.reset();
    Check(wp);

    double ff = 11.111;
    int fi = static_cast<double>(ff);
    cout << "fi::" << fi<< endl;

    const int *p = &fi;
    int *p1 = const_cast<int *>(p);


//        int *pxx = new int;
//        cout <<"pxx ::: " << *pxx <<endl;
//        pxx += 10;
//        cout <<"pxx ::: " << *pxx <<endl;
//        pxx -= 10;
//        cout <<"pxx ::: " << *pxx <<endl;
//        *ppx = 100;
//        cout <<"pxx ::: " << *pxx <<endl;

    return 0;
}