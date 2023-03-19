#include "Food.h"

// Constructor initialize the seed that will be used.
Food::Food()
{
    srand(time(NULL));
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
        sf::Vector2f pos = sf::Vector2f((rand()) % static_cast<int>(windowSize.x - 3.5f),
                     rand() % static_cast<int>(windowSize.y - 3.5f));
        m_food.setFillColor(sf::Color::Red);
        m_food.setOrigin(sf::Vector2f(m_food.getPosition().x / 2, m_food.getPosition().y / 2));
        m_food.setPosition(pos);

        m_isFoodDrawn = true;
    }

    window.draw(m_food);
}

sf::RectangleShape Food::getFoodShape(){
    return m_food;
}