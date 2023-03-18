#include "Snake.h"
#include <iostream>

// A parte do corpo

Snake::Snake() {}
Snake::~Snake() {}

// Snake Snake::init(Snake::snake s)
// {
//     Snake i_s;
//     i_s.update(s);
//     return i_s;
// }

void Snake::movement(sf::Event::KeyEvent key)
{
    // Checa se a direção da cobra é valida para o próximo movimento
    auto checkDirection = [&](Direction d) -> bool
    {
        switch (d)
        {
        case Direction::Right:
            if (m_d != Direction::Left)
            {
                m_d = Direction::Right;
                return true;
            }
            else
            {
                return false;
            }
            break;

        case Direction::Left:
            if (m_d != Direction::Right)
            {
                m_d = Direction::Left;
                return true;
            }
            else
            {
                return false;
            }
            break;

        case Direction::Up:
            if (m_d != Down)
            {
                m_d = Direction::Up;
                return true;
            }
            else
            {
                return false;
            }
            break;

        case Direction::Down:
            if (m_d != Up)
            {
                m_d = Direction::Down;
                return true;
            }
            else
            {
                return false;
            }
            break;
        default:
            return false;
            break;
        }
    };

    // Checa a tecla de entrada e executa o movimento de acordo
    switch (key.code)
    {

    case sf::Keyboard::Key::Right:

        if (checkDirection(Direction::Right))
        {
            std::cout << "direita" << std::endl;
            // std::cout << "funfo";
            // for (int i = 0; i < this->m_player.size(); i++)
            // {
            //     this->m_player[i].position.x += 6.0f;
            // }

            m_player[0].position.x + m_kspeed;
        }
        break;

    case sf::Keyboard::Key::Left:
        if (checkDirection(Direction::Left))
        {
            std::cout << "esquerda" << std::endl;
            m_player[0].position.x - m_kspeed;
        }
        break;
    case sf::Keyboard::Key::Up:
        if (checkDirection(Direction::Up))
        {
            std::cout << "up" << std::endl;
            m_player[0].position.y - m_kspeed;
        }
    case sf::Keyboard::Key::Down:
        if (checkDirection(Direction::Down))
        {
            std::cout << "down" << std::endl;
            m_player[0].position.y + m_kspeed;
        }

    default:
        break;
    }
}

void Snake::update(Snake::snake snake)
{
    m_player.push_back(snake);
}

void Snake::draw(sf::RenderWindow &window)
{

    for (int i = 0; i < m_player.size(); i++)
    {
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(5.0f, 5.0f));
        rect.setFillColor(sf::Color::White);
        rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
        rect.setPosition(m_player[i].position.x, m_player[i].position.y);
        window.draw(rect);
    }
}
