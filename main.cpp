#include <iostream>
#include "SFML\Graphics.hpp"
#include "Snake.h"
#include <conio.h>

// Declarando as variaveis globais
sf::Vector2f viewSize(800, 600);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Ssnake", sf::Style::Default);
sf::RectangleShape rect;
sf::Texture goTexture;
sf::Sprite s_gameOver;

// checa se o jogo acabou
bool isGameOver = false;

// The player
// Player initialization
Snake s;
Food food;

// Renderiza a cobra na tela, para cada elemento do corpo da cobra
void start()
{
   s.init(std::vector<Snake::Player>{{sf::Vector2f(viewSize.x / 2, viewSize.y / 2), rect}}, sf::Keyboard::Right);
}
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
            window.close();
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
            if(isGameOver){
                if(event.key.code == sf::Keyboard::Enter){
                    start();
                    s.setBorderHit(false);
                    isGameOver = false;
                    food.setFoodDraw(false);
                }
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
    // ------------------------------------------------------------------------------------------------
    if (!goTexture.loadFromFile("Assets/Game-Over.png"))
    {
        std::cout << "Erro ao carregar a textura." << std::endl;
    }
    goTexture.loadFromFile("Assets/GO.png");
    s_gameOver.setTexture(goTexture);
    s_gameOver.setOrigin(goTexture.getSize().x / 2, goTexture.getSize().y);
    s_gameOver.setPosition(viewSize.x / 2, viewSize.y / 2);
    s_gameOver.scale(0.2, 0.2);
    // ------------------------------------------------------------------------------------------------


    start();

    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        updateInput();

        window.clear(sf::Color(186, 186, 186));

        if (s.move(dt.asSeconds(), viewSize))
        {
            window.draw(s_gameOver);
            isGameOver = true;
        }
        s.eat(food);

        // Desenha todas as entidades.
        draw();

        window.display();
    }
    return 0;
}