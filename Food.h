#include "SFML\Graphics.hpp"
#include <ctime>
#include <random>

class Food{

public:
    Food();
    ~Food();
    void draw(sf::RenderWindow &window, sf::Vector2f widnowSize);




private:
    // int m_seed;
    sf::Vector2f m_size = sf::Vector2f(7.0f, 7.0f);
    sf::Vector2f m_position;
};