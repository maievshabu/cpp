//
// Created by redredmaple on 2025/8/25.
//

#ifndef MAIEV_POOL_H
#define MAIEV_POOL_H

#include <time.h>
#include <iostream>
#include <vector>
using std::vector;

template<typename T>
class PoolItem{
public:
    T connect;
    bool inUse = false;
    time_t lastUsed;
    PoolItem(T conn) : connect(conn),inUse(false),lastUsed(time(nullptr)) {}
};

template<typename T>
class ConnectionPool{
public:
    ConnectionPool(size_t maxSize): maxSize(maxSize){}

    T* acquire(){
        for(auto& item: pool){
            if (!item.inUse){
                item.inUse = true;
                item.lastUsed = time(nullptr);

                return &item.connect;
            }
        }

        if (pool.size() < maxSize){
            T newConn = createConnect();
            pool.emplace_back(newConn);
            pool.back().inUse = true;

            return &pool.back().connect;
        }

        throw std::runtime_error("No available connections!!!");
    }

    void release(T* conn){
        for(auto& item : pool){
            if (&item.connect == conn){
                item.inUse = false;
                item.lastUsed = time(nullptr);
                return ;
            }
        }

        throw std::runtime_error("connection not found in pool!!");
    }

private :
    std::vector<PoolItem<T>> pool;
    size_t maxSize;

    T createConnect(){
        //建立连接
        std::cout << "connect" << std::endl;
        return T();
    }
};


#endif //MAIEV_POOL_H
