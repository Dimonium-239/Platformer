#include "platfomtexture.h"

PlatfomTexture::PlatfomTexture() :
    image(platformSpriteSheet)
{
    platformSpriteSheet.loadFromFile("Assets/sheet.png");
}

sf::Sprite PlatfomTexture::setTexture(int type, int row)
{
    image.setTextureRect(sf::IntRect(type, row, 16, 16));
    return  image;
}
