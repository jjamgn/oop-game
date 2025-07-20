#include "Enemy.h"
#include "TankEnemy.h"
#include "GameConfig.h"

TankEnemy::TankEnemy(const shared_ptr<sf::Texture>& tex): Enemy(tex) {}

void TankEnemy::update(float deltaTime) {
    Enemy::update(deltaTime); 
    if (canShoot()) { //Ban 
        shoot();
        shootTimer = 0.0f; //Reset
    }
}

void TankEnemy::move(float deltaTime) {
    position.y -= speed * deltaTime;
    sprite.setPosition(position);
    if (position.y > screenHeight) { //Ra khoi man hinh
        isActive = false;   
    }
}

void TankEnemy::shoot() {
    if (shootTimer >= shootCooldown) {
        shootTimer = 0.0;
        // auto bullet = make_unique<Bullet>(/* thông số đạn */);
        // bullet->setPosition(position.x + sprite.getGlobalBounds().width/2, position.y);
        // bullets.push_back(std::move(bullet));
    }
}

void TankEnemy::takeDamage(int damage) {
    Enemy::takeDamage(damage);
    if (!isAlive()) {
        //Hieu ung no
    }
}