#include <iostream>
#include "SFML\Graphics.hpp"
#include "Snake.h"

// Declarando as variaveis globais
sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Ssnake", sf::Style::Default);

// The player
Snake s;

// Renderiza a cobra na tela, para cada elemento do corpo da cobra
void draw()
{
}

void updateInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {

        switch (event.type)
        {
        case sf::Event::Closed:
            std::cout << "fechei";
            window.close();
        case sf::Event::KeyPressed:
            s.movement(event.key);
            event.key.code;
            break;

        default:
            break;
        }

    }
}

int main()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        updateInput();

        sf::Time dt = clock.restart();
        window.clear(sf::Color::Black);
        s.draw(window);

        window.display();
    }

    return 0;
}