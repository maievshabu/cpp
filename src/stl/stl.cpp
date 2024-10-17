//
// Created by xiaowei003 on 2024/10/17.
//

#include "stl.h"
#include <vector>

void stl::test_stl()
{
    std::vector<int> vc{1,1,2,3};
    vc.push_back(1);
//    vc.push_back({2,2,4});

    std::vector<int>::iterator it = vc.begin();
    std::cout << *it << std::endl;

    std::cout << vc.at(3) << std::endl;
    std::cout << "can u fell???" << std::endl;
}

