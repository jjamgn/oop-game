#ifndef MineTrap_h
#define MineTrap_h

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <memory>

class MineTrap: public Enemy {
public:
    MineTrap(const shared_ptr<sf::Texture>& tex);
    void update(float deltaTime) override;
    void move(float deltaTime) override;  
    void shoot() override {};            
};

#endif