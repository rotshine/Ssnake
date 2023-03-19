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
    std::vector<Player> player;
    // std::vector<sf::Vector2f> m_positions;
    sf::Keyboard::Key m_direction;
    const sf::Vector2f size = sf::Vector2f(7.0f, 7.0f);
    float m_speed = 200.f;
    float m_borderOffSet = 3.5f;
};