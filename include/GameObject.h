#ifndef GameObject_h
#define GameObject_h

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

using namespace std;

class GameObject {
protected:
    shared_ptr<sf::Texture> texture; //Dung shared_ptr vi cac bullet/explosion dung chung texture
    sf::Sprite sprite; 
    sf::Vector2f position;
    float speed = 0.0f; //pixel/s
    int hp;                       
    bool isActive = true;                
    bool isDestroyed = false;  

public:
    GameObject(const shared_ptr<sf::Texture>& tex);
    virtual ~GameObject() = default;
    virtual void update(float deltaTime) = 0; 
    virtual void draw(sf::RenderWindow& window);
    virtual void takeDamage(int damage);
    virtual bool isAlive() const;
    sf::FloatRect getGlobalBounds() const; //Tra ve thong tin vi tri, kich thuoc de xu ly va cham
    bool checkCollision(const GameObject& other) const;
    void setPosition(int x, int y);
    void setSpeed(float newSpeed);
    sf::Vector2f getPosition() const;
    int getHp() const { return hp; }
};

#endif