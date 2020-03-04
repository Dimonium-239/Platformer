#ifndef PLATFORM_H
#define PLATFORM_H
#include "SFML/Graphics.hpp"

class Platform
{
public:
    sf::Vector2f position;
    sf::Vector2f vel;
    bool isWater;
    int scale;
    float left;
    float top;
    float right;
    float bottom;
    float rectSides[4];
    sf::Sprite image;
    Platform(sf::Vector2f position, sf::Sprite image);
};

#endif // PLATFORM_H
