#ifndef Player_h
#define Player_h

#include <iostream>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
#include <vector>
#include "Enemy.h"
#include "Bullet.h"
#include "GameConfig.h"


class Player {
private: 
    std::shared_ptr<sf::Texture> texture; //Dung shared_ptr vi cac bullet/explosion dung chung texture
    sf::Sprite sprite; 
    sf::Vector2f position;
    float speed = PlayerSpeed; //pixel/s
    int hp; 
    const int maxHp = 3;
    //Ban thuong
    float shootCooldown = PlayerShootCooldown; //Thoi gian cho giua 2 lan ban
    float shootTimer = 0.0f; //Dem thoi gian de co the ban tiep
    //Skill
    float skillCooldown = PlayerSkillCooldown; //Thoi gian cho giua 2 lan ki nang
    float skillTimer = 0.0f; //Dem thoi gian de co the dung ki nang tiep
    bool isInvincible = false; //Trang thai bat tu (sau khi bi ban)
    float invincibleDuration = PlayerInvincibleTime; //Thoi gian bat tu (theo file ban dau la 3s)
    float invincibleTimer = 0.0f; //Dem thoi gian trong trang thai bat tu

public:
    Player(const std::shared_ptr<sf::Texture>& tex); 
    ~Player() = default;
    void update(float deltaTime); 
    void draw(sf::RenderWindow& window);

    void move(float deltaTime, int direction); //direction = -1: trai, = 1: phai
    void shoot(); //Tao dan thuong
    void useSkill(std::vector<Enemy*>& enemies);

    void takeDamage();
    bool isAlive() const;
    bool isSkillReady() const;
    sf::FloatRect getBounds() const; //Tra ve thong tin vi tri, kich thuoc de xu ly va cham
    
    void setPosition(float x, float y); //Dung float thay int x, int y
    sf::Vector2f getPosition() const;
    int getHp() const;
    float getSkillCooldownTimer() const; //Doi ten, ten cu trong UML la getCooldownTimer  
};

#endif