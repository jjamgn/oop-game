#ifndef Player_h
#define Player_h

#include <iostream>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
#include <vector>
#include "GameObject.h"
#include "Enemy.h"
#include <Bullet.h>

using namespace std;

class Player: public GameObject {
private: 
    const int maxHp;
    float shootCooldown; //Thoi gian cho giua 2 lan ban
    float shootTimer; //Dem thoi gian de co the ban tiep
    float skillCooldown; //Thoi gian cho giua 2 lan ki nang
    float skillTimer; //Dem thoi gian de co the dung ki nang tiep
    bool isInvincible; //Trang thai bat tu (sau khi bi ban)
    float invincibleDuration; //Thoi gian bat tu (theo file ban dau la 3s)
    float invincibleTimer; //Dem thoi gian trong trang thai bat tu

public:
    Player(const shared_ptr<sf::Texture>& tex); 
    ~Player() override = default;
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    void takeDamage(int damage) override;
    bool isAlive() const override;
    float getSkillCooldownTimer() const { return this->skillTimer; }; //Doi ten, ten cu trong UML la getCooldownTimer
    void move(float deltaTime, int direction); //direction = -1: trai, = 1: phai
    void shoot(); //Tao dan thuong
    bool isSkillReady();
    void useSkill(vector<Enemy*>& enemies);
    
};

#endif