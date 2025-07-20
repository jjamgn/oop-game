#include "GameObject.h"


GameObject::GameObject(const shared_ptr<sf::Texture>& tex): 
    texture(tex ? tex : make_shared<sf::Texture>()),
    sprite(*this->texture),
    position(0.0f, 0.0f),
    speed(0.0f),
    hp(1),
    isActive(true),
    isDestroyed(false)
{
    if (!texture) { //Texture == nullptr
        this->texture->resize({1, 1}, true); 
        uint8_t whitePixel[] = {255, 255, 255, 255}; //Tao pixel trang 1x1
        this->texture->update(whitePixel);
        sprite.setTexture(*texture, true); //Cap nhat lai sprite
    }
}

void GameObject::draw(sf::RenderWindow& window) {
    if (isActive && !isDestroyed) {
        window.draw(sprite);
    }
}

void GameObject::takeDamage(int damage) {
    hp -= damage;
    if (hp <= 0) {
        isActive = false;
        isDestroyed = true;
    }
}

bool GameObject::isAlive() const {
    return hp > 0 && !isDestroyed;
}

sf::FloatRect GameObject::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

bool GameObject::checkCollision(const GameObject& other) const {
    return getGlobalBounds().findIntersection(other.getGlobalBounds()).has_value(); //Neu co vung giao nhau tra ve true
}

void GameObject::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
    sprite.setPosition(position);
}

void GameObject::setSpeed(float newSpeed) {
    speed = newSpeed;
}

sf::Vector2f GameObject::getPosition() const {
    return position;
}
