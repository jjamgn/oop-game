#ifndef Enemy_h
#define Enemy_h

#include <SFML/Graphics.hpp>

using namespace std; 

class Enemy {
protected:
    int hp;
    float speed; //Doi kieu du lieu, trong UML la int
    sf::Vector2f position;
    sf::Sprite image;

public:
    Enemy(sf::Texture& texture); //Do image khong co default constructor, phai duoc gan một sf::Texture, 
    virtual ~Enemy(); //Ke thua nen dung virtual cho destructor luon
    int getHp() const;
    sf::Vector2f getPosition() const;
    float getSpeed() const; //Doi kieu du lieu, trong UML la int
    virtual void update(float deltaTime) = 0;
    virtual void move(float deltaTime) = 0;
    virtual void shoot() = 0;
    virtual void takeDamage(int damage) = 0; //Them tham so khac UML, su dung skill se co damage khac
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual bool isAlive(); //Them virtual, de tro den dung lop con
    virtual bool isBoss(); //Them 

};

#endif