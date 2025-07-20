#include "Missile.h"
#include <cmath>

Missile::Missile(const shared_ptr<sf::Texture>& tex, sf::Vector2f target): Bullet(tex), target(target) { }

void Missile::update(float deltaTime) {
    sf::Vector2f directionToTarget = target - position; //Tinh huong di chuyen
    float angle = atan2(directionToTarget.y, directionToTarget.x);
    float currentAngle = atan2(direction.y, direction.x); //Xoay ve phia muc tieu
    float rotation = angle - currentAngle;
    direction.x = cos(rotation);
    direction.y = sin(rotation);
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    direction /= length;
    position += direction * getSpeed() * deltaTime; //Chuyen dong 
    sprite.setPosition(position);
}

void Missile::onHit() {
    //Hieu ung no
}