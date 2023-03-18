#include "SFML\Graphics.hpp"
#include <memory>

class Snake
{
public:
    enum BodyPart
    {
        Head,
        Body
    };
    enum Direction
    {
        Right,
        Left,
        Up,
        Down
    };
    struct snake
    {
        sf::Vector2f position;
        BodyPart bodyPart;
    };

    // Constructor

    Snake();

    // Destructor

    ~Snake();

    // Functions

    // void movement(sf::Keyboard::Key key);
     void movement(sf::Event::KeyEvent key);
    // Snake init(Snake::snake);
    void update(snake s);
    void draw(sf::RenderWindow &window);

    // Members

private:
    const float m_kspeed = 6.0f;
    std::vector<snake> m_player = {};
    Direction m_d;
    BodyPart m_bp;
};