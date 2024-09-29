//
// Created by xiaowei003 on 2024/9/29.
//

#pragma once
#ifndef UNTITLED_array_iterator_HPP
#define UNTITLED_array_iterator_HPP
#include <iostream>

namespace stl{
    template<typename T>
    class array_iterator {
    public:
        typedef array_iterator& reference;
        typedef array_iterator* pointer;

        array_iterator(T*);
        ~array_iterator();
        T operator*();
        array_iterator& operator++ ();
        array_iterator operator++(int); // Postfix increment
        array_iterator& operator= (array_iterator const &);
        bool operator!= (array_iterator const &);
    private:
        T* elem;
    };

    template <typename T>
    array_iterator<T>::array_iterator(T* _elem) {
        elem = _elem;
    }

    template <typename T>
    array_iterator<T>::~array_iterator() {
    }

    template <typename T>
    T array_iterator<T>::operator*()
    {
        return *elem;
    }

    template <typename T>
    array_iterator<T>& array_iterator<T>::operator=(array_iterator const & other)
    {
        if (this != &other){
            elem = other.elem;
        }

        return *this;
    }

    template <typename T>
    bool array_iterator<T>::operator !=(array_iterator const& other)
    {
        return this->elem != other.elem;
    }

    template <typename T>
    array_iterator<T>& array_iterator<T>::operator ++()
    {
        ++elem;
        return *this;
    }

    template <typename T>
    array_iterator<T> array_iterator<T>::operator++(int) {
        array_iterator temp = *this; // Save the current state
        ++elem; // Move to the next element
        return temp; // Return the saved state (postfix semantics)
    }
}
#endif
