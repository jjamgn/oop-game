#ifndef Enemy_h
#define Enemy_h

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <memory>

using namespace std; 

class Enemy: public GameObject {
protected:
    int scoreValue;
    float shootCooldown;
    float shootTimer;

public:
    Enemy(const shared_ptr<sf::Texture>& tex); //Do image khong co default constructor, phai duoc gan một sf::Texture, 
    virtual ~Enemy() = default; 
    virtual void update(float deltaTime) override;
    virtual void draw(sf::RenderWindow &window) override;
    virtual void move(float deltaTime) = 0;
    virtual void shoot() = 0;
    virtual void takeDamage(int damage) override; //Them tham so khac UML, su dung skill se co damage khac
    bool isAlive() const override;
    virtual bool isBoss() { return false; }; 
    int getScore() const { return scoreValue; }

protected: 
    bool canShoot() const { return shootTimer >= shootCooldown; }
    
};

#endif