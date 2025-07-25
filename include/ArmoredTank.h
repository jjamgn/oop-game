#ifndef ArmoredTank_h
#define ArmoredTank_h

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <memory>

class ArmoredTank: public Enemy { //Doi thanh di zigzag
private:
    float direction = 1.0f; //-1 la trai, +1 la phai

public:
    ArmoredTank(const std::shared_ptr<sf::Texture>& tex);
    ~ArmoredTank() = default;
    void move(float deltaTime) override;
    void shoot() override;

};

#endif