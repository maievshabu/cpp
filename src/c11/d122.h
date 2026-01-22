//
// Created by redredmaple on 2026/1/22.
//

#ifndef C11_D122_H
#define C11_D122_H

#include "common.h"


namespace d122 {
    void test();

    void do_once();

    int func(int x);

    struct AtomicCounter{
        std::atomic<int> val;
        void crement(){
            ++val;
        }

        void deCrement(){
            --val;
        }
        int get(){
            return val.load();
        }
    };

    struct Counter{
        int value;
        std::mutex mutex;
        void crement(){
            std::lock_guard<std::mutex> locker(mutex);
            ++value;
        }
        void decrement(){
            std::lock_guard<std::mutex> locker(mutex);
            --value;
        }
        int get(){
            return value;
        }
    };

    struct ccomplex{
    private: std::mutex mutex;
    public:
        int i;
        ccomplex() : i(0){}
        void mul(int x){
            std::lock_guard<std::mutex> lock(mutex);
            i *= x;
        }
        void add(int x){
            std::lock_guard<std::mutex> lock(mutex);
            i += x;
        }
        void getI(){
            std::cout << i << std::endl;
        }
    };

    struct Complex{
//        std::mutex mutex; //这里的话会方式死锁,同一个线程锁住了，后面的锁就无法释放了
        std::recursive_mutex mutex;
        int i;
        Complex() : i(0) {}
        void mul(int x){
            std::lock_guard<std::recursive_mutex> lock(mutex);
            i *= x;
        }
        void div(int x){
            std::lock_guard<std::recursive_mutex> lock(mutex);
            i /= x;
        }

        void both(int x, int y){
            std::lock_guard<std::recursive_mutex> lock(mutex);
            mul(x);
            div(y);
        }

        void getI(){
            std::cout << i << std::endl;
        }
    };

    //同步队列的实现
    template<typename T>
    class SyncQueue
    {
    public:
        bool isFull() const{
            return m_queue.size() == m_masSize;
        }
        bool isEmpty() const{
            return m_queue.empty();
        }

        SyncQueue(const SyncQueue&) = delete;
        SyncQueue& operator=(const SyncQueue&) = delete;

        explicit SyncQueue(int maxSize):m_masSize(maxSize){}
        void Put(const T& x){
//            std::lock_guard<std::mutex> locker(m_mutex);
            std::unique_lock<std::mutex> locker(m_mutex);
            while(isFull()){
                cout << "[ ";
                for(const auto & _l : m_queue){
                    cout << _l << " ";
                }
                cout << "]"<< endl;
                cout << "缓冲区满了,需要等待..." << endl;
                m_notFull.wait(m_mutex);
            }

//            m_notFull.wait(locker,[this]{return !isFull();});

            m_queue.push_back(x);
            m_notEmpty.notify_one();// ???
        }

        void Take(T& x){
            std::lock_guard<std::mutex> locker(m_mutex);

            cout << "[ ";
            for(const auto & _l : m_queue){
                cout << _l << " ";
            }
            cout << "]"<< endl;

            while(isEmpty()){
                cout << "缓冲区空了,需要等待..." << endl;
                m_notEmpty.wait(m_mutex);
            }
            x = m_queue.front();
            m_queue.pop_front();
            std::cout << "出队列:"<< x << endl;
            m_notFull.notify_one();
        }
        bool Empty(){
            std::lock_guard<std::mutex> locker(m_mutex);
            return m_queue.empty();
        }
        bool Full(){
            std::lock_guard<std::mutex> locker(m_mutex);
            return m_queue.size() == m_masSize;
        }
        size_t Size(){
            std::lock_guard<std::mutex> locker(m_mutex);
            return m_queue.size();
        }
        int Count(){
            return m_queue.size();
        }
    private:
        std::list<T> m_queue;
        std::mutex m_mutex;
        std::condition_variable_any m_notEmpty;
        std::condition_variable_any m_notFull;
        int m_masSize;
    };

    template<typename T>
    class SimpleSyncQueue{
    public:
        SimpleSyncQueue(){}
        void Put(const T& x){
//            std::unique_lock<std::mutex> locker(m_mutex);
            std::unique_lock<std::recursive_mutex> locker(m_mutex);
            cout << "进队列: " << x << endl;
            m_queue.push_back(x);
            print();
            m_notEmpty.notify_one();
        }
        void Take(T& x){
//            std::unique_lock<std::mutex> locker(m_mutex);
            std::unique_lock<std::recursive_mutex> locker(m_mutex);
            m_notEmpty.wait(locker, [this]{
                return !m_queue.empty();
            });
            x = m_queue.front();
            m_queue.pop_front();
            cout << "出队列: " << x << endl;
            print();
        }
        bool Empty(){
//            std::lock_guard<std::mutex> locker(m_mutex);
            std::lock_guard<std::recursive_mutex> locker(m_mutex);
            return m_queue.empty();
        }

        size_t Size(){
//            std::lock_guard<std::mutex> locker(m_mutex);
            std::lock_guard<std::recursive_mutex> locker(m_mutex);
            return m_queue.size();
        }

        void print(){
            std::unique_lock<std::recursive_mutex> locker(m_mutex);
            cout << "[ ";
            for(const auto & _l : m_queue){
                cout << _l << " ";
            }
            cout << "]" << endl;
        }

    private:
        std::list<T> m_queue;
        std::recursive_mutex m_mutex;

        std::condition_variable_any m_notEmpty;
    };
};

struct A{
    void func(int i){
        cout << i << endl;
    }
};


#endif //C11_D122_H
