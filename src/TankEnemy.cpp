//Tuong tu voi ham shoot?
#include "Enemy.h"
#include "TankEnemy.h"
#include "GameConfig.h"

TankEnemy::TankEnemy(const std::shared_ptr<sf::Texture>& tex): Enemy(tex) {
    sprite.setScale(TankEnemyScale); //Dat scale
    speed = TankEnemySpeed;
    hp = TankEnemyHP;
    shootCooldown = TankEnemyShootCooldown;
    shootTimer = 0.0f;
}

void TankEnemy::move(float deltaTime) {
    position.y += speed * deltaTime;
    sprite.setPosition(position);
    if (position.y > screenHeight + getBounds().size.y / 2.0f) { //Ra khoi man hinh
        hp = 0;
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