#include "MineTrap.h"
#include "GameConfig.h"

void MineTrap::move(float deltaTime) {
    position.y -= speed * deltaTime;
    sprite.setPosition(position);
    if (position.y > screenHeight) { //Ra khoi man hinh
        isActive = false;   
    }
}

void MineTrap::update(float deltaTime) {
    if (!isAlive()) return;
    move(deltaTime);
}