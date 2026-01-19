//
// Created by redredmaple on 2026/1/19.
//

#include "word.h"

void word::read(const std::string& filename) {
    fstream fs(filename);
    std::string words;
    while(fs >> words){
       container.emplace_back(words);
    }
}

void word::show(){
    for(const string& str: container){
        std::cout << str << std::endl;
        int count = std::count(container.begin(), container.end(), str);
        countMap[str] = count;
//        countMap.insert(std::make_pair(str,count));
    }
}

void word::result() {

    int digital = 0; //数字
    int b = 0; //标点符号
    int str = 0; //字符

    string pd = "0123456789";
    string pb = ",.!?"; //标点符号
    string pa="{}[]()"; //括号
    string pc = "$#@!~%^&*"; //其他字符串

    for(auto& _countMap: countMap){
        std::cout << _countMap.first << " :" << _countMap.second << std::endl;
    }
}
