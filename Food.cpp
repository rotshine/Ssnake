#include "Food.h"
#include <iostream>

// Constructor initialize the seed that will be used.
Food::Food()
{
    srand(time(NULL));
    m_food.setOrigin(m_food.getSize().x / 2, m_food.getSize().y / 2);
}

Food::~Food()
{
}

void Food::setFoodDraw(bool isFoodDrawn)
{
    m_isFoodDrawn = isFoodDrawn;
}

void Food::draw(sf::RenderWindow &window, sf::Vector2f windowSize)
{

    if (!m_isFoodDrawn)
    {
        sf::Vector2f pos = sf::Vector2f(rand() % static_cast<int>(windowSize.x - m_borderOffSet) + m_borderOffSet,
                                        rand() % static_cast<int>(windowSize.y - m_borderOffSet) + m_borderOffSet);
        m_food.setFillColor(sf::Color::Red);
        m_food.setPosition(pos);
        m_isFoodDrawn = true;
    }
    // std::cout << std::to_string(m_food.getPosition().x) << " " << std::to_string(m_food.getPosition().y) << std::endl;
    window.draw(m_food);
}

sf::RectangleShape Food::getFoodShape()
{
    return m_food;
}