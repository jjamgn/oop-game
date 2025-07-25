//Ham shoot?

#include "Plane.h"
#include "GameConfig.h"

Plane::Plane(const std::shared_ptr<sf::Texture>& tex): Enemy(tex) {
    sprite.setScale(PlaneScale); //Dat scale
    speed = PlaneSpeed;
    hp = PlaneHP;
    shootCooldown = PlaneShootCooldown;
    shootTimer = 0.0f;
}

void Plane::move(float deltaTime) {
    position.x += direction * speed * deltaTime; //Di chuyen qua phai
    if (position.x <= getBounds().size.x / 2.0f || position.x >= screenWidth - getBounds().size.x) {
        direction *= -1.0f;
    }
    sprite.setPosition(position);
}


void Plane::shoot() {
    if (shootTimer >= shootCooldown) {
        shootTimer = 0.0;
        // auto bullet = make_unique<Bullet>(/* thông số đạn */);
        // bullet->setPosition(position.x + sprite.getGlobalBounds().width/2, position.y);
        // bullets.push_back(std::move(bullet));
    }
}


