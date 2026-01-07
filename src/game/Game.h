//
// Created by redredmaple on 2025/3/29.
//

#ifndef MAIEV_GAME_H
#define MAIEV_GAME_H
#include <string>
#include <iostream>
using namespace std;

class Game {
public:
    Game() ;
    Game(string name);
    ~Game();
    Game(const Game & game); //拷贝构造
    Game(Game && game); //移动构造
    Game& operator=(const Game & game1); //拷贝赋值
    Game& operator=(Game && rbs); //移动赋值
    string getName() const;

    friend ostream& operator<<(ostream & os, const Game & game)
    {
        os << game._name;
        return os;
    }
private:
    string _name;
};

#endif //MAIEV_GAME_H
