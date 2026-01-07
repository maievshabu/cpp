//
// Created by redredmaple on 2025/3/29.
//

#include "scene.h"

void scene::enter() const{
}

void scene::out() const {}

scene::~scene() noexcept {

}

skyScene::skyScene() {
    std::cout << "sky-scene" << std::endl;
}

void skyScene::enter() const {
    std::cout << "enter-sky-scene" << std::endl;
}

void skyScene::out() const {
    std::cout << "out-sky-scene" << std::endl;
}

skyScene::~skyScene() noexcept {
    std:cout << "~skyscene" << std::endl;
}

waterScene::waterScene() {
    std::cout << "water-scene" << std::endl;
}

void waterScene::enter() const{
    std::cout << "enter-water-scene" << std::endl;
}

void waterScene::out() const{
    std::cout << "out-water-scene" << std::endl;
}

waterScene::~waterScene() noexcept {
    std::cout << "~waterscene()" << std::endl;
}