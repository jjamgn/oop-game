#ifnder AirPlane_h
#define AirPlane_h

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <memory>

class AirPlane: public Enemy {
private:
    float direction; //-1 la trai, +1 la phai
    float leftBound, rightBound;
public:
    Airplane(const shared_ptr<sf::Texture>& tex);
    void update(float deltaTime) override;
    void move(float deltaTime) override;
    void shoot() override;
    void takeDamage(int damage) override;
};

#endif