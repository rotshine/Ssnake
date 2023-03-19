#include <iostream>
#include "Snake.h"

Snake::Snake(std::vector<sf::Vector2f> corpse, sf::Keyboard::Key direction) : m_positions(corpse), m_direction(direction)
{
}
Snake::~Snake() {}

// Atualiza a direção do moviemnto
void Snake::update(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Right:
            if (m_direction != sf::Keyboard::Left)
            {
                m_direction = sf::Keyboard::Right;
            }
            break;

        case sf::Keyboard::Left:
            if (m_direction != sf::Keyboard::Right)
            {
                m_direction = sf::Keyboard::Left;
            }
            break;

        case sf::Keyboard::Up:
            if (m_direction != sf::Keyboard::Down)
            {
                m_direction = sf::Keyboard::Up;
            }
            break;

        case sf::Keyboard::Down:
            if (m_direction != sf::Keyboard::Up)
            {
                m_direction = sf::Keyboard::Down;
            }
            break;

        default:
            break;
        }
    }
}

// Realiza o movimento do player.
void Snake::move(float dt)
{
    switch (m_direction)
    {
    case sf::Keyboard::Right:
        for (size_t i = 0; i < m_positions.size(); i++)
        {
            std::cout << "Direita" << std::endl;
            m_positions[i].x += m_speed * dt;
        }
        break;

    case sf::Keyboard::Left:
        for (size_t i = 0; i < m_positions.size(); i++)
        {
            std::cout << "Esquerda" << std::endl;
            m_positions[i].x -= m_speed * dt;
        }
        break;

    case sf::Keyboard::Up:
        for (size_t i = 0; i < m_positions.size(); i++)
        {
            m_positions[i].y -= m_speed * dt;
        }
        break;

    case sf::Keyboard::Down:
        for (size_t i = 0; i < m_positions.size(); i++)
        {
            m_positions[i].y += m_speed * dt;
        }
        break;

    default:
        break;
    }
}

// Função para desenhar a nosso player na tela.
void Snake::draw(sf::RenderWindow &window)
{
    for (size_t i = 0; i < m_positions.size(); i++)
    {
        sf::RectangleShape rect;
        rect.setSize(size);
        rect.setOrigin(size.x / 2., size.y / 2.);
        rect.setFillColor(sf::Color::White);
        rect.setPosition(m_positions[i].x, m_positions[i].y);
        rect.setOutlineColor(sf::Color(186, 186, 186)); // Cor um pouco acinzentada.
        rect.setOutlineThickness(1.f);
        window.draw(rect);
    }
}
