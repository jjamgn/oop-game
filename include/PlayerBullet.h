#ifndef PlayerBullet_h
#define PlayerBullet_h

#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include <memory>

class PlayerBullet: public Bullet {
public:
    PlayerBullet(const shared_ptr<sf::Texture>& tex);    
    void update(float deltaTime) override;
    void onHit() override;
};

#endif