#ifndef HandleInput_h
#define HandleInput_h

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <map>

class HandleInput {
private:
    std::map<sf::Keyboard::Key, bool> keyPressed; //Luu trang thai phim
    std::map<sf::Mouse::Button, bool> mouseButtonPressed; //Luu trang thai chuot

public:
    HandleInput();
    ~HandleInput() = default;
    void update();
    bool isKeyPressed(sf::Keyboard::Key key) const; //Kiem tra ban phim
    bool isKeyDown(sf::Keyboard::Key key) const;
    bool isMouseButtonPressed(sf::Mouse::Button button) const; //Kiem tra chuot
    sf::Vector2f getMousePosition(const sf::RenderWindow& window) const;

};

#endif