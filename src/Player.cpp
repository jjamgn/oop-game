//Constructor can dieu chinh speed, shootCooldown, (invincibleDuration).
//Truong hop di chuyen ra ngoai man hinh trong ham move(). 
//Ban thuong gay ra bao nhieu damage.
//Chua xu ly shoot(), ban dan, hinh anh,...

#include "Player.h"
#include <GameConfig.h>


Player::Player(const shared_ptr<sf::Texture>& tex): GameObject(tex), maxHp(PlayerHP) {
    hp = PlayerHP;
    speed = PlayerSpeed;
    shootCooldown = shootCooldownT;
    shootTimer = shootTimerT;
    skillCooldown = skillCooldownT;
    skillTimer = skillTimerT;
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) //An phim mui ten di chuyen trai 
        move(deltaTime, -1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) //An phim mui ten di chuyen phai
        move(deltaTime, 1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) //An space de ban
        shoot();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) //An enter de su dung skill
        if (isSkillReady()) skillTimer += deltaTime;
}

void Player::draw(sf::RenderWindow& window) {
    if (isInvincible) { //Neu bat tu -> nhap nhay
        float blinkPhase = fmod(invincibleTimer, 1.f);
        if (blinkPhase > 0.5f) {
            sprite.setColor(sf::Color(255, 255, 255, 128)); //Lam mo
        } else {
            sprite.setColor(sf::Color::White); //Binh thuong
        }
    } else {
        sprite.setColor(sf::Color::White);
    }
    window.draw(sprite);
}

void Player::takeDamage(int damage) {
    if (!isInvincible) {
        GameObject::takeDamage(damage);
        if (!isAlive()) {
            isActive = false;
        } else {
            isInvincible = true;
            invincibleTimer = 0.0;
        }
    }
}

void Player::move(float deltaTime, int direction) {
    float newX = getPosition().x + direction * speed * deltaTime;
    float playerWidth = sprite.getGlobalBounds().getSize().x;
    newX = std::clamp(newX, playerWidth / 2.0f, screenWidth - playerWidth / 2.0f);
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
                e->takeDamage(NormalDamage); 
            }
        }
    }
}