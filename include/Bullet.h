#ifndef Bullet_h
#define Bullet_h

#include <SFML/Graphics.hpp>
#include "GameConfig.h"
#include <memory>

enum class BulletType { Normal, Laser, Fan };

class Bullet {
private:
    std::shared_ptr<sf::Texture> texture; //Dung shared_ptr vi cac bullet/explosion dung chung texture
    sf::Sprite sprite; 
    sf::Vector2f position;
    float speed = BulletSpeed; 
    int damage = 1;        
    sf::Vector2f direction; // (0,-1) player ban len, (0,1) enemy ban xuong
    BulletType type;
    float lazerWarningTime = LazerWarningTime;
    float lazerTimer = 0.0f;

public:
    Bullet(const std::shared_ptr<sf::Texture>& tex, BulletType bulletType, sf::Vector2f dir, float spd, int dmg);
    virtual ~Bullet() = default;
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool isOutOfBounds() const;

    int getDamage() const { return damage; }
    sf::FloatRect getBounds() const { return sprite.getGlobalBounds(); } //Tra ve thong tin vi tri, kich thuoc de xu ly va cham
    sf::Vector2f getPosition() const { return position; };

    void setPosition(float x, float y);
    void setSpeed(float newSpeed);
    
};

#endif