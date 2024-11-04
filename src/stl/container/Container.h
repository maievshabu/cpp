//
// Created by xiaowei003 on 2024/11/1.
//

#ifndef UNTITLED_CONTAINER_H
#define UNTITLED_CONTAINER_H
#include <iostream>
#include <chrono>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "../util/Util.h"

using namespace std;

class Container {

};

template <typename T, T val>
struct Integeral_constant{
    static constexpr T value = val;
    typedef T value_type;
    typedef Integeral_constant<T, val> type;
    constexpr operator value_type(){
        return value;
    }

    typedef Integeral_constant<bool, true> TRUE_TYPE;
    typedef Integeral_constant<bool, false> FALSE_TYPE;
};

class X{
public:
    int _x;
    X(int x):_x(x){}
    bool operator==(const X& other) const{
        return other._x == _x;
    }

    bool operator<(const X& other) const{
        return _x < other._x;
    }
};

template <typename V, typename R>
std::ostream& operator<<(ostream& s, const std::chrono::duration<V,R>& d){
    s << "[" << d.count() << " of " << R::num << "/" << R::den << "]";
    return s;
}

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
void test_array();

/**
  * <vector> random-access-iterator
  * vector<elem> c;
  * vector<elem> c(c2);
  * vector<elem> c = c2;
  * vector<elem> c(rc);
  * vector<elem> c = rc;
  * vector<elem> c(n);
  * vector<elem> c(n, elem);
  * vector<elem> c (c2.begin(), c2.end());
  * vector<elem> c{initilist};
  * vector<elem> c = {initlist;
  *
  * operations:
  * c.empty()
  * c.size()
  * c.capacity()
  * c.max_size()
  * c.reverse(num); //enlarge capacity ,if not enough
  * c.shrink_to_fit
  * c1 < c2;
  * c2 <= c2;
  * c1 == c2;
  * c1 > c2;
  * c1 >= c2;
  * c1 != c2;
  *
  * assign:
  * c = initlist;
  * c = c2;
  * c = rv;
  * c.assign(n, begin);
  * c.assign(beg, end);
  * c.assign(initlist)
  * c1.swap(c2)
  * swap(c1,c2)
  *
  * element access:
  * c.at(idx);
  * c[idx]
  * c.front()
  * c.back()
  *
  * Iterator functions:
  * c.begin()
  * c.end()
  * c.rbegin()
  * c.rend()
  * c.cbegin()
  * c.cend()
  * c.crbegin()
  * c.crend()
  *
  * operations;
  * c.push_back()
  * c.pop_back()
  * c.insert(pos, elem)
  * c.insert(pos, n, elem)
  * c.insert(pos, begin, end)
  * c.insert(pos, initlist)
  * c.emplace(pos, args...)
  * c.emplace_back(pos, args...)
  * c.erase(pos)
  * c.erase(begin,end)
  * c.resize(num)
  * c.resize(num, elem)
  * c.clear()
  *
  *
  * vector<bool>
  * c.flip()
  * c[idx].flip()
  * c[idx] = val
  * c[idx] = c[idx2]
  *
  */

void test_vector();

/**
    * deque --double -end -queue [random-access-itertor]
    * deque<Elem> c
    * deque<Elem> c(c2)
    * deque<Elem> c = c2
    * deque<Elem> c = rc
    * deque<Elem> c(rc)
    * deque<Elem> c = initlist
    * deque<Elem> c(initlist)
    * deque<Elem> c(beg,end)
    * deque<Elem> c(n)
    * deque<Elem> c(n,elem>
    * c.~deque()
    *
    * operation:
    * c.empty()
    * c.size()
    * c.max_size()
    * c.capacity()
    * c.reverse(n)
    * c.shrink_to_fit()
    * c1 > c2
    * c1 >= c2
    * c1 < c2
    * c1 <= c2
    * c1 != c2
    * c1 == c2
    * c.front()
    * c.back()
    * c.at(idx)
    * c[idx]
    * c.begin()
    * c.end()
    * c.rbegin()
    * c.rend()
    * c.crbegin()
    * c.crend()
    *
    * c = c2
    * c = rv
    * c = initlist
    * c.assign(n,elem)
    * c.assign(initlist)
    * c.assign(beg,end)
    * c1.swap(c2)
    * swap(c1,c2)
    * c.erase(beg,end)
    * c.push_back(elem)
    * c.pop_back()
    * c.push_front(elem)
    * c.pop_front()
    * c.insert(pos, elem )
    * c.insert(pos, n, elem)
    * c.insert(pos, beg, end)
    * c.insert(pos, initlist)
    * c.emplace(pos, args...)
    * c.emplace_back(args..)
    * c.emplace_front(args...)
    * c.erase(pos)
    * c.erase(beg,end)
    * c.resize(n)
    * c.resize(n,elem)
    * c.clear()
    *
    */
void test_deque();

/**
     * list -bidirection-iterator
     * list<Elem> c;
     * list<Elem> c = c2;
     * list<Elem> c(c2);
     * list<Elem> c = rc;
     * list<Elem> c(rc);
     * list<Elem> c = initlist;
     * list<Elem> c(initlist);
     * list<Elem> c(begin, end)
     *c.~list()
     *
     * nomodifying operations:
     * c.empty()
     * c.max_size()
     * c.size()
     * c1 > c2
     * c1 >= c2
     * c1 == c2;
     * c1 != c2
     * c1 < c2;
     * c1 <= c2
     *
     * assgin operations:
     * c1 = c2;
     * c1 = rc;
     * c1 = initlist
     * c1.assign(beg, end)
     * c1.assign(n, elem)
     * c1.assign(initlist)
     * c1.swap(c2)
     * swap(c1,c2)
     * c.back()
     * c.front()
     *
     * special modifying operations:
     * c.unique()
     * c.unique(op)
     * c.splice(pos, c2)
     * c.splice(pos, c2, c2pos)
     * c.splice(pos,c2,c2beg, c2end)
     * c.sort()
     * c.sort(op)
     * c.merge(c2)
     * c.merge(c2,op)
     * c.reverse()
     *
     * modifying operations:
     * c1.push_back(elem)
     * c1.pop_back()
     * c1.push_front(elem)
     * c1.pop_front()
     * c1.insert(pos, initlist)
     * c1.insert(beg, end)
     * c1.insert(pos, n, elem)
     * c1.insert(pos, beg, end)
     * c.erase(pos)
     * c.erase(beg,end)
     * c.emplace(pos, args...)
     * c.emplace_back(args...)
     * c.emplace_front(args...)
     * c.resize(n)
     * c.resize(n,elem)
     * c.clear()
     *
     * c.remove(val)
     * c.remove_if(op)
     *
     *
     */
void test_list();

/**
    * forward-list -forward-iterator-tag
    * forward_list<Elem> c
    * forward_list<Elem> c(c2)
    * forward_list<Elem> c = c2;
    * forward_list<Elem> c(rc)
    * forward_list<Elem> c = rc;
    * forward_list<Elem> c(initlist)
    * forward_list<Elem> c = initlist
    * c.~forward_list()
    *
    * operations:
    * c.empty()
    * c.max_size()
    * c1 > c2
    * c1 >= c2
    * c1 != c2
    * c1 == c2
    * c1 < c2;
    * c1 <= c2
    *
    * assign:
    * c = c2;
    * c = rc
    * c = {initlist}
    * c.assign(beg, end)
    * c.assign(pos, beg, end);
    * c.assign(initlist)
    * c1.swap(c2)
    * swap(c1, c2)
    *
    * c.front()
    *
    * iterator functions:
    * c.begin()
    * c.end()
    * c.cbegin()
    * c.cend()
    *
    * c.before_begin()
    * c.cbefore_begin()
    *
    *
    * c.push_front()
    * c.pop_front()
    * c.insert_after(pos, elem);
    * c.insert_after(pos, beg, end)
    * c.insert_after(pos, n, elem)
    * c.insert_after(pos, initlist)
    * c.emplace_after(pos, args...)
    * c.emplace_front(args..)
    * c.erase_after(pos)
    * c.erase_after(beg,end)
    *
    * c.remove(val)
    * c.remove_if(op)
    * c.resize(num, elem)
    * c.clear()
    * c.unique( // only remove consecutive duplicates..
    * c.unique(op)
    *
    * c.splice_after(pos, c2)
    * c.splice_after(pos, c2, pos)
    * c.splice_after(pos, c2, c2beg, c2end)
    *
    * c.sort()
    * c.sort(op)
    *
    * c.merge(c2)
    * c.merge(c2, op)
    * c.reverse()
    */
void test_forward_list();

/**
 * set c;
 * set c(op)
 * set c(c2);
 * set c = c2;
 * set c(rc);
 * set c = rc;
 * set c(beg, end)
 * set c(beg, end, op)
 * set c{initlist}
 * set c = {initlist}
 * c.~set()
 *
 * set == set<Elem>, set<Elem, op> multiset<Elem>, multiset<Elem, op>
 *
 * c.key_comp()
 * c.value_comp()
 * c.empty()
 * c.size()
 * c.max_size()
 * c1 == c2;
 * c1 != c2
 * c1 > c2
 * c1 >= c2
 * c1 < c2
 * c1 <= c2
 *
 * opertaions:
 * c.count()
 * c.find(val)
 * c.lower_bound(val)
 * c.upper_bound(val)
 * c.equal_range(val)
 *
 * assign()
 * c = c2;
 * c = rc
 * c = {initlist}
 * c1.swap(c2)
 * swap(c1, c2)
 *
 * iterator function:
 * c.begin()
 * c.end()
 * c.cbegin()
 * c.cend()
 * c.rbegin()
 * c.rend()
 * c.crbegin()
 * c.crend()
 *
 * c.insert(val)
 * c.insert(pos, val)
 * c.insert(beg, end)
 * c.insert(initlist)
 * c.emplace(args...)
 * c.emplace(pos, args...)
 * c.erase(val)
 * c.erase(pos)
 * c.erase(beg,end)
 * c.clear()
 *
 *
 */
void test_set();

class RuntimeCmp{
public:
    enum cmp_mode{NORMAL, REVERSE};
private:
    cmp_mode mode;
public:
    RuntimeCmp(cmp_mode m_mode=NORMAL):mode(m_mode){}

    template<typename T>
    bool operator()(const T& t1, const T& t2){
        return mode == NORMAL ? t1 < t2  : t2 < t1;
    }
    bool operator==(const RuntimeCmp& rc){
        return mode == rc.mode;
    }
};

bool fncomp(int lhs, int rhs){return lhs > rhs;}
struct classcomp{
    bool operator()(const int& lhs, const int& rhs) const{
        return lhs > rhs;
    }
    bool operator==(const classcomp& rc){
        return true;
    }
};

/**
 * map c;
 * map c(op); //op is the sorting criteriton
 * map c(c2)
 * map c = c2;
 * map c(rv)
 * map c = rv;
 * map c(beg, end)
 * map c(beg,end, op)
 * map c(initlist)
 * map c = initlist
 * c.~map()
 *
 * map types: map<Key, Val> map<Key,Val, Op>, multimap<Key, Val>, multimap<Key, Val, Op>
 *
 * c.key_comp()
 * c.value_comp()
 * c.empty()
 * c.size()
 * c.max_size()
 * c1 == c2
 * c1 != c2
 * c1 > c2
 * c1 >= c2
 * c1 < c2
 * c1 <= c2
 *
 * c.count(val)
 * c.find(val)
 * c.lower_bound(val)
 * c.upper_bound(val)
 * c.equal_range(val)
 *
 * assign
 * c = c2;
 * c = rv;
 * c = {initlist}
 * c1.swap(c2)
 * swap(c1, c2)
 *
 * iterator
 * c.begin()
 * c.end()
 * c.cbegin()
 * c.cend()
 * c.rbegin()
 * c.rend()
 * c.crbegin()
 * c.crend()
 *
 * inserting and removing
 * c.insert(val)
 * c.insert(pos, val)
 * c.insert(beg, end)
 * c.insert(initlist)
 * c.emplace(args...)
 * c.emplace_hit(pos, args...)
 * c.erase(val)
 * c.erase(pos)
 * c.erase(beg, end)
 * c.clear()
 *
 * c[key]
 * c.at(key)
 */

class RuntimeStringCmp{
public:
    enum cmp_mode{NORMAL, NOCASE};
private:
    const cmp_mode mode;
    static bool nocase_compare(char c1, char c2){
        return toupper(c1) == toupper(c2);
    }
public:
    RuntimeStringCmp(cmp_mode m_mode =NORMAL):mode(m_mode){}
    bool operator()(const std::string& s1, const std::string& s2){
        if (mode == NORMAL){
            return s1 < s2;
        }else{
            return std::lexicographical_compare(
                    s1.begin(), s1.end(),
                    s2.begin(), s2.end(),
                    nocase_compare
            );
        }
    }
};

void test_map();

#endif //UNTITLED_CONTAINER_H
