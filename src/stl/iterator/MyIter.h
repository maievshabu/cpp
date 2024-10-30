//
// Created by xiaowei003 on 2024/10/30.
//

#ifndef UNTITLED_MYITER_H
#define UNTITLED_MYITER_H

//template <typename T>
//class MyIter_x{
//public:
//    using iterator_category = typename std::iterator_traits<T>::iterator_category;
//    using value_type = typename std::iterator_traits<T>::value_type;
//    using reference = typename std::iterator_traits<T>::reference;
//    using pointer = typename std::iterator_traits<T>::pointer;
//    using difference_type = typename std::iterator_traits<T>::difference_type;
//
//    MyIter_x(T it): m_it(it) {}
//
//    reference operator*() const { return *m_it; }
//    pointer operator->() { return m_it; } // 前置递增运算符
//    MyIter_x& operator++() {
//        ++m_it;
//        return *this;
//    }
//
//    MyIter_x operator++(int) {
//        MyIter_x tmp = *this;
//        ++m_it;
//        return tmp;
//    }
//
//    bool operator==(const MyIter_x& other) const {
//        return m_it == other.m_it;
//    }
//    bool operator!=(const MyIter_x& other) const {
//        return m_it != other.m_it;
//    }
//protected: T m_it;
//};
//
//template<typename T>
//class MyIter_x<T*>{
//public:
//    using iterator_category = std::random_access_iterator_tag;
//    using value_type = T;
//    using reference = T&;
//    using pointer = T*;
//    using difference_type = std::ptrdiff_t ;
//
//    MyIter_x(pointer ptr): m_ptr(ptr) {}
//
//    reference operator*() const { return *m_ptr; }
//    pointer operator->() { return m_ptr; } // 前置递增运算符
//    MyIter_x& operator++() {
//        ++m_ptr;
//        return *this;
//    }
//
//    MyIter_x operator++(int) {
//        MyIter_x tmp = *this;
//        ++m_ptr;
//        return tmp;
//    }
//
//    bool operator==(const MyIter_x& other) const {
//        return m_ptr == other.m_ptr;
//    }
//    bool operator!=(const MyIter_x& other) const {
//        return m_ptr != other.m_ptr;
//    }
//protected: pointer m_ptr;
//};

// 指针类型的模板特化


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

template <typename T>
class MyIter_xx {
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using reference = T &;
    using pointer = T *;
    using difference_type = std::ptrdiff_t;
    explicit MyIter_xx(pointer ptr) : m_ptr(ptr) {}
    reference operator*() const { return *m_ptr; }
    pointer operator->() { return m_ptr; }
    MyIter_xx &operator++() {
        ++m_ptr;
        return *this;
    }
    MyIter_xx operator++(int) {
        MyIter_xx tmp = *this;
        ++m_ptr;
        return tmp;
    }
    bool operator==(const MyIter_xx &other) const { return m_ptr == other.m_ptr; }
    bool operator!=(const MyIter_xx &other) const { return m_ptr != other.m_ptr; }
protected:
    pointer m_ptr;
};


template<typename InputIterator>
void print_it(InputIterator begin, InputIterator end, std::string flag = "::")
{
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

#endif //UNTITLED_MYITER_H
