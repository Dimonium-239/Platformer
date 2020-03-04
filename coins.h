#ifndef COINS_H
#define COINS_H
#include "SFML/Graphics.hpp"

class Coins
{
public:
    Coins(sf::Vector2f position, sf::Sprite image);

    sf::Vector2f position;
    sf::Texture coinsTexture;
    sf::Sprite coins;
    float left;
    float right;
    float top;
    float bottom;

};

#endif // COINS_H
