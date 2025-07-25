#ifndef AirCraft_h
#define AirCraft_h

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <memory>
#include <string>

enum class BossFireType {SINGLE, TRIPLE, LAZER}; //Ban 1 vien, 3 vien, lazer

class AirCraft: public Enemy {
private:
    float fireCooldown; //Thoi gian giua 2 lan ban
    float fireTimer; //Dem thoi gian den lan ban tiep theo
    float lazerWarningTimer; //Dem thoi gian canh bao
    bool isLazerWarning; //Co dang canh bao khong
    BossFireType pendingFire; //Dich ma boss tha ra tiep theo
    float spawnCooldown; //Thoi gian cho tha them dich
    float spawnTimer; //Dem thoi gian den lan tha tiep theo
    sf::RectangleShape lazerWarningLine; //Canh bao lazer

public:
    AirCraft(const std::shared_ptr<sf::Texture>& tex);
    ~AirCraft() = default;
    void update(float deltaTime) override;
    void move(float deltaTime) override {}; 
    void draw(sf::RenderWindow &window) override;
    void shoot() override;
    bool shouldSpawnMinion() const; //Goi de tha quan phu
    std::string getRandomMinionType() const; //Ham random tao quan phu
    bool isLazerCharging() const { return isLazerWarning; } 
    sf::RectangleShape getLazerWarningLine() const { return lazerWarningLine; }
    bool isBoss() override { return true; }
};

#endif