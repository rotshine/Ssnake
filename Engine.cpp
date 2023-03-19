#include "Engine.h"

bool Engine::collider(sf::RectangleShape &player, sf::RectangleShape food)
{

    sf::FloatRect boundingBox = player.getGlobalBounds();
    sf::FloatRect targetBox = food.getGlobalBounds();

    return boundingBox.intersects(targetBox);
}