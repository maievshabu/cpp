//
// Created by xiaowei003 on 2024/8/25.
//

#include "A.h"
#include <vector>
#include <map>

namespace A05{
    using namespace std;


    void test(){
        int a {1};
        int b[] = {2,4,6};
        vector<int> c{1,2,3};

        map<int ,float> d= {
                {1,0.1f},
                {2,0.2f},
                {3,0.3f},
                {4,0.4f},
        };

        int* i = new int {1};

        A aa{
                {"maiev", boy},
                {"nico", girl},
                {"nick", boy},
                {"tu", girl},
                {"maiev", boy}};

        cout << "A05::TEST" << endl;

        Fun({1,2,3});
        Fun({});

        cout << "mydata:::" << endl;
        Mydata mydata;

        mydata[{2,3, 5}] = 7;
        mydata[{1,4, 5, 8}] = 4;
        mydata.print();

        cout << "mydata:::" << endl;

        const int x = 1024;
        const int y = 10;

        char ca = x;
        char* cb = new char(1024);

//        char cc = {x};
        char cd = {y};
//        unsigned char ce{-1};

        float f {7};
//        int g{1.0f};

        float *h = new float(1e48);

        float ii = 1.2l;


    }

}
