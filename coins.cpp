#include "coins.h"

Coins::Coins(sf::Vector2f position, sf::Sprite image)
{
    coins = image;
    coins.setScale(0.2f, 0.2f);
    coins.setPosition(position.x, position.y - coins.getGlobalBounds().height/2);
    left = coins.getPosition().x;
    right = coins.getPosition().x + coins.getGlobalBounds().width;
    top = coins.getPosition().y;
    bottom = coins.getPosition().y + coins.getGlobalBounds().height;
}


