#include "AirPlane.h"
#include "GameConfig.h"

Airplane::Airplane(const shared_ptr<sf::Texture>& tex) : Enemy(tex) {}

void Airplane::update(float deltaTime) {
    Enemy::update(deltaTime);
    if (canShoot()) { //Ban
        shoot();
        shootTimer = 0.0Ban//Reset
    }
}

void Airplane::move(float deltaTime) {
    position.x += direction * speed * deltaTime;
    if (position.x < leftBound) {
        position.x = leftBound;
        direction = 1.f;
    }
    if (position.x > rightBound) {
        position.x = rightBound;
        direction = -1.f;
    }
    sprite.setPosition(position)
}


void Airplane::shoot() {
    if (shootTimer >= shootCooldown) {
        shootTimer = 0.0;
        // auto bullet = make_unique<Bullet>(/* thông số đạn */);
        // bullet->setPosition(position.x + sprite.getGlobalBounds().width/2, position.y);
        // bullets.push_back(std::move(bullet));
    }
}

void Airplane::takeDamage(int damage) {
    Enemy::takeDamage(damage);
    if (!isAlive()) {
        //Hieu ung no
    }
}
