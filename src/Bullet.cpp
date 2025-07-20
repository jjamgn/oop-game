#include "Bullet.h"

Bullet::Bullet(const std::shared_ptr<sf::Texture>& tex): GameObject(tex) {
    position = pos;
    direction = fromPlayer ? sf::Vector2f(0, -1) : sf::Vector2f(0, 1); // Player bắn lên, Enemy bắn xuống
    sprite.setPosition(position);
}

void Bullet::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}