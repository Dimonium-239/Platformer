#ifndef BUTTON_H
#define BUTTON_H
#include "SFML/Graphics.hpp"
#include <iostream>


class Button
{
public:
    Button(std::string text);
    sf::Text buttonText;
    sf::Font font;
};

#endif // BUTTON_H
