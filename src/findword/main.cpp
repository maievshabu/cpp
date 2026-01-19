//
// Created by redredmaple on 2026/1/19.
//
#include "word.h"

int main(){
    std::cout << "this is a article about ai!!now, Count the words and sort the word accord the Alpha ";

    word word;
    word.read("../word.txt");
    word.show();
    std::cout << word.count() << std::endl;
    word.result();

    return 0;
}
