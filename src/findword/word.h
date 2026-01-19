//
// Created by redredmaple on 2026/1/19.
//

#ifndef C11_WORD_H
#define C11_WORD_H
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class word {
public:
    word() =default;
    void read(const std::string&);
    void show();
    int count(){
        return container.size();
    }
    void result();
    ~word(){}
private:
    std::vector<string> container;
    std::map<string,int> countMap;
};


#endif //C11_WORD_H
