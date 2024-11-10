//
// Created by xiaowei003 on 2024/11/6.
//

#include "Algo.h"
#include <numeric>
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include "../util/Util.h"
#include <random>
#include <chrono>

using namespace std;

std::vector<int> vc{1,2,3,3,3,2,2,32,3,1, 11};
list<int> col1;

int main(void){
    std::cout << "hello Algo" << std::endl;
    test_algo();

    return 0;
}

void print(int elem)
{
    std::cout << elem << " ";
}

class Print{
public:
    bool operator()(int elem){
        std::cout << elem << " ";
        return true;
    }
};

template <typename T>
class AddValue{
private:
    T value;
public:
    AddValue(const T& val) : value(val){}
    void operator()(T& elem) const{
        elem += value;
    }
};

void test_for_each()
{
    vector<int> col1;
    INSERT_ELEMENTS(col1,1,9);
    PRINT_ELEMENTS(col1, "col1: ");

    for_each(col1.begin(), col1.end(), [](int& elem){
        elem += 10;
    });
    PRINT_ELEMENTS(col1, "col1 add ten: ");

    for_each(col1.begin(), col1.end(),[](int elem){
        std::cout << elem << " ";
    });

    std::cout << std::endl;

    for_each(col1.begin(), col1.end(), print);
    std::cout << std::endl;

    for_each(col1.begin(), col1.end(), std::bind(Print(), std::placeholders::_1));
    std::cout << std::endl;

    for_each(col1.begin(), col1.end(), [=](int& elem){
        elem += *(col1.begin());
    });

    for_each(col1.begin(), col1.end(), AddValue<int>(10));
    PRINT_ELEMENTS(col1, "add first: ");

    for_each(col1.begin(), col1.end(), AddValue<int>(*(col1.begin())));
    PRINT_ELEMENTS(col1, "add begin: ");

    transform(col1.begin(), col1.end(), col1.begin(), [](int elem){
        return elem + 10;
    });
    PRINT_ELEMENTS(col1, "col1 transform: ");

    double mv = for_each(col1.begin(), col1.end(), MeanValue(0,0));
    std::cout << "mean value :" << mv;
}

void test_count()
{
    vector<int> col1;
    int num;
    INSERT_ELEMENTS(col1,1,9);
    PRINT_ELEMENTS(col1, "col1: ");

    num = count(col1.begin(), col1.end(), 9);
    std::cout << "num of 9 equal  is: " << num << std::endl;

    num = count_if(col1.begin(), col1.end(), [](int elem){
        return elem > 4;
    });

    std::cout << "num of > 4 is: " << num << std::endl;

}

void test_min_max()
{
    deque<int>col1;
    INSERT_ELEMENTS(col1, 2, 6);
    INSERT_ELEMENTS(col1, -3, 6);
    PRINT_ELEMENTS(col1, "col1: ");

    std::cout << "minmum:" << *(min_element(col1.begin(), col1.end())) <<std::endl;
    std::cout << "maxmum:" << *(max_element(col1.begin(), col1.end())) <<std::endl;

    auto mm = minmax_element(col1.begin(), col1.end());
    std::cout << "min-max" << *(mm.first) << "][:" << *(mm.second) << std::endl;

    std::cout << "abs minmum:" << *(min_element(col1.begin(), col1.end(), absLess)) <<std::endl;
    std::cout << "abs maxmum:" << *(max_element(col1.begin(), col1.end(), absLess)) <<std::endl;
}

void test_find()
{
    list<int> col2{3, 2, 11, 22};
    INSERT_ELEMENTS(col1, 1, 9);
    PRINT_ELEMENTS(col1, "col1: ");

    list<int>::iterator pos1;
    pos1 = find(col1.begin(), col1.end(), 4);

    list<int>::iterator pos2;
    if (pos1 != col1.end()){
        pos2 = find(++pos1, col1.end(), 4);
    }

    std::cout << "4 and 4 range[]:";

    if (pos1 != col1.end() && pos2 != col1.end()){
        copy(--pos1, ++pos2, std::ostream_iterator<int>(cout, " "));
        std::cout << std::endl;
    }

    pos1 = find_if(col1.begin(),col1.end(), std::bind(greater<int>(), std::placeholders::_1, 3));
    cout << "> 3 :" << *pos1 << " : distance to end"  << distance(pos1, col1.end()) << std::endl;

    pos1 = find_if(col1.begin(),col1.end(), [](int elem){
        return elem > 5;
    });

    cout << "> 5 :" << *pos1 << ": distance to end"  << distance(pos1, col1.end()) << std::endl;

    pos1 = find_if_not(col1.begin(), col1.end(), std::bind(less<int>(), std::placeholders::_1, 10));
    cout << "first value > =10 : " << *pos1 << std::endl;

    pos1 = std::adjacent_find(col1.begin() ,col1.end()); //查找相邻元素是否==
    if (pos1 != col1.end()){
        std::cout << "Found" << std::endl;
    }

    PRINT_ELEMENTS(col2, "col2: ");
//    pos1=std::find_end(col1.begin(), col1.end(), col2.begin(), col2.end()); //查找子集
    pos1=std::find_first_of(col1.begin(), col1.end(), col2.begin(), col2.end(), [](int a, int b){
         return true;
    });
    pos1=std::find_first_of(pos1, col1.end(), col2.begin(), col2.end()); //

    if (pos1 != col1.end()){
        std::cout << "pos : " << *pos1 << " and distance : " << distance(col1.begin(), pos1) << std::endl;
    }
}

void test_search()
{
    deque<int> col1;
    col1 = {1, 2, 7, 7, 6 , 3, 9 ,5,7 ,7,7, 3, 6};
    PRINT_ELEMENTS(col1, "col1: ");

    auto last = std::unique(col1.begin(), col1.end());
    col1.erase(last, col1.end());
    PRINT_ELEMENTS(col1, "col1 unique:");

    std::sort(col1.begin(), col1.end());
    PRINT_ELEMENTS(col1, "col1 sort:");

    auto lx = std::unique(col1.begin(), col1.end());
    col1.erase(lx, col1.end());
    PRINT_ELEMENTS(col1, "col1 unique:");

    std::cout << "is sorted : " << std::is_sorted(col1.begin(), col1.end()) << std::endl;
    auto pos = std::is_sorted_until(col1.begin(), col1.end());
    std::cout << "pos at: " << distance(pos, col1.end()) << std::endl;

//    unsigned int data = -100000;
//    unsigned long long data2 = -10;
//
//    std::cout << "unsgined max::" << UINT_MAX << std::endl;
//    std::cout << "max::" << INT_MAX << std::endl;
//
//    if (data & 0X80000){
//        data |= 0XFF000000;
//        std::cout << "data::" << data << std::endl;
//    }
//
//    auto tt = data & 0x800000;
//    auto tt2 = data2 & 0x800000;
//
//    std::cout << "tt:::" << tt  <<"] tt2:: " << tt2 << std::endl;

            //   deque<int>::iterator pos;
//   pos = search_n(col1.begin(), col1.end(),3,7);
//
//   if (pos != col1.end()){
//      cout << "three consecutive element with value 7"
//        << " start with " << distance(col1.begin(), pos) + 1
//       << " .element" << endl;
//   }else{
//        cout << "no consecutive elements with value 7 found" << std::endl;
//   }
//
//    pos = search_n(col1.begin(), col1.end(),4,0, [](int elem, int value){
//        return elem % 2 == 1;
//    });

//    pos = search_n_if(col1.begin(), col1.end(),4, [](int elem) {
//        return elem % 2 == 1;
//    });
//
//    if (pos != col1.end()){
//        std::cout << "first four consecutive odd element :";
//        for(int i= 0;i < 4; ++i,++pos){
//            std::cout << *pos <<  " ";
//        }
//    }else{
//        std::cout << "no consecutive elements with value 7 found" << std::endl;
//    }

    std::cout << endl;

    vector<int> col2{5,7};
    PRINT_ELEMENTS(col2, "col2: ");
    vector<int> col3;

//    pos = std::search(col1.begin(), col1.end(), col2.begin(), col2.end(), [](int i, int j){
//        return i == j;
//    });
//
//    if (pos != col1.end()){
//        std::cout << "found as pos : " << (pos - col1.begin()) << std::endl;
//    }

    col3.resize(col1.size() + col2.size());
    std::merge(col1.begin(), col1.end(), col2.begin(), col2.end(), col3.begin());
    PRINT_ELEMENTS(col3, "col3: ");
}

void test_equal()
{
    std::vector<int> vc{1,2,3,3,3,2,2,32,3,1, 11};
    std::vector<int> vc2(vc.size());
    PRINT_ELEMENTS(vc2, "col2: ");

    auto bool_flag = std::equal(vc.begin(), vc.end(), vc2.begin());
    std::cout << bool_flag << std::endl;
    std::sort(vc.begin(), vc.end());
    PRINT_ELEMENTS(vc, "col1:");
    auto pos = std::equal_range(vc.begin(), vc.end(), 11);
    std::cout << "pos:" <<( pos.first - vc.begin()) << ": " << (pos.second - vc.begin()) << std::endl;
    std::copy(pos.first, pos.second, std::ostream_iterator<int>(std::cout , " "));

    if (std::all_of(vc.begin(), vc.end(), std::bind(greater<int>(), std::placeholders::_1, 1))){
        std::cout << "all greanter 1" << std::endl;
    }else{
        std::cout << "not all greater 1" << std::endl;
    }

    if (std::any_of(vc.begin(), vc.end(), std::bind(greater<int>(), std::placeholders::_1, 1))){
        std::cout << "any greanter 1" << std::endl;
    };

    if (binary_search(vc.begin(), vc.end(), 5)){
        std::cout <<  "5 Found"<< std::endl ;
    }else{
        std::cout <<  "5 not Found"<< std::endl ;
    }

    vc={1,2,3,4,5,6,7,8,9};
    if (!std::none_of(vc.begin(), vc.end(), isOdd)){
        std::cout << "none of elem is odd!" << std::endl;
    };

    std::random_shuffle(vc.begin(), vc.end());
    PRINT_ELEMENTS(vc, "vc random shuffle: ");

    //第三小的元素
//    std::nth_element(vc.begin(), vc.begin() +5, vc.end());
    std::nth_element(vc.begin(), vc.begin() +5, vc.end(), myfunction);
    std::cout << vc.at(5) << std::endl;
    PRINT_ELEMENTS(vc, "vc: ");
}

void test_fill()
{
    std::vector<int> vc2(vc.size());
    std::fill(vc2.begin(), vc2.end(), 10);
    PRINT_ELEMENTS(vc2, "col2: ");
}

void test_copy()
{
    std::vector<int> vc2(vc.size());
    PRINT_ELEMENTS(vc2, "col2: ");
//    std::copy_backward(vc.begin(), vc.end(), vc2.end());
//    std::copy_if(vc.begin(), vc.end(), vc2.begin(), [](int elem){
//        return elem % 2 == 0;
//    });

    std::copy_n(vc.begin(),3, vc2.begin());
    PRINT_ELEMENTS(vc2, "vc2: ");
}

void test_generate()
{
    forward_list<int> list(10);
    int i = 0;
//    std::generate(list.begin(), list.end(), [&](){
//        return ++i;
//    });

//    std::generate(list.begin(), list.end(), randomNumber);
//    std::generate_n(list.begin(), 10, randomNumber);
    std::generate_n(list.begin(),10, UniqueNumber);
    PRINT_ELEMENTS(list, "list: ");

    forward_list<int> list2{11, 12, 22};

    if (std::includes(list.begin(), list.end(), list2.begin(), list2.end())){
        std::cout << "list includes list2"<< std::endl;
    }

    int first[] = {5,10,15,20,25};
    int second[]={50,40,30,20,10};
    std::vector<int>v(10);
    std::vector<int>::iterator it;

    std::sort(first, first + 5);
    std::sort(second, second + 5);

    it = std::copy(first, first + 5, v.begin());
    std::copy(second, second + 5, it);

    PRINT_ELEMENTS(v, "v: ");

    std::inplace_merge(v.begin(), v.begin()+5, v.end());

    PRINT_ELEMENTS(v, "v: ");
}

void test_heap()
{
    PRINT_ELEMENTS(vc, "vc: ");
    if (!std::is_heap(vc.begin(), vc.end())){
        std::make_heap(vc.begin(), vc.end());
    }
    PRINT_ELEMENTS(vc, "vc-make-heap: ");

//    sort_heap(vc.begin(), vc.end());

    PRINT_ELEMENTS(vc, "vc-sort-heap: ");
    std::cout << "poping out elments:";

    while(!vc.empty()){
        std::pop_heap(vc.begin(), vc.end());
        std::cout << " " << vc.back();
        vc.pop_back();
    }

    std::cout << std::endl;

    PRINT_ELEMENTS(vc, "vc-after-pop: ");

    std::cout << std::endl;

    auto pos = std::is_heap_until(vc.begin() ,vc.end());
    std::cout << "pos :" << std::distance(vc.begin(), pos) << std::endl;
}

void test_part()
{
    std::array<int, 7> foo { 1,2,3,4,5,6,7};
    std::array<int, 7> bar;
    bar.fill(0);
    if (std::is_partitioned(foo.begin(), foo.end(), isOdd)){
        std::cout << "is partitioned!!!" << std::endl;
    }
    PRINT_ELEMENTS(foo, "foo-before-part:");
    auto pos = std::partition_point(foo.begin(), foo.end(), isOdd);
    std::cout << "pos:" << *pos << std::endl;

    pos = std::partition(foo.begin(), foo.begin() + 3, isOdd);
    PRINT_ELEMENTS(foo, "foo-after-part:");

    std::partition_copy(foo.begin(), foo.end(), bar.begin(), bar.end(), isOdd);
    PRINT_ELEMENTS(bar, "bar:-partion-copy: ");

    if (std::is_partitioned(foo.begin(), pos, isOdd)){
        std::cout << "is partitioned!!!" << std::endl;
    }

    PRINT_ELEMENTS(foo.begin(), pos,"foo first: ");
    PRINT_ELEMENTS(pos, foo.end(),"foo second: ");

    PRINT_ELEMENTS(pos, foo.end(),"foo point: ");

    std::partial_sort(pos, foo.end(), foo.end());
    std::partial_sort(foo.begin(), foo.end(), foo.end(), myfunction);
    std::sort(foo.begin(), foo.end(), myfunction);
    PRINT_ELEMENTS(foo.begin(), foo.end(),"foo partial_sort: ");
    std::partial_sort_copy(foo.begin(), foo.begin() + 3, bar.begin(), bar.end(), myfunction);
    PRINT_ELEMENTS(bar.begin(), bar.end(),"foo partial_sort_copy: ");

    pos = std::stable_partition(foo.begin(), foo.end(), isOdd);
    PRINT_ELEMENTS(foo.begin(), pos, "foo [stale-partition]: ");
    PRINT_ELEMENTS(pos, foo.end(), "foo [stale-partition]: ");

    std::stable_sort(foo.begin(), foo.end());
    PRINT_ELEMENTS(foo, "FOO[stable-sort]:");

    int x = 10, y = 20;
    std::cout << "x= " << x << " y= " << y << std::endl;
    std::swap(x, y);
    std::cout << "x= " << x << " y= " << y << std::endl;
    std::vector<int> foo1(4,x), bar1(4,y), zoo(4);
    std::swap(foo1, bar1);

    PRINT_ELEMENTS(foo1, "foo1: ");
    PRINT_ELEMENTS(bar1, "bar1: ");
    std::swap_ranges(foo1.begin(), foo1.end(), bar1.begin());
    PRINT_ELEMENTS(foo1, "foo1[swap-ranges]: ");
    PRINT_ELEMENTS(bar1, "bar1[swap-ranges]: ");

//    std::transform(foo1.begin(), foo1.end(), ostream_iterator<int>(cout," "), isOdd);

    std::transform(foo1.begin(), foo1.end(), bar1.begin(), zoo.begin(), xx<int>);
    PRINT_ELEMENTS(zoo, "zoo [plus]: ");

    int myints[] = {10, 20, 20,20, 30, 30, 20, 20, 10};
    std::vector<int>vc(myints,myints+9);
    std::vector<int>v2(9);
    std::vector<int>::iterator it;
    PRINT_ELEMENTS(vc, "vc: ");
    it = std::unique(vc.begin(), vc.end());
    PRINT_ELEMENTS(vc, "vc[unique]: ");

    std::unique_copy(vc.begin(), vc.end(), v2.begin());
    PRINT_ELEMENTS(v2, "v2[unique-copy]: ");

//    vc.resize(std::distance(vc.begin(), it));
//    std::unique(vc.begin(), vc.end(), myfunction);
//    PRINT_ELEMENTS(vc, "vc[unique]: ");

//    std::stable_sort(foo.begin(), foo.end(), isOdd);
//    PRINT_ELEMENTS(foo, "FOO[stable-sort-2]:");
}

void test_permutation()
{
    std::array<int, 3> foo{1,2,3};
    std::array<int, 3> bar{1,4, 10};

    if (std::is_permutation(foo.begin(), foo.end(), bar.begin())){
        std::cout << "bar is a permutaion of foo" << std::endl;
    }

    auto match = std::mismatch(foo.begin(), foo.end(), bar.begin());
    std::cout << *(match.first) << *(match.second) << std::endl;
    std::cout << distance(foo.begin(), match.first) << distance(bar.begin(), match.second) << std::endl;

    std::sort(foo.begin(), foo.end());
//    std::reverse(foo.begin(), foo.end());
    do{
//        std::next_permutation(foo.begin(), foo.end());
        PRINT_ELEMENTS(foo, "foo: ");
//    }while(std::prev_permutation(foo.begin(), foo.end()));
    }while(std::next_permutation(foo.begin(), foo.end()));

    std::iter_swap(foo.begin(), bar.begin()+1);
    PRINT_ELEMENTS(foo, "foo: ");
    PRINT_ELEMENTS(bar, "bar: ");

    char foo1[]="Apple";
    char bar1[]="apartment";
    std::cout << std::boolalpha;
    std::cout << "compareing foo and bar lexicographically(foo<bar): " << std::endl;
    std::cout << "using default comparision:(operator<) " << std::endl;
    std::cout << std::lexicographical_compare(foo1, foo1+5, bar1, bar1+9) << std::endl;
    std::cout << "using mycomp as comparision object: " << std::endl;
    std::cout << std::lexicographical_compare(foo1, foo1+5, bar1, bar1+9,mycomp) << std::endl;
}

void test_bound()
{
    int myints[] ={10,20,30,30,20,10,10,20};
    std::vector<int>v{myints,myints+8};
    std::sort(v.begin(), v.end());

    std::vector<int>::iterator low, up;
    low = std::lower_bound(v.begin(), v.end(), 20);
    up = std::upper_bound(v.begin(), v.end(), 20);

    PRINT_ELEMENTS(v, "vector: ");

    std::cout << "lower-bound at pos: " << distance(v.begin(),low) <<std::endl;
    std::cout << "upper-bound at pos: " << distance(v.begin(),up) <<std::endl;

    std::vector<int> v1(v.size()*2);
    std::merge(myints, myints+8, v.begin(),v.end(), v1.begin());

    PRINT_ELEMENTS(v1, "v1: ");

    std::cout << "move ranges : " << std::endl;
    v1.resize(v.size()*3);
    std::move_backward(v.begin(), v.end(), v1.end());
//    std::move(v.begin(), v.end(), v1.begin());
//    PRINT_ELEMENTS(v, "v: ");
    PRINT_ELEMENTS(v1, "v1: ");

//    std::cout << "move container: " << std::endl;
//    v = std::move(v1);
//    PRINT_ELEMENTS(v, "v: ");
//    PRINT_ELEMENTS(v1, "v1: ");

}

void test_remove()
{
    int myints[] = {10,20,3,30,20,10,10,20, 11};
    int *pbegin = myints;
    int *pend = myints + sizeof(myints)/ sizeof(int);
    PRINT_ELEMENTS(myints, "myints:");

    std::vector<int> vc(9);

//    pend = std::remove(pbegin, pend, 20);
//    auto pos = std::remove_copy(pbegin, pend, vc.begin(), 20);
//    auto pos = std::remove_copy_if(pbegin, pend, vc.begin(), isOdd);
//    PRINT_ELEMENTS(vc, "vc :");
//    auto pos = std::remove_if(pbegin, pend, isOdd);
//    PRINT_ELEMENTS(pbegin, pos, "myints:");

    std::replace(pbegin, pend, 20, 11);
    PRINT_ELEMENTS(myints, "myints: ");

    std::replace_if(pbegin, pend, isOdd, 5);
    PRINT_ELEMENTS(myints, "myints: ");

    std::replace_copy(pbegin, pend, vc.begin(), 20, 11);
    PRINT_ELEMENTS(vc, "vc: ");

    std::replace_copy_if(pbegin, pend, vc.begin(), isOdd, 11);
    PRINT_ELEMENTS(vc, "vc: ");

    std::reverse(vc.begin(), vc.end());
    PRINT_ELEMENTS(vc, "vc: ");

    std::reverse_copy(vc.begin(), vc.end(), ostream_iterator<int>(cout, "-"));
    std::cout << std::endl;
    PRINT_ELEMENTS(vc, "vc: ");

    std::rotate(vc.begin(), vc.begin()+3, vc.end());
    PRINT_ELEMENTS(vc, "vc: ");
    std::rotate_copy(vc.begin(), vc.begin()+3, vc.end(), ostream_iterator<int>(cout, "-"));
    std::cout << std::endl;
    PRINT_ELEMENTS(vc, "vc: ");

    auto pos = std::search(pbegin, pend, vc.begin(), vc.end());
    if (pos != pend){
        std::cout << *pos << " and distance to begin is :" << std::distance(pbegin, pos) << std::endl;
    }else{
        std::cout << "no search!" << std::endl;
    }
}

void test_set()
{
    std::set<int> s1{1,2,3,4,5};
    std::set<int> s2{2,3,4, 6};
    std::set<int> s3;
    std::set<int> s4;
    std::set<int> s5;
    std::set<int> s6;

    PRINT_ELEMENTS(s1, "s1 [init]: ");
    PRINT_ELEMENTS(s2, "s2 [init]: ");

    std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin())); //注意这里s3迭代器
    PRINT_ELEMENTS(s3, "s1 and s2 [difference]: "); //差集[在第一个集合，但是不在第二个集合种]

    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s4, s4.begin())); //注意这里s3迭代器
    PRINT_ELEMENTS(s4, "s1 and s2 [intersection]: "); //交集

    std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s5, s5.begin())); //注意这里s3迭代器
    PRINT_ELEMENTS(s5, "s1 and s2 [union]: "); //合集

    std::set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s6, s6.begin())); //注意这里s3迭代器
    PRINT_ELEMENTS(s6, "s1 and s2 [symmetric_diffenence]: "); //对称差集[在一个集合,但是并不在另一个集合种]

    std::array<int,5> foo{1,2,3,4,5};
    PRINT_ELEMENTS(foo, "foo: ");
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(foo.begin(), foo.end(), std::default_random_engine(seed));
    PRINT_ELEMENTS(foo, "foo [shuffle]: ");
//    shuffle(s1.begin(), s1.end(), std::default_random_engine(seed)); //ERROR...
//    PRINT_ELEMENTS(s1, "s1 [shuffle]: ");
}

void test_algo()
{
    /**
    test_for_each();
    test_count();
    test_min_max();
    test_search();
    test_equal();
    test_find();
    test_generate();
    test_heap();
    test_part();
    test_permutation();
    test_bound();
    test_remove();
    test_set();
    **/

    test_part();
}


