#ifndef Bullet_h
#define Bullet_h

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <memory>

using namespace std; 

class Bullet : public GameObject {
protected:
    int damage; 
    float speed;             
    sf::Vector2f direction; // (0,-1) player ban len, (0,1) enemy ban xuong
    bool fromPlayer;

public:
    Bullet(const std::shared_ptr<sf::Texture>& tex);
    virtual ~Bullet() = default;
    virtual void update(float deltaTime) override = 0;
    virtual void draw(sf::RenderWindow& window) override;
    int getDamage() const { return damage; }
    bool isFromPlayer() const { return fromPlayer; }
    virtual void onHit() = 0;
};

#endif