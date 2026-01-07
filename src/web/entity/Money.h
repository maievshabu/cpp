//
// Created by redredmaple on 2025/8/25.
//

#ifndef MAIEV_MONEY_H
#define MAIEV_MONEY_H
#include <iostream>

using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;
class Money{
public:
    Money(){
        _type = string("");
        _amount = 0;
    }
    Money(string type, int amount):_amount(amount),_type(type){}
    friend ostream& operator<<(ostream&, const Money&);
private:
    string _type;
    int _amount;
};

ostream& operator<<(ostream& os, const Money& money){
    os << "" << money._type << " " << money._amount;
    return os;
}

#endif //MAIEV_MONEY_H
