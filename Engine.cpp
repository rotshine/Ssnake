#include "Engine.h"

bool Engine::collider(sf::RectangleShape player, sf::RectangleShape food)
{
    auto firstBox = player.getGlobalBounds();
    auto secondBox =  food.getGlobalBounds();

    return firstBox.intersects(secondBox);

}