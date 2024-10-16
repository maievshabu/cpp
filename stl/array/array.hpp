//
// Created by xiaowei003 on 2024/9/29.
//

#pragma once
#ifndef UNTITLED_ARRAY_HPP
#define UNTITLED_ARRAY_HPP
#include <initializer_list>
#include <iostream>
#include "array_iterator.hpp"

namespace stl {


    template<typename T, size_t N>
    class array {
    public:
        //member function
//        typedef array_iterator<T> iterator;
        using iterator = array_iterator<T>;

        array();
        array(std::initializer_list<T>);
        ~array();
        array& operator=(const array &ar);
        //acces
        T at(int pos);
        T operator[](int pos);
        T front();
        const T front() const;
        T back();
        T *data();

        //capacity
        bool empty();
        size_t size();
        size_t max_size();
        //operations
        void  fill(int val);
        void swap(array &other);

        iterator begin();
        iterator end();
    private:
        T elem[N];
    };


    template <typename T, size_t N>
    array<T, N>::array() {
    }

    template <typename T, size_t N>
    array<T, N>::array(std::initializer_list<T> list){
        size_t i = 0;
        for(auto &val : list){
            elem[i++] = val;
        }
    }

    template <typename T, size_t N>
    array<T,N>::~array() {}

    template <typename T, size_t N>
    array<T,N>& array<T,N>::operator= (array<T,N> const & ar) {
        return *this;
    }

    template <typename T, size_t N>
    T array<T,N>::at(int pos) {
        return elem[pos - 1];
    }

    template <typename T, size_t N>
    T array<T,N>::operator[](int pos){
        return elem[pos - 1];
    }

    template <typename T, size_t N>
    T array<T, N> ::front() {
        return elem[0];
    }

    template <typename T, size_t N>
    T array<T, N> ::back() {
        return elem[ N - 1];
    }

    template <typename T, size_t N>
    T* array<T, N> ::data() {
        return elem;
    }

    template <typename T, size_t N>
    bool array<T, N>::empty() {
        return N == 0;
    }

    template <typename T, size_t N>
    size_t array<T, N>::size() {
        return N;
    }

    template <typename T, size_t N>
    size_t array<T, N>::max_size() {
        return N;
    }

    template <typename T, size_t N>
    void array<T,N>::fill(int val){
        for( int i = 0; i < N; i ++ ){
            elem[i] = val;
        }
    }

    template <typename T, size_t N>
    void array<T, N> ::swap(array& ar){
        for(size_t i = 0; i < N ;i ++){
            std::swap(elem[i], ar.elem[i]); //这里出错过了.
        }
    }

    template <typename T, size_t N>
    typename array<T,N>::iterator array<T, N>::begin()
    {
        return array_iterator<T>(elem);
    }

    template <typename T, size_t N>
    typename array<T,N>::iterator array<T, N>::end()
    {
        return array_iterator<T>(elem + N) ;
    }
}


#endif //UNTITLED_ARRAY_HPP
