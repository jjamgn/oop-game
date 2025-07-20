#ifndef TankEnemy_h
#define TankEnemy_h

class TankEnemy: public Enemy {
public:
    TankEnemy(const shared_ptr<sf::Texture>& tex);
    void update(float deltaTime) override;
    void move(float deltaTime) override;
    void shoot() override;
    void takeDamage(int damage) override;
};

#endif