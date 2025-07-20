#ifndef EnemyBullet_h
#define EnemyBullet_h

#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include <memory>

class EnemyBullet : public Bullet {
public:
    EnemyBullet(const shared_ptr<sf::Texture>& tex);
    void update(float deltaTime) override;
    void onHit() override;
};

#endif