//
// Created by xiaowei003 on 2024/10/27.
//

#ifndef UNTITLED_MYALLOC_H
#define UNTITLED_MYALLOC_H

#include <cstddef>

template <typename T>
class MyAlloc {
public:
    typedef T value_type;
    MyAlloc() noexcept {}

    template<typename U>
    MyAlloc(const MyAlloc<U> &) noexcept {}

    T* allocate(std::size_t num){
        return static_cast<T*>(::operator new (num* sizeof(T)));
    }

    void deallocate(T * p, size_t num){
        ::operator delete(p);
    }
};

template<typename T1, typename T2>
bool operator==(const MyAlloc<T1> &, const MyAlloc<T2> &) noexcept{
    return true;
}

template<typename T1, typename T2>
bool operator!=(const MyAlloc<T1> &, const MyAlloc<T2> &) noexcept{
    return true;
}

#endif //UNTITLED_MYALLOC_H
