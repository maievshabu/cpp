//
// Created by redredmaple on 2025/3/29.
//

#ifndef MAIEV_OBJECT_H
#define MAIEV_OBJECT_H
#include <iostream>
#include <random>

namespace GAME{

}

class baseObject
{
public:
    virtual void battle(baseObject&) = 0;
};

class Object {
public:
    virtual void battle(Object&) = 0;
    int life;
    int skill;
};

//角色
class Role: public Object{
public:
    void battle(Object&);
};

//敌人
class Enermy : public Object
{
    void battle(Object&);
};


#endif //MAIEV_OBJECT_H
