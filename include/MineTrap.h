#ifndef MineTrap_h
#define MineTrap_h

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <memory>

class MineTrap: public Enemy {
public:
    MineTrap(const std::shared_ptr<sf::Texture>& tex);
    ~MineTrap() = default;
    void move(float deltaTime) override; //Di chuyen thang
    void shoot() override {};            
};

#endif