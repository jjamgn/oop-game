#ifndef Enemy_h
#define Enemy_h

#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <memory>
#include "GameConfig.h"

class Enemy {
protected:
    std::shared_ptr<sf::Texture> texture; //Dung shared_ptr vi cac bullet/explosion dung chung texture
    sf::Sprite sprite; 
    sf::Vector2f position;
    float speed = 0.0f; //pixel/s
    int hp;                       
    float shootCooldown;
    float shootTimer = 0.0f;

public:
    Enemy(const std::shared_ptr<sf::Texture>& tex);
    virtual ~Enemy() = default; 
    virtual void update(float deltaTime);
    virtual void draw(sf::RenderWindow& window);

    virtual void move(float deltaTime) = 0;
    virtual void shoot() = 0;

    virtual void takeDamage(int damage);
    bool isAlive() const { return hp > 0; }

    sf::FloatRect getBounds() const { return sprite.getGlobalBounds(); }
    sf::Vector2f getPosition() const { return position; }
    int getHp() const { return hp; }

    void setPosition(float x, float y); //Dung float thay int x, int y
    void setSpeed(float newSpeed);

    virtual bool isBoss() { return false; }; 

protected: 
    bool canShoot() const { return shootTimer >= shootCooldown; }
    
};

#endif