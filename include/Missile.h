#ifndef Missile_h
#define Missile_h

#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Missile: public Bullet {
public:
    private:
    float turningSpeed; 
    sf::Vector2f target; //Muc tieu

public:
    Missile(const std::shared_ptr<sf::Texture>& tex, sf::Vector2f target);
    void update(float deltaTime) override;
    void onHit() override;
};

#endif