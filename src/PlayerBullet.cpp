#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(const std::shared_ptr<sf::Texture>& tex): Bullet(tex) {}

void PlayerBullet::update(float deltaTime) {
    position += direction * getSpeed() * deltaTime;
    sprite.setPosition(position);
}

void PlayerBullet::onHit() {
    //Hieu ung khi ban trung
}

