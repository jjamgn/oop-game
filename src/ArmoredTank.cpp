//Ham shoot?

#include "ArmoredTank.h"
#include "GameConfig.h"

ArmoredTank::ArmoredTank(const std::shared_ptr<sf::Texture>& tex): Enemy(tex) {
    sprite.setScale(ArmoredTankScale); //Dat scale
    speed = ArmoredTankSpeed;
    hp = ArmoredTankHP;
    shootCooldown = ArmoredTankShootCooldown;
    shootTimer = 0.0f;
}

void ArmoredTank::move(float deltaTime) {
    position.x += speed * direction * deltaTime;
    position.y += speed * deltaTime * 0.3f;
    sprite.setPosition(position);
    if (position.y > screenHeight + getBounds().size.y / 2.0f) { //Ra khoi man hinh
        hp = 0;
    }
    if (position.x <= getBounds().size.x / 2.0f || position.x >= screenWidth - getBounds().size.x) {
        direction *= -1.0f;
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

