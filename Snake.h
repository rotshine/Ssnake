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
    // TODO: mudar o codigo para que o vetor m_positions possa ser um vetor de uma struct
    // onde possui as posiçoes e o size da posiçao
    // void setSize(sf::Vector2f newSize);

private:
    float m_speed = 350.f;
    float m_borderOffSet = 7.5f;
    float m_bodySize = 15.f;
    std::vector<Player> player;
    sf::Keyboard::Key m_direction;
    const sf::Vector2f size = sf::Vector2f(m_bodySize, m_bodySize);
};