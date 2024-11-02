//
// Created by xiaowei003 on 2024/10/31.
//

#ifndef UNTITLED_UTIL_H
#define UNTITLED_UTIL_H
#include <iterator>
#include <string>

class Util{
public:

};

template <typename Container>
void PRINT_CONTAINER(Container container, const std::string outstr = ": ")
{
    std::cout << outstr << " ";
    for( const auto& elem : container){
        std::cout << elem << " ";
    }

    std::cout << std::endl;

//    using Iterator = typename Container::iterator;
//    std::cout << msg ;
//    for (Iterator it = container.begin(); it != container.end(); ++it) {
//        std::cout << *it << " ";
//    }
//    std::cout << std::endl;
}

template <typename T>
void PRINT(const std::string& msg){
    std::cout << msg << std::endl;
}

#endif //UNTITLED_UTIL_H
