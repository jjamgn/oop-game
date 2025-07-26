//Chua long vao Player

#include "HandleInput.h"

HandleInput::HandleInput(Player* player) : m_Player(player) {
    for (int i = 0; i < sf::Keyboard::KeyCount; ++i) {
        keyPressed[static_cast<sf::Keyboard::Key>(i)] = false;
    }
    for (int i = 0; i < sf::Mouse::ButtonCount; ++i) {
        mouseButtonPressed[static_cast<sf::Mouse::Button>(i)] = false;
    }
}

void HandleInput::update(float deltaTime, std::vector<Enemy*>& enemies) {
    for (int i = 0; i < sf::Keyboard::KeyCount; ++i) { //Trang thai phim
        sf::Keyboard::Key key = static_cast<sf::Keyboard::Key>(i);
        keyPressed[key] = sf::Keyboard::isKeyPressed(key);
    }
    for (int i = 0; i < sf::Mouse::ButtonCount; ++i) { //Trang thai chuot
        sf::Mouse::Button button = static_cast<sf::Mouse::Button>(i);
        mouseButtonPressed[button] = sf::Mouse::isButtonPressed(button);
    }
    if (keyPressed[sf::Keyboard::Key::Left]) { //Di chuyen trai
        m_Player->move(deltaTime, -1);
    }
    if (keyPressed[sf::Keyboard::Key::Right]) { //Di chuyen phai
        m_Player->move(deltaTime, 1);
    }
    if (mouseButtonPressed[sf::Mouse::Button::Left] || keyPressed[sf::Keyboard::Key::Space]) { //Ban thuong
        m_Player->shoot();
    }
    if (mouseButtonPressed[sf::Mouse::Button::Right] || keyPressed[sf::Keyboard::Key::Enter]) { //Su dung ki nang
        m_Player->useSkill(enemies);
    }
}

sf::Vector2f HandleInput::getMousePosition(const sf::RenderWindow& window) const {
    return window.mapPixelToCoords(sf::Mouse::getPosition(window));
}