#ifndef PAUSE_H
#define PAUSE_H
#include <iostream>
#include "SFML/Graphics.hpp"


class Pause
{
    sf::View view;
    sf::Text contin;
    sf::Text exit;
    sf::Font font;
    sf::Sprite backgroundBack;
    sf::Texture bgTextureBack;
    int move = 0;
public:
    Pause();
    void draw(sf::RenderTarget &target, int selector, sf::Time time);
};

#endif // PAUSE_H
