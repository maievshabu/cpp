//
// Created by xiaowei003 on 2024/11/6.
//

#ifndef UNTITLED_ALGO_H
#define UNTITLED_ALGO_H
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


class Algo {

};

/**
 *
 * Nomodifying algorithms
 * input and forward iteraors
 * for_each()
 * count()
 * count_if()
 * min_element()
 * max_element()
 * minmax_element()
 *
 * find()
 * find_if()
 * find_if_not()
 *
 * search_n()
 * find_end()
 * find_first_of()
 * adjacent_find()
 *
 * equal()
 * is_permutation()
 *
 * mismatch()
 * lexicographical_compare()
 * is_stored()
 * is_sorted_until()
 * is_partitioned()
 * partition_point()
 * is_heap()
 * is_heap_until()
 * all_of()
 * any_of()
 * none_of()
 *
 * modifying algorithms
 *
 * for_each()
 * copy()
 * copy_if()
 * copy_n()
 * copy_backward()
 * move()
 * move_backward()
 * transform()
 * merge()
 * swap_ranges()
 * fill()
 * fill_n()
 * generate()
 * generate_n()
 * iota()
 * replace()
 * replace_if()
 * replace_copy()
 * replace_copy_if()
 *
 * removing algorithms
 * remove()
 * remove_if()
 * remove_copy()
 * remove_copy_if()
 * unique()
 * unique_copy()
 *
 *
 * mutating algorithms
 *
 * sorting algorithms
 * reverse()
 * reverse_copy()
 * rotate()
 * rotate_copy()
 * next_permutation()
 * prev_permutation()
 * shuffle()
 * random_shuffle()
 * partition()
 * stable_partition()
 * partition_copy()
 *
 * sort()
 * stable_sort()
 * partial_sort()
 * partial_sort_copy()
 * nth_element()
 * partition()
 * stable_partition()
 * partition_copy()
 * make_heap()
 * push_heap()
 * pop_heap()
 * sort_heap()
 * is_sorted()
 * is_sorted_until()
 * is_partitioned()
 * pritition_until()
 * is_heap()
 * is_heap_until()
 *
 * sorted-range algorithms
 *
 * binary_search()
 * includes()
 * lower_bound()
 * upper_bound()
 * equal_range()
 * merge()
 * set_union()
 * set_intersection()
 * set_difference()
 * set_symmetric_difference()
 * inplace_merge()
 * partition_point()
 *
 * numeric algorithms
 * accumulate()
 * inner_product()
 * adjacent_difference()
 * partial_sum()
 */

template<typename InputIterator>
inline void PRINT_ELEMENTS(InputIterator first, InputIterator end, const std::string& opercstr)
{
    std::cout << opercstr << " ";
    typedef typename std::iterator_traits<InputIterator>::value_type vtype;
    std::copy(first, end, std::ostream_iterator<vtype>(std::cout, " "));
    std::cout << std::endl;
}

template<typename T>
inline void INSERT_ELEMENTS(T& col, int first, int last)
{
    for(int i = first; i <= last; ++i){
        col.insert(col.end(), i);
    }
}

template<typename T>
inline void PRINT_ELEMENTS(const T& col1, const std::string& optcstr="")
{
    std::cout << optcstr;
    for(auto elem : col1){
        std::cout << elem << " ";
    }

    std::cout << std::endl;
}

template<typename T>
inline void PRINT_MAPPEND_ELEMENTS(const T& col1, const std::string& optcstr = "")
{
    std::cout << optcstr;
    for(auto elem : col1){
        std::cout <<"[" << elem.first << " ,"
                <<"]" << elem.second<< " ]";
    }

    std::cout << std::endl;
}

bool absLess(int elem1, int elem2)
{
    return abs(elem1) < abs(elem2);
}

class MeanValue
{
private:
    long num;
    long sum;
public:
    MeanValue(int n, int s) : num(n),sum(s){}
    void operator()(int elem){
        num++;
        sum+=elem;
    }

    operator double(){
        return static_cast<double>(sum) /static_cast<double>(num);
    }
};

int randomNumber()
{
    return std::rand() % 100;
}

struct c_unique{
    int current;
    c_unique(){current = 10;}
    int operator()(){return ++current;}
}UniqueNumber;

bool isOdd(int elem)
{
    return elem % 2 == 1;
}

bool myfunction(int i, int j )
{
    return i > j;
}


void test_algo();

#endif //UNTITLED_ALGO_H
