#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(const shared_ptr<sf::Texture>& tex): Bullet(tex) {}

void EnemyBullet::update(float deltaTime) {
    position += direction * getSpeed() * deltaTime;
    sprite.setPosition(position);
}

void EnemyBullet::onHit() {
    //Hieu ung no
}