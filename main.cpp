#include <iostream>
#include "SFML\Graphics.hpp"
#include "Snake.h"

// Declarando as variaveis globais
sf::Vector2f viewSize(800, 600);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Ssnake", sf::Style::Default);
const float k_speed = 6.0f;
sf::RectangleShape rect;



// The player
// Player initialization
Snake s(std::vector<Snake::Player>{{sf::Vector2f(2.0, 2.0),
                                   rect}},
        sf::Keyboard::Right);
Food food;

// Renderiza a cobra na tela, para cada elemento do corpo da cobra
void draw()
{
    food.draw(window, viewSize);
    s.draw(window);
}

void updateInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {

        switch (event.type)
        {
        case sf::Event::Closed:
            std::cout << "Aplicação encerrada no botão de fechar";
            window.close();
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
            {
                std::cout << "ESC pressionado";
                window.close();
            }
            break;

        default:
            break;
        }

        s.update(event);
    }
}

int main()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        updateInput();

        window.clear(sf::Color::Black);
        s.move(dt.asSeconds(), viewSize);

        // Desenha todas as entidades.
        draw();
        s.eat(food);

        window.display();
    }

    return 0;
}