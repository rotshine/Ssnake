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
bool Snake::move(float dt, sf::Vector2f windowSize)
{
    sf::Vector2f n(0.0, 0.0);
    sf::Vector2f n2(0.0, 0.0);

    // lambda para realizar o movimento das posiçoes no vetor.
    auto moveBody = [&](int index)
    {
        if (index > 0)
        {
            n2 = player[index].pos;
            player[index].pos = n;
            n = n2;
        }
    };

    n = player[0].pos;

    // Checa se o player encostou nas bordas, se sim, para todos os movimentos.

    if (m_isBorderHit)
    {
        return m_isBorderHit;
    }
    else
    {
        // iterador que captura a posiçao atual e a proxima posiçao, depois troca seus valores
        for (int i = 0; i < player.size(); i++)
        {
            // ---------------

            if (i == 0)
            {
                n = player[i].pos;

                switch (m_direction)

                {
                case sf::Keyboard::Right:
                    player[0].pos.x += m_speed * dt;

                    if (player[0].pos.x + m_borderOffSet > windowSize.x)
                    {
                        player[0].pos.x = windowSize.x - m_borderOffSet;
                        m_isBorderHit = true;
                    }
                    break;

                case sf::Keyboard::Left:
                    player[0].pos.x -= m_speed * dt;
                    if (player[0].pos.x - m_borderOffSet < 0)
                    {
                        player[0].pos.x = m_borderOffSet;
                        m_isBorderHit = true;
                    }
                    break;

                case sf::Keyboard::Up:
                    player[0].pos.y -= m_speed * dt;
                    if (player[0].pos.y - m_borderOffSet < 0)
                    {
                        player[0].pos.y = m_borderOffSet;
                        m_isBorderHit = true;
                    };

                    break;
                case sf::Keyboard::Down:
                    player[0].pos.y += m_speed * dt;
                    if (player[0].pos.y + m_borderOffSet > windowSize.y)
                    {
                        player[0].pos.y = windowSize.y - m_borderOffSet;
                        m_isBorderHit = true;
                    };
                    break;

                default:
                    break;
                }
            }
            // Move as outras partes do corpo no indice "i"
            moveBody(i);
        }
    }
    return false;
}

// Função para desenhar a nosso player na tela.
void Snake::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < player.size(); i++)
    {
        player[i].shape.setSize(size);
        player[i].shape.setFillColor(sf::Color::Black);
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

        // Cria um objeto do tipo RectangleShape, usado apenas na funçao draw
        sf::RectangleShape rect;

        // Objeto utilizado para criar o offset do ultimo elemento, onde cada direçao tem um valor diferente de adiçao
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

        // Cria a struct que sera adicionada ao nosso vetor player.
        // pega o ultimo elemento do vetor e adiciona um offset que chamei de "toAdd",
        Player adder = {
            .pos = player.back().pos + toAdd,
            .shape = rect};

        // Adiciona o struct ao vetor, criando uma parte nova do corpo
        player.push_back(adder);
    }
}