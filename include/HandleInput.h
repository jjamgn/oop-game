#ifndef HandleInput_h
#define HandleInput_h

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <unordered_map>

class HandleInput {
private:
    Player* m_Player;
    std::unordered_map<sf::Keyboard::Key, bool> keyPressed; //Luu trang thai phim
    std::unordered_map<sf::Mouse::Button, bool> mouseButtonPressed; //Luu trang thai chuot

public:
    HandleInput(Player* m_Player);
    ~HandleInput() = default;
    void update(float deltaTime, std::vector<Enemy*>& enemies);
    sf::Vector2f getMousePosition(const sf::RenderWindow& window) const;

};

#endif