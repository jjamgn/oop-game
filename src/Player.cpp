//Constructor can dieu chinh speed, shootCooldown, (invincibleDuration).
//Truong hop di chuyen ra ngoai man hinh trong ham move(). 
//Ban thuong gay ra bao nhieu damage.
//Chua xu ly shoot(), ban dan, hinh anh,...

#include "Player.h"

Player::Player(sf::Texture& texture): hp(3), maxHp(3), speed(100.0), position(sf::Vector2f(0.0f, 0.0f)), shootCooldown(0.2), shootTimer(0.2), skillCooldown(60.0), skillTimer(30.0), isInvincible(false), invincibleDuration(3.0), invincibleTimer(0.0), image(texture) {}

Player::~Player() {}

int Player::getHp() const {
    return this->hp;
}

sf::Vector2f Player::getPosition() const {
    return this->position;
}

float Player::getSkillCooldownTimer() const {
    return this->skillTimer;
}

void Player::update(float deltaTime) {
    shootTimer = min(shootTimer + deltaTime, shootCooldown);
    skillTimer = min(skillTimer + deltaTime, skillCooldown);
    if (isInvincible) {
        invincibleTimer += deltaTime;
        if (invincibleTimer >= invincibleDuration) {
            isInvincible = false;
            invincibleTimer = 0.0;
        }
    }
}

void Player::move(float deltaTime, int direction) {
    position.x += direction * speed * deltaTime; 
    // if (position.x < 0) position.x = 0;
    // if (position.x >...
}

void Player::shoot() {
    if (shootTimer >= shootCooldown) {
        shootTimer = 0.0;
        //...
    }
}

void Player::takeDamage() {
    if(!isInvincible) {
        hp--;
        isInvincible = true;
        invincibleTimer = 0.0;
    }

}

bool Player::isSkillReady() {
    return skillTimer >= skillCooldown;
}

void Player::useSkill(vector<Enemy*>& enemies) {
    if (isSkillReady()) {
        skillTimer = 0.0;
        for (auto &e: enemies) {
            if(e->isBoss()) {
                e->takeDamage(30);
            }
            else {
                e->takeDamage(1); //Ban thuong bao nhieu hp nhi?
            }
        }
    }
}

void Player::draw(sf::RenderWindow &window) {
    image.setPosition(position);
    window.draw(image);
}

bool Player::isAlive() {
    return hp > 0;
}