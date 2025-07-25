#ifndef TankEnemy_h
#define TankEnemy_h

class TankEnemy: public Enemy {
public:
    TankEnemy(const std::shared_ptr<sf::Texture>& tex);
    ~TankEnemy() = default;
    void move(float deltaTime) override; //Di thang
    void shoot() override;
};

#endif