//
// Created by xiaowei003 on 2024/11/1.
//

#include "Container.h"
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <deque>
#include <forward_list>
#include "../util/util.h"
#include <utility>
#include <queue>
#include <algorithm>
#include <ratio>
#include <chrono>
#include <array>
#include <functional>

int main(void)
{
    /**
    std::list<char> col1;
    for(char c='a';c <= 'z'; ++c){
        col1.push_back(c);
    }

    std::copy(col1.begin(), col1.end(), std::ostream_iterator<char>(std::cout, " "));
     **/

    /**
    std::multiset<std::string>col1{
            "BEIJING", "SHANGHAI", "HANGZHOU", "NANJING", "CHENGDU"
    };

    //排序
    std::copy(col1.begin(), col1.end(), std::ostream_iterator<std::string>(std::cout, " "));

    std::multiset<std::string>::iterator it = col1.begin();
    std::cout << *it++ << std::endl;
    std::cout << *it++ << std::endl;
    std::cout << *it++ << std::endl;
    std::cout << *it++ << std::endl;
    std::cout << *it++ << std::endl;

    std::copy(col1.begin(), col1.end(), std::ostream_iterator<std::string>(std::cout, " "));
     **/

    /**
    std::multimap<std::string, int> col1;
    col1.insert(std::make_pair<std::string,int>("maiev", 20));
    col1.insert(std::make_pair<std::string,int>("FENG", 21));
    col1.insert(std::make_pair<std::string,int>("ZENG", 22));

    auto it = col1.begin();
    std::cout << "name is : " <<(*it).first;
    std::cout << " and age is : " <<(*it).second << std::endl;
    it++;
    std::cout << "name is : " <<(*it).first;
    std::cout << " and age is : " <<(*it).second << std::endl;
    it++;
    std::cout << "name is : " <<(*it).first;
    std::cout << " and age is : " <<(*it).second << std::endl;

    for(auto pair : col1){
        std::cout << "name is : " << pair.first;
        std::cout << " and age is : " << pair.second << std::endl;
    }

    std::copy(col1.begin(), col1.end(), std::ostream_iterator<std::pair<std::string, int>(std::cout, " ")); error
     **/

    /**
    std::cout << "------------------------------------" << std::endl;
    std::cout << "set" << std::endl;
    std::set<std::string> fruit;
    fruit.emplace(std::string("APPLE"));
    fruit.emplace(std::string("BANANA"));
    fruit.emplace(std::string("ORANGE"));
    fruit.emplace(std::string("JUSTIC"));
    std::copy(fruit.begin(), fruit.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "------------------------------------" << std::endl;
    std::cout << "unordered_set" << std::endl;
    std::unordered_set<std::string>col1{
            "BEIJING", "SHANGHAI", "HANGZHOU", "NANJING", "CHENGDU"
    };

    //排序
    std::copy(col1.begin(), col1.end(), std::ostream_iterator<std::string>(std::cout, " "));

    std::unordered_set<std::string>::iterator it = col1.begin();
    std::cout << *it++ << std::endl;
    std::cout << *it++ << std::endl;
    std::cout << *it++ << std::endl;
    std::cout << *it++ << std::endl;
    std::cout << *it++ << std::endl;

    std::cout << "------------------------------------" << std::endl;
    std::cout << "unordered_map" << std::endl;

    std::unordered_map<std::string, int> col2;
    col2.insert(std::make_pair<std::string,int>("maiev", 20));
    col2.insert(std::make_pair<std::string,int>("FENG", 21));
    col2.insert(std::make_pair<std::string,int>("ZENG", 22));

    for(auto pair : col2){
        std::cout << "name is : " << pair.first;
        std::cout << " and age is : " << pair.second << std::endl;
    }

    std::cout << std::endl;

    std::cout << "------------------------------------" << std::endl;
    std::cout << "unordered_multiset" << std::endl;
    std::unordered_multiset<std::string>col3{
            "BEIJING", "SHANGHAI", "HANGZHOU", "NANJING", "CHENGDU"
    };

    col3.insert(std::string("HANGZHOU"));
    std::copy(col3.begin(), col3.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "------------------------------------" << std::endl;
    std::cout << "unordered_multimap" << std::endl;
    std::unordered_multimap<std::string, int> col4;
    col4.insert(std::make_pair<std::string,int>("maiev", 20));
    col4.insert(std::make_pair<std::string,int>("FENG", 21));
    col4.insert(std::make_pair<std::string,int>("ZENG", 22));

    for(auto pair : col4){
        std::cout << "name is : " << pair.first;
        std::cout << " and age is : " << pair.second << std::endl;
    }

    std::cout << std::endl;
     **/

    /**
    std::cout << "------------------------------------" << std::endl;
    std::cout << "priority queue" << std::endl;
    std::priority_queue<int> pq;
    pq.push(30);
    pq.push(10);
    pq.push(5);
    pq.push(40);
    pq.push(20);

    while(!pq.empty()){
        std::cout << pq.top() << std::endl;
        pq.pop();
    }

    std::cout << "------------------------------------" << std::endl;
    std::cout << "set" << std::endl;
    typedef std::set<int> Intset;
    Intset col1{1,23,2,3,3,4,54,5};
    Intset col2;
//    std::copy(col1.begin(), col1.end(), std::ostream_iterator<int> (std::cout, " "));
//    std::copy(col1.begin(), col1.end(), back_inserter(col2));

    PRINT_CONTAINER(col1, "can u fell");
    **/

    /**
    std::vector<int> col3;
    std::back_insert_iterator<std::vector<int>> it(col3);
    *it++ = 3;
    *it++ = 4;
    *it++ = 5;
    std::copy(col3.begin(), col3.end(), std::ostream_iterator<int> (std::cout, " "));
     */

    /**
    auto a = std::min({1,3,3,23,2,2,3,23,23,2});

    std::vector<int> col1{1,2};
    std::vector<int> col2;

    std::swap(col1, col2);
    std::copy(col1.begin(), col1.end(), std::ostream_iterator<int> (std::cout, " "));
    std::copy(col2.begin(), col2.end(), std::ostream_iterator<int> (std::cout, " "));
    **/

    /**
    using namespace std::rel_ops;
    X x1(1), x2(2);
    if (x1 < x2){
        std::cout << "x1 < x2" << std::endl;
    }

    if (!(x1 == x2)){
        std::cout << "x1 != x2" << std::endl;
    }
    **/

    /**
    typedef std::ratio<5,3> FiveThirds;
    std::cout << FiveThirds::den << FiveThirds::num << std::endl;
    std::chrono::duration<int, std::ratio<1,3>> d1(1);
    std::chrono::duration<int, std::ratio<1,5>> d2(2);
    **/

    /**
    std::deque<int> col1((std::istream_iterator<int>(std::cin)), (std::istream_iterator<int>()));
    std::copy(col1.begin(), col1.end(), std::ostream_iterator<int> (std::cout, " "));
     **/

    /**
     * std::array
     * initialization std::array
     * swap and move semantics
     * array operations:
     * array<int,N> c;
     * array<int,N> c(c2);
     * array<int,N> c= c2;
     * array<int,N> c(rv);
     * array<int,N> c = rv;
     * array<int,N> c = initlist;
     *
     * c.empty()
     * c.size()
     * c.max_size()
     * c1 == c2;
     * c1 != c2;
     * c1 >= c2;
     * c1 <= c2;
     * c1 > c2;
     * c1 < c2;
     *
     * assign:
     * c = c2;
     * c.fill(n);
     * c1.swap(c2);
     * std::swap(c1, c2);
     *
     * access:
     * c.front();
     * c.back();
     * c[idx];
     * c.at(idx);
     * c.data() first element pointer
     *
     * ierator:
     * c.begin()
     * c.end();
     * c.cbegin();
     * c.cend();
     * c.rbegin();
     * c.rend();
     * c.crbegin();
     * c.crend();
     *
     * tuple inferface
     * tuple_size()
     * tuple_element()
     * get<>()
     *
     */

    /**
     * std::array --example
    std::cout << "--------------" << std::endl;
    std::array<int, 5> arr={1,2,3};
    std::array<int, 5> arr2(arr);
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int> (std::cout, " "));
    std::copy(arr2.begin(), arr2.end(), std::ostream_iterator<int> (std::cout, " "));
    std::array<int, 5> arr3(std::move(arr2)); // arr2 is always with {1,2,3,4,5}

    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int> (std::cout, " "));
    std::copy(arr2.begin(), arr2.end(), std::ostream_iterator<int> (std::cout, " "));
    std::copy(arr3.begin(), arr3.end(), std::ostream_iterator<int> (std::cout, " "));

    std::cout << "--------------" << std::endl;
    std::cout << arr.size() << std::endl;
    std::cout << arr2.size() << std::endl;
    std::cout << arr3.size() << std::endl;

    std::cout << arr3.at(0) << std::endl;
    std::cout << arr3.front() << std::endl;
    std::cout << arr3.back() << std::endl;

    typedef std::array<std::string, 5> FiveStrings;
    FiveStrings a = {"a", "b", "c", "d", "m"};
    std::cout << std::tuple_size<std::array<int, 5>>::value << std::endl;
    std::cout << typeid(std::tuple_element<1, FiveStrings>::type).name();
    std::cout << std::get<1>(a) << std::endl;

    std::cout << (negate<int>()(1)) << std::endl;

    **/

    /**
    std::vector<int> vc, vc2;
    std::copy(arr.begin(), arr.end(), back_inserter(vc));
    std::cout << vc.size() << std::endl;

    vc2 = std::move(vc);
    std::cout << vc.size() << std::endl;
    std::cout << vc2.size() << std::endl;
     **/

    return 0;
}
