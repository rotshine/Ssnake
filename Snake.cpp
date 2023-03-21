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
    // sf::Vector2f n(0.0, 0.0);
    // sf::Vector2f nPlus_1(0.0, 0.0);

    // iterador que captura a posiçao atual e a proxima posiçao, depois troca seus valores
    for (int i = 0; i < player.size(); i++)
    {

        /* / Move as posiçoes do vetor
        // Talvez este código possa ficar abaixo, fora da função lambda
        if (i + 1 < player.size())
        {
        nPlus_1 = player[i + 1].pos;
        std::cout << player[i].pos.x << " " << player[i].pos.y << std::endl;
        std::cout << nPlus_1.x << " " << nPlus_1.y << std::endl;
        }

        // Checa se a iteração está na cabeça (indice 0), caso true move a cobra.
        n = player[i].pos; */

        // ---------------

        n = player[i].pos;
        if (i + 1 < player.size())
        {
            nPlus_1 = player[i + 1].pos;
        }
        if (i == 0)
        {
            switch (m_direction)

            {
            case sf::Keyboard::Right:
                player[0].pos.x += m_speed * dt;

                if (player[0].pos.x + m_borderOffSet > windowSize.x)
                {
                    player[0].pos.x = windowSize.x - m_borderOffSet;
                }

                break;

            case sf::Keyboard::Left:

                player[0].pos.x -= m_speed * dt;

                if (player[0].pos.x - m_borderOffSet < 0)
                {
                    player[0].pos.x = m_borderOffSet;
                }

                break;

            case sf::Keyboard::Up:
                player[0].pos.y -= m_speed * dt;

                if (player[0].pos.y - m_borderOffSet < 0)
                {
                    player[0].pos.y = m_borderOffSet;
                };
                break;

            case sf::Keyboard::Down:
                player[0].pos.y += m_speed * dt;

                if (player[0].pos.y + m_borderOffSet > windowSize.y)
                {
                    player[0].pos.y = windowSize.y - m_borderOffSet;
                };
                break;

            default:
                break;
            }
        }

        if (i != 0)
        {
            player[i].pos = n;
            n = nPlus_1;
        }
        // Move os valores do corpo no vetor
        // Condiçao executa depois de passar pela cabeça (indice 0).

        // std::cout << player[i].pos.x << " " << player[i].pos.y << std::endl;
        // std::cout << nPlus_1.x << " " << nPlus_1.y << std::endl;
        // std::cout << player.size() << std::endl;
    }

    // TODO:
    // Checar pela colisão das laterais para que a cobra e todo o seu corpo pare de andar ao atingir a borda.
    /*  switch (m_direction)
     {
     case sf::Keyboard::Right:

         for (size_t i = 0; i < player.size(); i++)
         {
             player[0].pos.x += m_speed * dt;

             if (player[0].pos.x + m_borderOffSet > windowSize.x)
             {
                 player[0].pos.x = windowSize.x - m_borderOffSet;
             }
         }

         break;

     case sf::Keyboard::Left:
         for (size_t i = 0; i < player.size(); i++)
         {
             player[0].pos.x -= m_speed * dt;

             if (player[0].pos.x - m_borderOffSet < 0)
             {
                 player[0].pos.x = m_borderOffSet;
             }
         }
         break;

     case sf::Keyboard::Up:
         for (size_t i = 0; i < player.size(); i++)
         {
             player[0].pos.y -= m_speed * dt;

             if (player[0].pos.y - m_borderOffSet < 0)
             {
                 player[0].pos.y = m_borderOffSet;
             };
         }
         break;

     case sf::Keyboard::Down:
         for (size_t i = 0; i < player.size(); i++)
         {
             player[0].pos.y += m_speed * dt;

             if (player[0].pos.y + m_borderOffSet > windowSize.y)
             {
                 player[0].pos.y = windowSize.y - m_borderOffSet;
             };
         }
         break;

     default:
         break;
     } */
}

// Função para desenhar a nosso player na tela.
void Snake::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < player.size(); i++)
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
            .shape = rect

        };

        // Adiciona o struct ao vetor, criando uma parte nova do corpo
        player.push_back(adder);
    }
}