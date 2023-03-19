#include "Food.h"

// Constructor initialize the seed that will be used.
Food::Food()
{
    srand(time(NULL));
}

Food::~Food()
{
}

void Food::draw(sf::RenderWindow &window, sf::Vector2f windowSize)
{
    sf::RectangleShape rect(m_size);

    rect.setPosition(sf::Vector2f((rand()) % static_cast<int>(windowSize.x),
                                  rand() % static_cast<int>(windowSize.y)));
    rect.setFillColor(sf::Color::Red);
    rect.setOrigin(sf::Vector2f(rect.getPosition().x / 2, rect.getPosition().y / 2));
    



}