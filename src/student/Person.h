//
// Created by redredmaple on 2026/1/7.
//

#ifndef STUDENT_PERSON_H
#define STUDENT_PERSON_H
#include <string>
#include <iostream>
using namespace std;

class Person {
public:
    Person() = default;
    Person(string first, string last): _lastName(last),_firstName(first){}
    void set(string first, string last){
        _firstName = first;
        _lastName = last;
    }
    friend ostream& operator<<(ostream&os, const Person& p){
        return os << p._firstName << " " << p._lastName;
    }
private:
    string _firstName;
    string _lastName;
};

#endif //STUDENT_PERSON_H
