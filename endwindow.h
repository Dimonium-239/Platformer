#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include <iostream>
#include "SFML/Graphics.hpp"


class EndWindow
{
    sf::View view;
    //sf::Text restart;
    sf::Text exit;
    sf::Text goodBay;
    sf::Text pressEnter;
    sf::Font font;
    sf::Sprite backgroundBack;
    sf::Texture bgTextureBack;
    int move = 0;
    bool enterPressed = false;
public:
    EndWindow();
    void draw(sf::RenderTarget &target, int selector, sf::Time time);
};

#endif // ENDWINDOW_H
