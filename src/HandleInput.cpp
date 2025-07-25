//Chua long vao Player

#include "HandleInput.h"

HandleInput::HandleInput() {
    for (int i = 0; i < sf::Keyboard::KeyCount; ++i) {
        keyPressed[static_cast<sf::Keyboard::Key>(i)] = false; //Chua nhan ban phim
    }
    for (int i = 0; i < sf::Mouse::ButtonCount; ++i) {
        mouseButtonPressed[static_cast<sf::Mouse::Button>(i)] = false; //Chua nhan chuot
    }
}

void HandleInput::update() {
    for (int i = 0; i < sf::Keyboard::KeyCount; ++i) {
        sf::Keyboard::Key key = static_cast<sf::Keyboard::Key>(i);
        if (sf::Keyboard::isKeyPressed(key)) {
            keyPressed[key] = true;
        } else {
            keyPressed[key] = false;
        }
    }
    for (int i = 0; i < sf::Mouse::ButtonCount; ++i) {
        sf::Mouse::Button button = static_cast<sf::Mouse::Button>(i);
        if (sf::Mouse::isButtonPressed(button)) {
            mouseButtonPressed[button] = true;
        } else {
            mouseButtonPressed[button] = false;
        }
    }
}

bool HandleInput::isKeyPressed(sf::Keyboard::Key key) const { 
    return keyPressed.at(key);
}

bool HandleInput::isKeyDown(sf::Keyboard::Key key) const {
    return sf::Keyboard::isKeyPressed(key);
}

bool HandleInput::isMouseButtonPressed(sf::Mouse::Button button) const {
    return mouseButtonPressed.at(button);
}

sf::Vector2f HandleInput::getMousePosition(const sf::RenderWindow& window) const {
    return window.mapPixelToCoords(sf::Mouse::getPosition(window));
}