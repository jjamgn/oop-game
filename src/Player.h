#ifndef Player_h
#define Player_h

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <vector>
#include "Enemy.h"

using namespace std;

class Player {
private: 
    int hp;
    int maxHp;
    float speed; //Doi kieu du lieu, trong UML la int
    sf::Vector2f position;
    sf::Sprite image;
    float shootCooldown; //Thoi gian cho giua 2 lan ban
    float shootTimer; //Dem thoi gian de co the ban tiep
    float skillCooldown; //Thoi gian cho giua 2 lan ki nang
    float skillTimer; //Dem thoi gian de co the dung ki nang tiep
    bool isInvincible; //Trang thai bat tu (sau khi bi ban)
    float invincibleDuration; //Thoi gian bat tu (theo file ban dau la 3s)
    float invincibleTimer; //Dem thoi gian trong trang thai bat tu

public:
    Player(sf::Texture& texture); //Do image khong co default constructor, phai duoc gan một sf::Texture, 
    ~Player();
    int getHp() const;
    sf::Vector2f getPosition() const;
    float getSkillCooldownTimer() const; //Doi ten, ten cu trong UML la getCooldownTimer
    void update(float deltaTime);
    void move(float deltaTime, int direction); //direction = -1: trai, = 1: phai
    void shoot();
    void takeDamage();
    bool isSkillReady();
    void useSkill(vector<Enemy*>& enemies);
    void draw(sf::RenderWindow &window);
    bool isAlive();
};

#endif