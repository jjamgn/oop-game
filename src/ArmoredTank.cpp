#include "ArmoredTank.h"
#include "GameConfig.h"

void ArmoredTank::update(float deltaTime) {
    Enemy::update(deltaTime);
    if (canShoot()) { //Ban
        shoot();
        shootTimer = 0.0f; //Reset
    }
}

void ArmoredTank::move(float deltaTime) {
    position.y += getSpeed() * deltaTime;
    sprite.setPosition(position);
    if (position.y > screenHeight) {
        isActive = false;
    }
}

void ArmoredTank::shoot() {
    if (shootTimer >= shootCooldown) {
        shootTimer = 0.0;
        // auto bullet = make_unique<Bullet>(/* thông số đạn */);
        // bullet->setPosition(position.x + sprite.getGlobalBounds().width/2, position.y);
        // bullets.push_back(std::move(bullet));
    }
}

void ArmoredTank::takeDamage(int damage) {
    Enemy::takeDamage(damage);
    if (!isAlive()) {
        //Hieu ung no
    }
}
