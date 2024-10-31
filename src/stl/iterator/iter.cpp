//
// Created by xiaowei003 on 2024/10/29.
//

#include <iostream>
#include "iter.h"
#include "MyIter.h"
#include <vector>
#include <iterator>
#include "../array/array.hpp"
#include <unordered_set>

int main(void) {
    std::vector<int> vc{1, 2, 3, 3, 4, 1};
    std::vector<std::string> vc2{"aa", "bb", "cc"};
    /**
    back_insert_iterator<std::vector<int>> b1(vc);
    b1++;
    *b1 = 20;
    b1++;
    *b1 = 30;
    print_it(vc.begin(), vc.end());

    front_insert_iterator<std::vector<int>> f1(vc);
    print_it(vc.begin(), vc.end());

    back_inserter(vc) = 22;
    back_inserter(vc) = 22;
    back_inserter(vc) = 22;
    print_it(vc.begin(), vc.end());

    front_inserter(vc) = 1;
    front_inserter(vc) = 1;
    front_inserter(vc) = 1;
    print_it(vc.begin(), vc.end());

    inserter(vc, vc.begin()) = 2;
    inserter(vc, vc.end()) = 2;
    print_it(vc.begin(), vc.end());

    MyIter_x<int *> begin_x1(vc.data());
    MyIter_x<int *> end_x1(vc.data() + vc.size());
    print_it(begin_x1, end_x1, "int*: ");
    typedef MyIter_x<int*> xx;
    xx begin_x1(vc.data());
    xx end_x1(vc.data() + vc.size());
    print_it(begin_x1, end_x1, "int*:");

    MyIter_x<int> begin(vc.data());
    MyIter_x<int> end(vc.data() + vc.size());
    print_it(begin, end, "int: ");
    foo(begin, end);

    MyIter_x<std::string> sb1(vc2.data());
    MyIter_x<std::string> se1(vc2.data() + vc2.size());
    print_it(sb1, se1, "string: ");
    foo(sb1, se1);

    MyIter_x<std::string*> sb2(vc2.data());
    MyIter_x<std::string*> se2(vc2.data() + vc2.size());
    print_it(sb2, se2, "string*: ");
    foo(sb2, se2);

    MyIter_x<std::vector<std::string>::iterator> sb3(vc2.begin());
    MyIter_x<std::vector<std::string>::iterator> se3(vc2.end());
    print_it(sb3, se3, "string iterator: ");
    foo(sb3, se3);
     **/

    std::unordered_set<int> col1;
    asso_insert_iterator<decltype(col1)> iter(col1);

    std::copy(vc.begin(), vc.end(), asso_inserter(col1));

    asso_inserter(col1) = 11;
    asso_inserter(col1) = 12;
    asso_inserter(col1) = 11;
    asso_inserter(col1) = 14;

    std::cout << "----------------" << std::endl;
    ostream_iterator<int>os(cout, " ");
    copy(col1.begin(), col1.end(), os);

    return 0;
}

