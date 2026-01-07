//
// Created by redredmaple on 2025/11/6.
//

#ifndef MAIEV_VECTOR2_H
#define MAIEV_VECTOR2_H
#include <math.h>

class Vector2{
public:
    Vector2(float mx, float my): x(mx),y(my){}
    float distanceTo(const Vector2& other) const{
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
    void moveTo(const Vector2& target, float speed){
        float dx = target.x - x;
        float dy = target.y - y;
        float dist = std::sqrt(dx*dx + dy*dy);

        if (dist < speed || dist == 0){
            x = target.x;
            y = target.y;
        }else{
            x += speed * dx / dist;
            y += speed * dy / dist;
        }
    }
private:
    float x;
    float y;
};

#endif //MAIEV_VECTOR2_H
