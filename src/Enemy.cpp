#include "Enemy.h"

Enemy::Enemy(const std::shared_ptr<sf::Texture>& tex): texture(tex), sprite(*texture) {
    sprite.setOrigin(sf::Vector2f(texture->getSize().x / 2.f, texture->getSize().y / 2.f)); //Dat goc toa do tai tam anh
}

void Enemy::update(float deltaTime) {
    if (!isAlive()) return;
    move(deltaTime);
    shootTimer = std::min(shootTimer + deltaTime, shootCooldown);
    if (canShoot()) {
        shoot();
        shootTimer = 0.0f;
    }
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Enemy::takeDamage(int damage) {
    hp -= damage;
    sprite.setColor(sf::Color::Red);
    if (hp < 0) hp = 0;
}

void Enemy::setPosition(float x, float y) {
    position = sf::Vector2f(x, y);
    sprite.setPosition(position);
}

void Enemy::setSpeed(float newSpeed) {
    speed = newSpeed;
}





