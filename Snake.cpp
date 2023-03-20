#include "Snake.h"

Snake::Snake(std::vector<Player> initialPlayer,
             sf::Keyboard::Key direction)
    : player(initialPlayer), m_direction(direction)
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
void Snake::move(float dt, sf::Vector2f windowSize)
{

    // TODO:
    // Checar pela colisão das laterais para que a cobra e todo o seu corpo pare de andar ao atingir a borda.
    switch (m_direction)
    {
    case sf::Keyboard::Right:
        for (size_t i = 0; i < player.size(); i++)
        {
            player[i].pos.x += m_speed * dt;

            if (player[i].pos.x + m_borderOffSet > windowSize.x)
            {
                player[i].pos.x = windowSize.x - m_borderOffSet;
            }
        }
        break;

    case sf::Keyboard::Left:
        for (size_t i = 0; i < player.size(); i++)
        {
            player[i].pos.x -= m_speed * dt;

            if (player[i].pos.x - m_borderOffSet < 0)
            {
                player[i].pos.x = m_borderOffSet;
            }
        }
        break;

    case sf::Keyboard::Up:
        for (size_t i = 0; i < player.size(); i++)
        {
            player[i].pos.y -= m_speed * dt;

            if (player[i].pos.y - m_borderOffSet < 0)
            {
                player[i].pos.y = m_borderOffSet;
            };
        }
        break;

    case sf::Keyboard::Down:
        for (size_t i = 0; i < player.size(); i++)
        {
            player[i].pos.y += m_speed * dt;

            if (player[i].pos.y + m_borderOffSet > windowSize.y)
            {
                player[i].pos.y = windowSize.y - m_borderOffSet;
            };
        }
        break;

    default:
        break;
    }
}

// Função para desenhar a nosso player na tela.
void Snake::draw(sf::RenderWindow &window)
{
    for (size_t i = 0; i < player.size(); i++)
    {
        player[i].shape.setSize(size);
        player[i].shape.setFillColor(sf::Color::White);
        player[i].shape.setOutlineColor(sf::Color(186, 186, 186)); // Cor um pouco acinzentada.
        player[i].shape.setOutlineThickness(1.f);
        player[i].shape.setPosition(player[i].pos.x, player[i].pos.y);
        player[i].shape.setOrigin(size.x / 2., size.y / 2.);
        window.draw(player[i].shape);
    }
}

void Snake::eat(Food &food)
{
    if (collider(player[0].shape, food.getFoodShape()))
    {
        food.setFoodDraw(false);

        sf::RectangleShape rect;
        sf::Vector2f toAdd;

        switch (m_direction)
        {
        case sf::Keyboard::Right:
            toAdd = sf::Vector2f(-m_bodySize, 0.0);
            break;
        case sf::Keyboard::Left:
            toAdd = sf::Vector2f(+m_bodySize, 0.0);
            break;
        case sf::Keyboard::Up:
            toAdd = sf::Vector2f(0.0, +m_bodySize);
            break;
        case sf::Keyboard::Down:
            toAdd = sf::Vector2f(0.0, -m_bodySize);
            break;
        default:
            break;
        }

        Player adder = {
            .pos = player.back().pos + toAdd,
            .shape = rect

        };

        player.push_back(adder);
    }
}