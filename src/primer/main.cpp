//
// Created by redredmaple on 2026/1/8.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

extern int xa;

int main() {
    cout << "c++ primer!!!!" << endl;
    {
//        string line, word;
//        while(getline(cin, line)){
//            int count = 0;
//            istringstream stream(line);
//            while(stream >> word){
//                ++count;
//            }
//            std::cout << "has :" << count << std::endl;
//        }

        int val1 = 512, val2=1024;
        ostringstream  format_message;
        format_message << "val1: " << val1 << "\n"
                       << "val2: " << val2 << "\n";
        std::cout << format_message.str() << std::endl;

        istringstream input_string(format_message.str());
        string dump;
        input_string >> dump >> val1 >> dump >> val2;
        cout << val1 << " " << val2 << endl;
    }
#ifdef TRUE
    {
        string filename("../aa.txt");
        ifstream fs(filename.c_str());
        if (!fs){
            std::cerr << "open errors!!" << std::endl;
            return 0;
        }
        if (fs.good()){
            std::cout << "can open" << std::endl;
        }

        string cs;
        while(getline(fs, cs)){
            std::cout << cs << std::flush;
        }

        if (fs.is_open()){
            fs.close();
            std::cout << "open files!!!" << std::flush;
        }
        std::cout << fs.rdstate() << std::endl;
    }
    {
        int zero = 0;
        const int c_ival = 0;
//        pi = zero;
//        pi = c_ival;

        void * pi;
        pi = 0;
        string s("hello world");
        string* sp = &s;
        std::cout << sp << std::endl;
        pi = &s;
//        pi = &zero;

        const int a1 = 10;
        const int a2 = 20;
        const int * pa = &a1;
//        *pa = 20; //???
        pa = &a2; //ok

        int *aa = static_cast<int*>(pi);
        std::cout << aa << std::endl;

        char* str = "Java";
        std::cout << strlen(str) << std::endl;
        const char* cp = "c++";
//        cp[0] = 'A';
        cp = str;//

//        char * ssp = const_cast<char*>(cp);
//        ssp[0] = 'X';
//        std::cout << ssp << std::endl;

        int a[3][4] = {
                {1,2,3,4},
                {1,1,1,1},
                {5,6,7,8},
        };

        int (*ia)[4];
        ia = &a[1];

        auto x = (1+1, 2);
        std::cout << x << std::endl;

        std::cout << "-------" << std::endl;

        int *iia = &a[2][0];
        int * end = iia + 4;
        for(; iia < end; iia++){
            std::cout << *iia << std::endl;
        }
//        for (int j = 0; j < 4; j++) {
//            std::cout << *(iia + j) << std::endl;
//        }
    }
    {
//        bitset<10> b(123);
//        bitset<10> b("0101010101");
        bitset<4> b(string("01010101"),0 ,4);
        std::cout << b << std::endl;
        std::cout << b[1].flip() << std::endl;
        std::cout << b.flip(2) << std::endl;
        std::cout << b.to_ullong() << std::endl;
        std::cout << b.any() << std::endl;
        std::cout << b.count() << std::endl;
        std::cout << b.test(3) << std::endl;
    }

    string word;
//    while(cin >> word){
//        cout << word << endl;
//    }

    vector<string> line;
//    while(getline(cin, word)){ //ctrl + D to end!!!
//        line.push_back(word);
//    }

    line.push_back("hello");
    line.push_back("world");
    line.push_back("mike");
    line.push_back("Ykc");

    {
        const int a = 10;
        const int c = 20;
        const int *pa = &a; // const pa->
        pa = &c;

        int b = 20;
        int *const pb = &b; //const pb
        *pb = 30;
        std::cout << a <<std::endl;
    }

    {

    }

    vector<string>::iterator it = line.begin();
    while(it != line.end()){
        std::cout << *it++ << std::endl;
    }

    std::for_each(line.begin(), line.end(), [](string val){
        std::cout << val << std::endl;
    });
#endif
    return 0;
}