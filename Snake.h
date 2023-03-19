#include "SFML\Graphics.hpp"
#include <memory>

class Snake
{
public:
    enum Anatomy
    {
        Head,
        Body
    };
    // enum Direction
    // {
    //     Right,
    //     Left,
    //     Up,
    //     Down
    // };

    Snake(std::vector<sf::Vector2f> corpse, sf::Keyboard::Key direction);
    ~Snake();

    void update(sf::Event event);
    void move(float dt);
    void draw(sf::RenderWindow &window);
    // TODO: mudar o codigo para que o vetor m_positions possa ser um vetor de uma struct
    // onde possui as posiçoes e o size da posiçao
    // void setSize(sf::Vector2f newSize);

private:
    std::vector<sf::Vector2f> m_positions;
    sf::Keyboard::Key m_direction;
    sf::Vector2f size = sf::Vector2f(7.0f, 7.0f);
    float m_speed = 100.f;
    
};