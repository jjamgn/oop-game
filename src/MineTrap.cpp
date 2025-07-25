#include "MineTrap.h"
#include "GameConfig.h"

MineTrap::MineTrap(const std::shared_ptr<sf::Texture>& tex): Enemy(tex) {
    sprite.setScale(MineTrapScale); //Dat scale
    speed = MineTrapSpeed;
    hp = MineTrapHP;
}

void MineTrap::move(float deltaTime) {
    position.y += speed * deltaTime;
    sprite.setPosition(position);
    if (position.y > screenHeight + getBounds().size.y / 2.0f) { //Ra khoi man hinh
        hp = 0;
    }
}


