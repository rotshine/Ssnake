#include <iostream>
#include "SFML\Graphics.hpp"
#include "Snake.h"
#include <conio.h>

// Declarando as variaveis globais
sf::Vector2f viewSize(800, 600);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Ssnake", sf::Style::Default);
const float k_speed = 6.0f;
sf::RectangleShape rect;
sf::Texture goTexture;
sf::Sprite s_gameOver;

// The player
// Player initialization
Snake s(std::vector<Snake::Player>{
            {sf::Vector2f(2.0, 2.0),
             rect}},
        sf::Keyboard::Right);
Food food;

// Renderiza a cobra na tela, para cada elemento do corpo da cobra
void draw()
{
    s.draw(window);
    food.draw(window, viewSize);
    // window.draw(s_gameOver);
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
    window.setFramerateLimit(15);
    sf::Clock clock;

    // Carrega a textura para o sprite de Game Over.

    if (!goTexture.loadFromFile("Assets/Game-Over.png"))
    {
        std::cout << "Erro ao carregar a textura." << std::endl;
    }
    goTexture.loadFromFile("Assets/Game-Over.png");
    s_gameOver.setTexture(goTexture);
    s_gameOver.setOrigin(goTexture.getSize().x / 2, goTexture.getSize().y);
    s_gameOver.setPosition(viewSize.x / 2, viewSize.y / 2);
    s_gameOver.scale(0.2, 0.2);

    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        updateInput();

        window.clear(sf::Color(186, 186, 186));

        if (s.move(dt.asSeconds(), viewSize))
        {
            window.draw(s_gameOver);
        }
        s.eat(food);

        // Desenha todas as entidades.
        draw();

        window.display();
    }
    return 0;
}