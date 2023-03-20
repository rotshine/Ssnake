#include "SFML\Graphics.hpp"
#include <ctime>
#include <random>

class Food
{

public:
    Food();
    ~Food();
    void draw(sf::RenderWindow &window, sf::Vector2f widnowSize);
    void setFoodDraw(bool isFoodDrawn);
    sf::RectangleShape getFoodShape();

private:
    bool m_isFoodDrawn = false;
    float m_borderOffSet = 7.5f;
    float m_foodSize = 15.0f;
    sf::RectangleShape m_food =
        sf::RectangleShape(sf::Vector2f(m_foodSize, m_foodSize));
};
