//Chinh dan lazer?

#include "Bullet.h"

Bullet::Bullet(const std::shared_ptr<sf::Texture>& tex, BulletType bulletType, sf::Vector2f dir, float spd, int dmg): texture(tex), sprite(*texture), type(bulletType), direction(dir), speed(spd), damage(dmg), lazerWarningTime(5.0f), lazerTimer(0.0f) {
    sprite.setOrigin(sf::Vector2f(texture->getSize().x / 2.f, texture->getSize().y / 2.f)); //Dat goc toa do tai tam anh
}

void Bullet::update(float deltaTime) {
    if (type == BulletType::Laser) {
        lazerTimer += deltaTime;
        if (lazerTimer >= lazerWarningTime) { //Het thoi gian canh bao
            position += direction * speed * deltaTime;
        }
    } else {
        position += direction * speed * deltaTime;
    }
    sprite.setPosition(position);
}

void Bullet::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

bool Bullet::isOutOfBounds() const {
    return position.y > screenHeight + getBounds().size.y / 2.0f || position.x > screenWidth + getBounds().size.x / 2.0f|| position.x < -sprite.getGlobalBounds().size.x / 2.0f;
}

void Bullet::setPosition(float x, float y) {
    position = sf::Vector2f(x, y);
    sprite.setPosition(position);
}

void Bullet::setSpeed(float newSpeed) {
    speed = newSpeed;
}