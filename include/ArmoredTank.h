#ifnder ArmoredTank_h
#define ArmoredTank_h

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <memory>

class ArmoredTank: public Enemy {
private:
    float direction; //-1 la trai, +1 la phai
    float leftBound, rightBound;
public:
    ArmoredTank(const shared_ptr<sf::Texture>& tex);
    void update(float deltaTime) override;
    void move(float deltaTime) override;
    void shoot() override;
    void takeDamage(int damage) override;
};

#endif