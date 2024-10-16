using namespace std;
#include <iostream>
#include <string>

class MyString{
public:
    MyString(){ cout << "construct" << endl; }
    MyString(std::string name) : _name(name){cout << "construct" << endl;}
    MyString(MyString const & myString ) : _name(myString._name){ cout << "copy contruct" <<endl;}
    MyString& operator= (MyString const & other);
    void get_name(MyString const& other);

    template <typename T>
    friend T& xx(T const& other);
private:
    std::string _name;
};

template<typename T>
T& xx(T const& other)
{
    T a = T();
    a._name = other._name;
    cout << "T empalte " << endl;

    return a;
}

MyString& MyString::operator= (MyString const & other)
{
    cout << "copy assgin"  << endl;
    if (this != &other){
        _name = other._name;
    }

    return *this;
}

void MyString::get_name(const MyString &other) {
    cout << "name :" << _name << endl;
    cout << "other :" << other._name << endl;
}

#include "../lib/conn.h"

int main() {
    std::cout << "test main " << std::endl;
    test_conn2("can u fell!!");

    return 0;
}
