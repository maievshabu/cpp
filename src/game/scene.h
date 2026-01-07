//
// Created by redredmaple on 2025/3/29.
//

#ifndef MAIEV_SCENE_H
#define MAIEV_SCENE_H
#include <iostream>
using namespace std;

class baseScene{
public:
    virtual void enter() const = 0;
    virtual void out() const = 0;
};

class scene : public baseScene{
public:
    virtual void enter() const;
    virtual void out() const;
    virtual ~scene();
};

class skyScene: public scene
{
public:
    void enter() const override;
    void out() const override;
    skyScene();
    ~skyScene();
};

class waterScene: public scene
{
public:
    void enter() const override;
    void out() const override;
    waterScene();
    ~waterScene();
};

#endif //MAIEV_SCENE_H
