//Can chinh lai constructor

#include "AirCraft.h"

AirCraft::AirCraft(const std::shared_ptr<sf::Texture>& tex): Enemy(tex) { //Khai bao tam thoi
    hp = 150;
    scoreValue = 1000;
    fireCooldown = 0.0f; 
    fireTimer = 0.f;
    spawnCooldown = 0.0f;  
    spawnTimer = 0.f;
    isLazerWarning = false;
    lazerWarningTimer = 0.f;
    position.y = 100.f; 
    sprite.setPosition(position);
    lazerWarningLine.setSize(sf::Vector2f(1.f, 1.f)); 
    lazerWarningLine.setFillColor(sf::Color(255,0,0,120));
    lazerWarningLine.setPosition(position.x, position.y + sprite.getGlobalBounds().height);
}

void AirCraft::update(float deltaTime) {
    sprite.setPosition(position);
    if (hp <= 45) { //Duoi 30% mau, ban dau la 150
        fireCooldown = 1.2f; //Toc do nhanh hon
        spawnCooldown = 2.5f;
    }
    if (isLazerWarning) { //Khi co lazer canh bao
        lazerWarningTimer -= deltaTime;
        if (lazerWarningTimer <= 0.0f) {
            isLazerWarning = false;
            shoot();   
        }
    } else {
        fireTimer += deltaTime;
        if (fireTimer >= fireCooldown) {
            int t = rand() % 6; //Chon random enemy
            if (t == 0) {
                pendingFire = BossFireType::LAZER;
                // Bắt đầu cảnh báo
                lazerWarningTimer = 5.0f; // Cảnh báo 5s
                isLazerWarning = true;
                float relX = position.x + rand() % static_cast<int>(sprite.getGlobalBounds().width); //Random vi tri tha enemy
                lazerWarningLine.setPosition(relX, position.y + sprite.getGlobalBounds().height); //Canh bao
            } else if (t <= 2) {
                pendingFire = BossFireType::TRIPLE;
                shoot();
            } else {
                pendingFire = BossFireType::SINGLE;
                shoot();
            }
            fireTimer = 0.f;
        }
        if (hp <= 45) { //Tha quan phu
            spawnTimer += deltaTime;
            if (spawnTimer >= spawnCooldown) {
                spawnTimer = 0.f;
                //Goi shouldSpawnMinion và getRandomMinionType...  
            }
        }
    }
}

void AirCraft::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    if (isLazerWarning) //Ve lazer
        window.draw(lazerWarningLine);
}

void AirCraft::shoot() {
    if (pendingFire == BossFireType::SINGLE) {
        //Goi GameManager.createBossBullet(position, ...); ...
    }
    if (pendingFire == BossFireType::TRIPLE) {
        //Goi tao dan...
    }
    if (pendingFire == BossFireType::LAZER) {
        //Tao lazer...
    }
}

void AirCraft::takeDamage(int damage) {
    Enemy::takeDamage(damage);
}

bool AirCraft::shouldSpawnMinion() const {
    return (hp <= 45);
}

string AirCraft::getRandomMinionType() const { //Tao ngau nhien quan phu
    int t = rand() % 3;
    if (t == 0) return "TankEnemy";
    if (t == 1) return "ArmoredTank";
    return "AirPlane";
}