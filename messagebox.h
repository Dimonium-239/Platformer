#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <iostream>
#include "platform.h"
#include "SFML/Graphics.hpp"

class MessageBox
{
public:
    MessageBox();
    void draw(unsigned int number, bool onTable, MessageBox mb, std::vector<Platform> tables, sf::RenderTarget& target);
    sf::RectangleShape box;
    sf::Text message;
    sf::Font font;
};

#endif // MESSAGEBOX_H
