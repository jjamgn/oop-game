//Xu li ham shoot() + lazerWarning, dung spawner???

#include "AirCraft.h"

AirCraft::AirCraft(const std::shared_ptr<sf::Texture>& tex): Enemy(tex) { 
    hp = AirCraftHP;
    fireCooldown = 0.0f; 
    fireTimer = 0.0f;
    spawnCooldown = 0.0f;  
    spawnTimer = 0.0f;
    isLazerWarning = false;
    lazerWarningTimer = 0.0f;
    sprite.setPosition(AirCraftStartPosition);
    lazerWarningLine.setSize(SizeLazerWarningLine); 
    lazerWarningLine.setFillColor(ColorLazerWarningLine);
    lazerWarningLine.setPosition(sf::Vector2f(position.x, position.y + sprite.getGlobalBounds().size.y / 2.0f));
}

void AirCraft::update(float deltaTime) {
    sprite.setPosition(position);
    if (hp <= 0.3*AirCraftHP) { //Duoi 30% mau
        fireCooldown *= 1.5f; //Toc do nhanh hon
        spawnCooldown *= 1.5f;
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
                lazerWarningTimer = 5.0f; //Bat dau canh bao 5s
                isLazerWarning = true;
                float relX = position.x + rand() % static_cast<int>(sprite.getGlobalBounds().size.x); //Random vi tri tha enemy
                lazerWarningLine.setPosition(sf::Vector2f(relX, position.y + sprite.getGlobalBounds().size.y)); //Canh bao
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
        //Goi tao dan...
    }
    if (pendingFire == BossFireType::TRIPLE) {
        //Goi tao dan...
    }
    if (pendingFire == BossFireType::LAZER) {
        //Tao lazer...
    }
}

bool AirCraft::shouldSpawnMinion() const {
    return (hp <= 0.3*AirCraftHP);
}

std::string AirCraft::getRandomMinionType() const { //Tao ngau nhien quan phu
    int t = rand() % 3;
    if (t == 0) return "TankEnemy";
    if (t == 1) return "ArmoredTank";
    return "AirPlane";
}