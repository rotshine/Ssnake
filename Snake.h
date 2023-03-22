#include <iostream>
#include <memory>

#include "SFML\Graphics.hpp"
#include "Food.h"
#include "Engine.h"

class Snake : Engine
{
public:
    enum Anatomy
    {
        Head,
        Body
    };
    struct Player
    {
        sf::Vector2f pos;
        sf::RectangleShape shape;
    };

    Snake(std::vector<Player> initialPlayer, sf::Keyboard::Key direction);
    ~Snake();

    void update(sf::Event event);
    void move(float dt, sf::Vector2f windowSize);
    void draw(sf::RenderWindow &window);
    void eat(Food &food);

private:
    float m_speed = 300.f;
    float m_borderOffSet = 7.5f;
    float m_bodySize = 15.f;
    std::vector<Player> player;
    sf::Keyboard::Key m_direction;
    const sf::Vector2f size = sf::Vector2f(m_bodySize, m_bodySize);
    bool m_isBorderHit = false;
    // sf::Vector2f n;
    // sf::Vector2f nPlus_1;
};