//
// Created by redredmaple on 2025/8/25.
//

#ifndef MAIEV_DB_H
#define MAIEV_DB_H
#include <iostream>
#include <string>
#include "Result.h"
#include "Sql.h"
#include "Type.h"

using std::string;
using std::cout;


template<typename T>
class Query{
public:
    Query eq(string field, T entity){
        return *this;
    }
    Query select(string field){
        return *this;
    }
private:
    T t;
};

class DB_Base{
public :
    virtual int connect() = 0 ;
    virtual ~DB_Base(){}
protected:
    string host;
    string port;
    string username;
    string password;
};

template<typename T>
class Mysql : public DB_Base{
public:
    Mysql(){
        cout << "Mysql()" << endl;
    }
    int connect(){
        cout << "connect" << endl;
        return 1;
    }

    int insert(T m){
        cout << "insert into" << m << endl;
        return 1;
    }

    T getOne(Query<T> query){
        cout << "getOne called :" << endl;
        return T("default", 200);
    }

    List<T> getList(Query<T> query){
        cout << "getList called: " << endl;

        T t1("maiev", 12);
        T t2("nico", 13);
        T t3("mike", 14);

        List<T> mylist;

        mylist.add(t1);
        mylist.add(t2);
        mylist.add(t3);

        return mylist;
    }
private:
    T result;
};

template<typename T>
class Sqlite: public DB_Base{
};

template<typename mode>
class PgSql: public DB_Base{
};

#endif //MAIEV_DB_H
