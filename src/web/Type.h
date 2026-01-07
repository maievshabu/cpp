//
// Created by redredmaple on 2025/8/25.
//

#ifndef MAIEV_TYPE_H
#define MAIEV_TYPE_H
#include <iostream>
#include <vector>
#include <list>

using std::string;
using std::vector;

template<typename T>
class List{
private:
    using list = vector<T>;
    list listData;
public:
    void add(const T& data){
        listData.push_back(data);
    }

    friend ostream& operator<<(ostream& os, const List& list){
        for(auto v : list.listData){
            os << v << " " << endl;
        }

        return os;
    }

    void print()const{
        cout << " data: ";
        for(auto v : listData){
             cout << v << " " << endl;
        }
    }
};


#endif //MAIEV_TYPE_H
