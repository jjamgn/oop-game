#ifndef Bullet_h
#define Bullet_h

#include <SFML/Graphics.hpp>

using namespace std; 

class Bullet {
protected:
    sf::Vector2f position;
    float speed; ////Doi kieu du lieu, trong UML la int
    int damage;
    sf::Sprite image;

public:
    Bullet(sf::Texture& texture); //Do image khong co default constructor, phai duoc gan một sf::Texture, 
    virtual ~Bullet(); //Ke thua nen dung virtual cho destructor luon
    virtual void update(float deltaTime) = 0;
    virtual int getDamage() = 0;
    virtual sf::Vector2f getPosition() = 0;
    virtual bool checkOutOfBound() = 0;
    virtual bool isAlive() = 0;
    virtual bool checkCollisions() = 0;
    virtual void draw(sf::RenderWindow &window) = 0;

};

#endif