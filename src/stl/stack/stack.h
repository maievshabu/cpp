//
// Created by xiaowei003 on 2024/10/25.
//

#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H

#include <deque>
#include <exception>
#include <vector>
#include <algorithm>
#include <iostream>

template<typename T>
class Stack{
protected:
    std::deque<T> c;
public:
    class ReadEmptyStack : public std::exception{
    public:
        virtual const char * what() const throw(){
            return "read empty stack";
        }
    };

    typename std::deque<T>::size_type size() const{
        return c.size();
    }

    bool empty() const {
        return c.empty();
    }

    void push(const T& elem){
        c.push_back(elem);
    }

    T pop(){
        if (c.empty()){
            throw new ReadEmptyStack();
        }

        T elem(c.back());
        c.pop_back();

        return elem;
    }

    T& top(){
        if (c.empty()){
            throw ReadEmptyStack();
        }

        return c.back();
    }
};

// 辅助函数，用于交换两个元素
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 生成全排列的递归函数
void permute(std::vector<int>& nums, int l, int r) {
    if (l == r) {
        // 打印当前排列
        for (int num : nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(nums[l], nums[i]); // 交换当前元素与第l个元素
            permute(nums, l + 1, r); // 递归生成剩余元素的排列
            swap(nums[l], nums[i]); // 回溯到原来的状态
        }
    }
}
#endif //UNTITLED_STACK_H
