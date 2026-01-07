//
// Created by redredmaple on 2025/3/29.
//

#include "Object.h"
#include <ctime>

int rand(int base)
{
    // 设置随机数种子，确保每次运行生成不同的随机数
    std::srand(static_cast<unsigned>(std::time(0)));
    return std::rand() % base;
}


void Role::battle(Object& obj) {
    std::cout << "person battle:" << std::endl;

    int scale = rand(20);

    if (skill > obj.skill){
        life -= scale;
    }
}

void Enermy::battle(Object& obj) {
    std::cout << "enermy battle" << std::endl;
}