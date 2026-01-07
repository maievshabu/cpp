//
// Created by redredmaple on 2025/8/25.
//

#ifndef MAIEV_USER_H
#define MAIEV_USER_H
#include <iostream>

using std::string;
class User{
public:
    User(){
        _name = string("");
        _age = 0;
    }
    User(string name, int age):_age(age),_name(name){}
    friend ostream& operator<<(ostream& os, const User& user){
        os << user._name << " " << user._age;
        return os;
    }
private:
    string _name;
    int _age;
};

#endif //MAIEV_USER_H
