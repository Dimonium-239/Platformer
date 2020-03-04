#ifndef PLATFOMTEXTURE_H
#define PLATFOMTEXTURE_H
#include "SFML/Graphics.hpp"


class PlatfomTexture
{
public:
    PlatfomTexture();
    sf::Sprite setTexture(int type, int row);
    sf::Texture platformSpriteSheet;
    sf::Sprite image;
};

#endif // PLATFOMTEXTURE_H
