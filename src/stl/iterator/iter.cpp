//
// Created by xiaowei003 on 2024/10/29.
//

#include <iostream>
#include "iter.h"
#include "MyIter.h"
#include <vector>
#include <iterator>

int main(void)
{
    std::vector<int> vc{1, 2, 3, 3, 4, 1};
    std::vector<std::string> vc2{"aa", "bb", "cc"};

    MyIter_x<int*> begin_x1(vc.data());
    MyIter_x<int*> end_x1(vc.data() + vc.size());
    print_it(begin_x1, end_x1, "int*: ");

    MyIter_xx<int> begin(vc.data());
    MyIter_xx<int> end(vc.data() + vc.size());
    print_it(begin, end, "int: ");

    MyIter_x<std::vector<int>::iterator> b1(vc.begin());
    MyIter_x<std::vector<int>::iterator> e1(vc.end());
    print_it(b1, e1, "iterator: ");

    return 0;
}
