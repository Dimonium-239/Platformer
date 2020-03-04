#include "platform.h"

Platform::Platform(sf::Vector2f position, sf::Sprite sprite)
{
    scale = 2;
    image = sprite;
    image.setPosition(position);
    image.setScale(scale, scale);
    left = image.getPosition().x;
    right = image.getPosition().x + image.getGlobalBounds().width;
    top = image.getPosition().y;
    bottom = image.getPosition().y + image.getGlobalBounds().height;
}
