//
// Created by redredmaple on 2026/1/17.
//

#ifndef EFFECTIVE_D119_H
#define EFFECTIVE_D119_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>

namespace d119{
    void test();
    void output(int);
    void output(int, int);
    void output_add_2(int);
    void call_when_even(int, const std::function<void(int)>&);
    std::vector<int>&get_range(void);

    template<typename T>
    class iterator{
    public:
        using value_type = T;
        using size_type = size_t;
    private:
        size_type cursor_;
        const value_type step_;
        value_type value_;
    public:
        iterator(size_type cur_start, value_type begin_val, value_type step_val):
            cursor_(cur_start),step_(step_val),value_(begin_val){
            value_ += step_ * cursor_;
        }
        value_type operator*()const{
            return value_;
        }
        bool operator!=(const iterator& rhs) const{
            return cursor_ != rhs.cursor_;
        }
        iterator& operator++(void){
            value_ += step_;
            ++cursor_;
            return (*this);
        }
    };

    template<typename T>
    class impl{
    public:
        using value_type = T;
        using reference = const value_type&;
        using const_reference = const value_type&;
        using itertor = const iterator<value_type>;
        using const_iterator = const iterator<value_type>;
        using size_type = typename iterator<value_type>::size_type;

        impl(value_type begin_val, value_type end_val, value_type step_val)
            :begin_(begin_val),
            end_(end_val),
            step_(step_val),
            max_count_(get_adjusted_count())
        {}

        size_type size(void) const{
            return max_count_;
        }
        const_iterator begin(void) const{
            return {0, begin_, step_};
        }
        const_iterator end(void) const{
            return {max_count_, begin_, step_};
        }
    private:
        const value_type begin_;
        const value_type end_;
        const value_type step_;
        const size_type max_count_;
        size_type get_adjusted_count(void)const{
            if (step_> 0 && begin_ >= end_){
                throw std::logic_error("End value must be greater than begin value");
            } else if (step_ <0 && begin_ <= end_){
                throw std::logic_error("End value must be less than begin value");
            }

            size_type x = static_cast<size_type>((end_ - begin_) / step_);

            if (begin_ + (step_*x) != end_) ++x;
            return x;
        }
    };

    template<typename T>
    impl<T> range(T end){
        return { {}, end, 1};
    }

    template<typename T>
    impl<T> range(T begin ,T end){
        return { begin, end, 1};
    }

    template<typename T, typename U>
    auto range(T begin, T end, U step) -> impl<decltype(begin + step)>
    {
        using r_t = impl<decltype(begin+step)>;
        return r_t(begin, end, step);
    }

    class A{
            std::function<void()> callback_;
    public:
            A(const std::function<void()>& f):callback_(f){}
            void notify(void){
                callback_();
            }
    };

    class Foo{
    public:
        void operator()(void){
            std::cout << __FUNCTION__  << std::endl;
        }
    };

    class AA{
    public:
        int i_ = 0;
        void output(int x, int y){
            std::cout << x << " " << y << std::endl;
        }
    };

    class CountEven{
    private:
        int& count_;
    public:
        CountEven(int& count):count_(count){}
        void operator()(int val){
            if (!(val&1)){
                ++ count_;
            }
        }
    };
}


#endif //EFFECTIVE_D119_H
