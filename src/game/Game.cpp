//
// Created by redredmaple on 2025/3/29.
//

#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() {
    std::cout << "Game()" << std::endl;
}

Game::~Game()
{
    std::cout << "~Game" << std::endl;
}

Game::Game(string name) {
    std::cout << "Game(game)" << std::endl;
    _name= name;
}

Game::Game(const Game& game) {
    std:: cout<<  "copy ctr:" << game <<std::endl;
    _name = game.getName();
}

Game::Game(Game &&game) {
    std:: cout<<  "move ctr(&&):" << game << std::endl;
    _name = std::move(game._name);
}

Game& Game::operator=(const Game &rbs) {
    std:: cout<<  "assign(&) =:" << rbs << std::endl;
    _name = rbs._name;

    return *this;
}

Game& Game::operator=(Game &&rbs) {
    std:: cout<<  "assign(&&) = :" << rbs << std::endl;
    _name = std::move(rbs._name);

    return *this;
}

std::string Game::getName() const
{
    return _name;
}