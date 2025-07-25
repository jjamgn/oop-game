#ifndef Plane_h
#define Plane_h

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <memory>

class Plane: public Enemy {
private:
    float direction = 1.0f ; //-1 la trai, +1 la phai

public:
    Plane(const std::shared_ptr<sf::Texture>& tex);
    ~Plane() = default;
    void move(float deltaTime) override;
    void shoot() override;
};

#endif