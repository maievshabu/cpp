//
// Created by redredmaple on 2025/11/6.
//

#ifndef MAIEV_ENTITY_H
#define MAIEV_ENTITY_H
#include <string>
#include "Vector2.h"

class Entity {
public:
    std::string name;
    Vector2 position;
    virtual void update() = 0;
    virtual ~Entity();
};

class Npc : public Entity{
public:
    Npc(const std::string& n, Vector2 pos){
        name = n;
        position = pos;
    }
    void update(){}
};

class Role : public Entity{
public:

    void update(){
        //更新自己的位置和其他相关
        position.moveTo(target, speed);
    }
private:
    Vector2 target;
    float speed = 0.2f;
};


#endif //MAIEV_ENTITY_H
