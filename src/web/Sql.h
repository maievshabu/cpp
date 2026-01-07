//
// Created by redredmaple on 2025/8/25.
//

#ifndef MAIEV_SQL_H
#define MAIEV_SQL_H
#include <iostream>
#include "DB.h"

using std::string;

template<typename T>
struct Sql{
    string sql;
    void select(string );
    string table;
};

template<typename T>
void Sql<T>::select(string) {
}



#endif //MAIEV_SQL_H
