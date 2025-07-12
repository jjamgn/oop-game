#include "Enemy.h"

Enemy::Enemy(sf::Texture& texture): image(texture) {}

Enemy::~Enemy() {}

bool Enemy::isAlive() {
    return hp > 0;
}