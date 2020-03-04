#include "button.h"

Button::Button(std::string text)
{
    buttonText.setFont(font);
    buttonText.setCharacterSize(30);
    buttonText.setFillColor(sf::Color(255, 195, 77));
    if (!font.loadFromFile("Assets/ARCADECLASSIC.TTF"))
    {
        std::cerr << "Font not founded" << std::endl;
    }
    buttonText.setString(text);
}

