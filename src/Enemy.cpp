#include "Enemy.h"

Enemy::Enemy(const shared_ptr<sf::Texture>& tex): GameObject(tex) {}

void Enemy::update(float deltaTime) {
    if (!isAlive()) return;
    if (shootTimer < shootCooldown)
        shootTimer += deltaTime;
    move(deltaTime);
}

void Enemy::draw(sf::RenderWindow& window) {
    if (isAlive()) {
        window.draw(sprite);
    }
}

void Enemy::takeDamage(int damage) {
    if (!isAlive()) return;
    hp -= damage;
    if (hp <= 0) {
        hp = 0;
        isActive = false;
    }
}

