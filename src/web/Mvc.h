//
// Created by redredmaple on 2025/8/25.
//

#ifndef MAIEV_MVC_H
#define MAIEV_MVC_H

#include "DB.h"
#include "Http.h"
#include "Result.h"
#include "Sql.h"

template<typename T, typename DB = Mysql<T>>
class Model{
public:
    Model(){
        //连接池
    }
    int insert(T);
    void update(T);
    int deleteByT(T);
    int searchByT(T);
    T getOne(Query<T> query){
        return db.getOne(query);
    }

    List<T> getList(Query<T> query){
        return db.getList(query);
    }

    friend ostream& operator<<(ostream& os, const Model<T> model){
        os << model._entity;
        return os;
    }
private:
    DB db;
    Result<T> result;
};

template<typename T, typename DB>
int Model<T,DB>::insert(T entity){
    cout << entity << endl;
    return 1;
}

class Controller{
};
class View{
};


#endif //MAIEV_MVC_H
