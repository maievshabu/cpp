//
// Created by redredmaple on 2026/1/6.
//

#include <iostream>
#include "Student.h"
#include "Report.h"

using namespace std;
void test(string);

void menu(string title){
    std::cout << title << std::endl;
    std::cout << "0: show all"<< std::endl;
    std::cout << "1: search id "<< std::endl;
    std::cout << "2: search no"<< std::endl;
    std::cout << "q: quit"<< std::endl;
}

int main(){
    menu("Welcome to my room!!!");

    Report report;

    char choice;
    int id;
    bool isOk = false;
    string no;
    report.read();
    while(std::cin >> choice){
        switch(choice){
            case '1':
                std::cout << "Enter your id: " << std::endl;
                std::cin >> id;
                report.search(id);
                break;
            case '2':
                std::cout << "Enter your No: " << std::endl;
                std::cin >> no ;
                report.search(no);
                break;
            case '0':
                std::cout << "show all student" << std::endl;
                report.result();
                break;
            case 'q':
            default:
                isOk = true;
                report.quit();
                break;
        }

        if (isOk){
            break;
        }
    }

    return 0;
}

void test(string filename){
//    ifstream fs(filename);
//    if (!fs){
//        std::cerr << "open file errors!!" << std::endl;
//    }
//
//    vector<Student> vc;
//    vc.reserve(10);
//    Student s1;
//    while(fs >> s1){
//        std::cout << s1 << std::endl;
//        vc.push_back(s1);
//    }
//
//    std::cout << vc.size() << std::endl;
}

