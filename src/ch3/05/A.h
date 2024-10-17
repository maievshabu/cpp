//
// Created by xiaowei003 on 2024/8/25.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>

enum Gender {boy, girl};
class A {
public:
    A(initializer_list<pair<string,Gender>> l){
        auto i = l.begin();
        for(;i != l.end(); ++i)
            data.push_back(*i);
    }

private:
    vector<pair<string,Gender>> data;
};


void Fun(initializer_list<int >iv){

}

class Mydata{
public:
    Mydata & operator [] (initializer_list<int> l){
        for(auto i = l.begin(); i != l.end(); i++){
            idx.push_back(*i);
        }

        return *this;
    }

    Mydata & operator = (int v){
        if (idx.empty() != true){
            for (auto i = idx.begin(); i != idx.end(); i++){
                d.resize((*i > d.size()) ? *i : d.size());
                d[*i - 1] = v;
            }

            idx.clear();
        }

        return *this;
    }

    void print(){
        for ( auto i = d.begin(); i != d.end(); i++){
            std::cout << *i << " ";
        }
        std::cout << std::endl;
    }

private:
    vector<int> idx;
    vector<int> d;
};


vector<int> Func() {return {1,2,3};}

#endif //UNTITLED_A_H
