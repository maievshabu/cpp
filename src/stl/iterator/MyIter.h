//
// Created by xiaowei003 on 2024/10/30.
//

#ifndef UNTITLED_MYITER_H
#define UNTITLED_MYITER_H
#include <iostream>
#include <vector>
#include <iterator>
#include <string>

// 通用迭代器模板
template <typename T>
class MyIter_x {
public:
    using iterator_category = typename std::iterator_traits<T>::iterator_category;
    using value_type = typename std::iterator_traits<T>::value_type;
    using reference = typename std::iterator_traits<T>::reference;
    using pointer = typename std::iterator_traits<T>::pointer;
    using difference_type = typename std::iterator_traits<T>::difference_type;

    MyIter_x(T it): m_it(it) {}

    reference operator*() const { return *m_it; }
    pointer operator->() { return m_it; } // 前置递增运算符
    MyIter_x& operator++() {
        ++m_it;
        return *this;
    }

    MyIter_x operator++(int) {
        MyIter_x tmp = *this;
        ++m_it;
        return tmp;
    }

    bool operator==(const MyIter_x& other) const {
        return m_it == other.m_it;
    }
    bool operator!=(const MyIter_x& other) const {
        return m_it != other.m_it;
    }
protected: T m_it;
};

template <typename T>
class MyIter_x<T*> {
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using difference_type = std::ptrdiff_t ;

    explicit MyIter_x(pointer ptr) : m_ptr(ptr) {}
    reference operator*() const { return *m_ptr; }
    pointer operator->() { return m_ptr; }
    MyIter_x &operator++() {
        ++m_ptr;
        return *this;
    }
    MyIter_x operator++(int) {
        MyIter_x tmp = *this;
        ++m_ptr;
        return tmp;
    }
    bool operator==(const MyIter_x &other) const { return m_ptr == other.m_ptr; }
    bool operator!=(const MyIter_x &other) const { return m_ptr != other.m_ptr; }
protected:
    pointer m_ptr;
};

template <>
class MyIter_x<int> : public std::iterator<std::forward_iterator_tag, int> {
public:
//    using iterator_category = std::forward_iterator_tag;
//    using value_type = int;
//    using reference = int &;
//    using pointer = int *;
//    using difference_type = std::ptrdiff_t;
    MyIter_x(pointer ptr) : m_ptr(ptr) {}
    reference operator*() const { return *m_ptr; }
    pointer operator->() { return m_ptr; }
    MyIter_x &operator++() {
        ++m_ptr;
        return *this;
    }
    MyIter_x operator++(int) {
        MyIter_x tmp = *this;
        ++m_ptr;
        return tmp;
    }
    bool operator==(const MyIter_x &other) const { return m_ptr == other.m_ptr; }
    bool operator!=(const MyIter_x &other) const { return m_ptr != other.m_ptr; }
protected:
    pointer m_ptr;
};

template <>
class MyIter_x<std::string> : public std::iterator<std::random_access_iterator_tag, std::string>{
public:
//    using iterator_category = std::random_access_iterator_tag;
//    using value_type = string;
//    using reference = string &;
//    using pointer = string *;
//    using difference_type = std::ptrdiff_t;
    MyIter_x(pointer ptr) : m_ptr(ptr) {}
    reference operator*() const { return *m_ptr; }
    pointer operator->() { return m_ptr; }
    MyIter_x &operator++() {
        ++m_ptr;
        return *this;
    }
    MyIter_x operator++(int) {
        MyIter_x tmp = *this;
        ++m_ptr;
        return tmp;
    }
    bool operator==(const MyIter_x &other) const { return m_ptr == other.m_ptr; }
    bool operator!=(const MyIter_x &other) const { return m_ptr != other.m_ptr; }
protected:
    pointer m_ptr;
};

template<typename Iterator>
inline void foo(Iterator begin, Iterator end)
{
    foo(begin, end, typename std::iterator_traits<Iterator>::iterator_category());
}

template<typename BiIterator>
inline void foo(BiIterator begin, BiIterator end, std::bidirectional_iterator_tag)
{
    std::cout << "std::bidirectional_iterator_tag" << std::endl;
}

template<typename forwardIterator>
inline void foo(forwardIterator begin, forwardIterator end, std::forward_iterator_tag)
{
    std::cout << "std::forward_iterator_tag" << std::endl;
}

template<typename randomIterator>
inline void foo(randomIterator begin, randomIterator end, std::random_access_iterator_tag)
{
    std::cout << "std::random_access_iterator_tag" << std::endl;
}

template<typename InputIterator>
void print_it(InputIterator begin, InputIterator end, const std::string flag = "::")
{
    typedef typename std::iterator_traits<InputIterator>::value_type value_type;

    std::cout << flag << " ";
    for (; begin != end; ++begin) {
        std::cout << *begin<< " "; // 使用重载的插入运算符
    }

    std::cout << std::endl;
}


template <typename Iterator>
typename std::iterator_traits<Iterator>::difference_type
distance(Iterator pos1, Iterator pos2)
{
    return std::distance(pos1, pos2, std::iterator_traits<Iterator>::iterator_category);
}

template <typename Iterator>
typename std::iterator_traits<Iterator>::difference_type
distance(Iterator pos1, Iterator pos2, std::input_iterator_tag)
{
    typename std::iterator_traits<Iterator>::difference_type d = 0;
    for(;pos1 != pos2; ++pos1,d++)
        return d;
}

template <typename Iterator>
typename std::iterator_traits<Iterator>::difference_type
distance(Iterator pos1, Iterator pos2, std::random_access_iterator_tag)
{
    return pos2 - pos1;
}

template <typename T, typename U>
class TT{
public:
    void p(){
        std::cout << "T U " << std::endl;
    }
};

template <typename T>
class TT<T,int>{
public:
    void p(){
        std::cout << "T int" << std::endl;
    }
};

template <typename T>
class TT<int,T>{
public:
    void p(){
        std::cout << "int T" << std::endl;
    }
};

template <>
class TT<double,int>{
public:
    void p(){
        std::cout << "double int" << std::endl;
    }
};
template <>
class TT<int,int>{
public:
    void p(){
        std::cout << "int int" << std::endl;
    }
};

template<typename Container>
class asso_insert_iterator : public std::iterator<std::output_iterator_tag, typename Container::value_type>{
protected:
    Container& container;
public:
    explicit asso_insert_iterator(Container& c): container(c){}

    asso_insert_iterator<Container>& operator=(const typename Container::value_type & value){
        container.insert (value);
        return *this;
    }

    asso_insert_iterator<Container> &operator*(){
        return *this;
    }

    asso_insert_iterator<Container> &operator++(){
        return *this;
    }

    asso_insert_iterator<Container> &operator++(int){
        return *this;
    }
};

template<typename Container>
inline asso_insert_iterator<Container> asso_inserter(Container& c)
{
    return asso_insert_iterator<Container>(c);
}

#endif //UNTITLED_MYITER_H
