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

//    test_array();
//    test_vector();
//    test_deque();
//    test_list();
//    test_forward_list();
//    test_set();
    test_map();

    return 0;
}

void test_array(){
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
}

void test_vector(){
//    std::vector<int> vc, vc2;
//    std::copy(arr.begin(), arr.end(), back_inserter(vc));
//    std::cout << vc.size() << std::endl;
//
//    vc2 = std::move(vc);
//    std::cout << vc.size() << std::endl;
//    std::cout << vc2.size() << std::endl;
    std::vector<bool> vc(5, true);

    std::copy(vc.begin(), vc.end(), ostream_iterator<bool>(cout, " "));
    std::cout<< std::endl;
    vc[1].flip();
    std::copy(vc.begin(), vc.end(), ostream_iterator<bool>(cout, " "));
    std::cout<< std::endl;
    vc[2].flip();
    std::copy(vc.begin(), vc.end(), ostream_iterator<bool>(cout, " "));
    std::cout<< std::endl;
    vc.flip();
    std::copy(vc.begin(), vc.end(), ostream_iterator<bool>(cout, " "));
    std::cout<< std::endl;
}

void test_deque(){
    std::deque<int> col1{1,2,3,4};
    col1.insert(col1.begin(), {1,2,3});
    PRINT_CONTAINER(col1, "col1:");
    std::deque<int> col2 = std::move(col1);
    PRINT_CONTAINER(col1, "col1 after move:");
    PRINT_CONTAINER(col2, "col2:");
    col2.clear();
    PRINT_CONTAINER(col2, "col2 after clear:");
    col2.push_front(1);
    col2.push_front(2);
    col2.push_front(3);
    PRINT_CONTAINER(col2, "col2 push front :");
    std::cout << col2.size() << std::endl;
    col2.resize(5, 0);
    PRINT_CONTAINER(col2, "col2 resize :");
    col2.erase(next(col2.begin()), prev(col2.end()));
    PRINT_CONTAINER(col2, "col2 erase [begin+1, end-1] :");
    col1.swap(col2);
    PRINT_CONTAINER(col2, "col1 swap col2 :");
}

void test_list(){
    std::list<int> col1;
    col1.assign({1,2,3,4,5});
    PRINT_CONTAINER(col1, "col1:");
    col1.erase(next(col1.begin()));
    PRINT_CONTAINER(col1, "col1 erase:");
    col1.insert(next(col1.begin()), {2,2});
    col1.emplace(prev(col1.end()), 11);
    col1.emplace(prev(col1.end()), 22);
    PRINT_CONTAINER(col1, "col1 emplace:");

    std::list<int>col2(col1);
    PRINT_CONTAINER(col2, "col2 :");
    col2.clear();
    PRINT_CONTAINER(col2, "col2 clear:");
    col2.push_front(1);
    col2.insert(prev(col2.begin()), {1,2,3});
    PRINT_CONTAINER(col2, "col2 push:");
}

void test_forward_list(){
    std::forward_list<int> list1 = {1,2,3,4};
    std::forward_list<int> list2 = {4,4,77,88,99};
    PRINT_CONTAINER(list1, "list:");

    list1.insert_after(list1.begin(), list2.begin(), list2.end());
    PRINT_CONTAINER(list1, "list-insert:");

    std::forward_list<int>::iterator it = list1.begin();

    list1.splice_after(it, list2);
    PRINT_CONTAINER(list1, "list-splice:");

    list1.remove(3);
    PRINT_CONTAINER(list1, "list-remove:");

    list1.unique();
    PRINT_CONTAINER(list1, "list-unique:");

    list1.reverse();
    PRINT_CONTAINER(list1, "list-reverse:");

    list1.erase_after(list1.begin(), list1.end());
    PRINT_CONTAINER(list1, "list-erase:");

    list1.insert_after(list1.begin(), list2.begin(), list2.end());
    PRINT_CONTAINER(list1, "list-insert:");
};

void test_set(){
    std::set<int, greater<int>>col1;

    col1.insert({1,2,34,5,6});
    col1.insert(6);
    PRINT_CONTAINER(col1, "set insert:");

    auto status = col1.insert(1);
    if (status.second){
        std::cout << "success" << std::endl;
    }else{
        std::cout << "fail!!!" << std::endl;
    }

//    typedef std::set<int, RuntimeCmp> Intset;
//    RuntimeCmp ro(RuntimeCmp::REVERSE);
//    Intset col2(ro);
    std::set<int, classcomp> col2;
    std::set<int, classcomp> col3;
    bool (*fncomp_str)(int, int) = fncomp;
//    std::set<int, decltype(fncomp_str)> col2(fncomp_str);
//    std::set<int, bool(*)(int, int)> col2(fncomp_str);
//    std::set<int, RuntimeCmp> col2(RuntimeCmp::REVERSE);

    col2.insert(1);
    col2.insert(5);
    col2.insert(3);

//    set<int> col2(col1.cbegin(), col1.cend());
//    std::copy(col2.begin(), col2.end(), std::ostream_iterator<int>(cout, " "));
//    std::cout << std::endl;
    PRINT_CONTAINER(col2, "col2:");

    col2.erase(1);
    col2.erase(col2.begin(), col2.find(3));
    PRINT_CONTAINER(col2, "col2 erase:");

    col3 = col2;

    if (col3.key_comp() == col2.key_comp()){
        std::cout << "value-comp====" << std::endl;
    }else{
        std::cout << "value-comp" << std::endl;
    }
}

bool find_value(const std::pair<std::string, double>& elem, std::string name){
    return elem.first == name;
}

template<typename T, typename U>
void fq(const typename std::map<T, U>::value_type & elem){
    std::cout << "map : (" << elem.first <<" " <<  elem.second << ")"<< std::endl;
};

void test_map(){
   map<std::string, double> col1{
           {"tim", 9.9},
           {"struppi", 11.77},
   };

   col1["maiev"] = 22.0;
    col1["tim"] = 0.11;

    std::for_each(col1.begin(), col1.end(), [](std::map<const std::string, double>::value_type & elem){
        elem.second *= 2;
    });

    std::for_each(col1.begin(), col1.end(), [](const std::map<std::string, double>::value_type &elem){
        std::cout << elem.first << ": " << elem.second << std::endl;
    });

    auto pos = col1.find("tim");
    if (pos != col1.end()){
        std::cout << "found : (" << pos->first <<" " <<  pos->second << ")"<< std::endl;
    }

    auto bb = std::bind(fq<std::string, double>, std::placeholders::_1);
    for_each(col1.begin(), col1.end(), bb);

    auto posVal = std::find_if(col1.begin(), col1.end(), std::bind(find_value, std::placeholders::_1, "tim"));
    if (posVal != col1.end()){
        std::cout << "found : (" << posVal->first <<" " <<  posVal->second << ")"<< std::endl;
    }else{
        std::cout << "not found " << std::endl;
    }

    typedef std::map<std::string, std::string, RuntimeStringCmp> stringstringMap;
    RuntimeStringCmp cmp(RuntimeStringCmp::NOCASE);
    stringstringMap col2(cmp);
    col2.insert(make_pair<std::string, std::string>("Deutschland", "beijing"));
    col2.insert(make_pair<std::string, std::string>("deutsch", "nanchan"));
    col2.insert(make_pair<std::string, std::string>("Haken", "shanghai"));
    col2.insert(make_pair<std::string, std::string>("gehen", "go"));
    col2.insert(make_pair<std::string, std::string>("Gehen", "go-11"));
    for_each(col2.begin(), col2.end(), std::bind(fq<std::string, std::string>, std::placeholders::_1));
}