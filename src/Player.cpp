//Co hieu ung, am thanh khi su dung skill khong?
//Hàm shoot() tạo đạn
//Hàm useSkill() tạo đạn, hiệu ứng, playSound?... không xử lí trực tiếp Enemy, cần hàm xử lí
//Hàm takeDamage hiệu ứng playSound?

#include "Player.h"
#include <GameConfig.h>

Player::Player(const std::shared_ptr<sf::Texture>& tex): texture(tex), sprite(*tex), hp(maxHp) {
    sprite.setOrigin(sf::Vector2f(texture->getSize().x / 2.f, texture->getSize().y / 2.f)); //Dat goc toa do tai tam anh
    sprite.setScale(PlayerScale); //Dat scale
    position = PlayerStartPosition;
    sprite.setPosition(position);
}

void Player::update(float deltaTime) {
    shootTimer = std::min(shootTimer + deltaTime, shootCooldown);
    skillTimer = std::min(skillTimer + deltaTime, skillCooldown);
    if (isInvincible) {
        invincibleTimer += deltaTime;
        if (invincibleTimer >= invincibleDuration) {
            isInvincible = false;
            invincibleTimer = 0.0f;
            sprite.setColor(sf::Color::White); //Tro lai binh thuong
        } else {
            static float blinkTimer = 0.0f; //Dung static de giu gia tri
            blinkTimer += deltaTime;
            if(blinkTimer > 0.1f) { //Nhap nhay chu ki 0.1s
                blinkTimer = 0.0f;
                sprite.setColor(sprite.getColor().a == 255 ? sf::Color(255, 255, 255, 150) : sf::Color::White); //255 la ro net, 150 la dang mo
            }
        }
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::move(float deltaTime, int direction) {
    float newX = getPosition().x + direction * speed * deltaTime; //Vi tri moi, truc Ox
    float playerWidth = getBounds().size.x; //Lay chieu rong
    newX = std::clamp(newX, playerWidth / 2.0f, screenWidth - playerWidth / 2.0f); //Gioi han toa do x de khong ra khoi man hinh std::clamp(value, min, max)
    setPosition(newX, getPosition().y);
}

void Player::shoot() {
    if (shootTimer >= shootCooldown) {
        shootTimer = 0.0;
        // auto bullet = make_unique<Bullet>(/* thông số đạn */);
        // bullet->setPosition(position.x + sprite.getGlobalBounds().width/2, position.y);
        // bullets.push_back(std::move(bullet));
    }
}

void Player::useSkill(std::vector<Enemy*>& enemies) {
    if (isSkillReady()) {
        skillTimer = 0.0f;
        for (Enemy* e : enemies) {
            if (e->isAlive()) {
                if (e->isBoss()) {
                    e->takeDamage(30);
                } else {
                    e->takeDamage(1000);
                }
            }
        }
    }
}

void Player::takeDamage() {
    if (!isInvincible) {
        --hp;
        sprite.setColor(sf::Color::Red);
        if (isAlive()) {
            isInvincible = true;
            invincibleTimer = 0.0f;
        }
    }
}

bool Player::isAlive() const {
    return hp > 0;
}

bool Player::isSkillReady() const {
    return skillTimer >= skillCooldown;
}

sf::FloatRect Player::getBounds() const { 
    return sprite.getGlobalBounds();
}

void Player::setPosition(float x, float y) {
    position = sf::Vector2f(x, y);
    sprite.setPosition(position);
}

sf::Vector2f Player::getPosition() const {
    return position;
}

int Player::getHp() const {
    return hp; 
}

float Player::getSkillCooldownTimer() const {
    return skillTimer;
}












