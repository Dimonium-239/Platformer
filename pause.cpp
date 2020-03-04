#include "pause.h"

Pause::Pause() :
    view(sf::Vector2f(0, 0), sf::Vector2f(640, 480))
{
    bgTextureBack.loadFromFile("Assets/Background/back.png");
    backgroundBack.scale(2, 2);
    backgroundBack.setPosition(0, 0);
    backgroundBack.setTexture(bgTextureBack);

    if (!font.loadFromFile("Assets/disposabledroid-bb.regular.ttf"))
    {
        std::cerr << "Font not founded" << std::endl;
    }
    contin.setFont(font);
    contin.setCharacterSize(30);
    contin.setFillColor(sf::Color(255, 195, 77));
    contin.setString("CONTINUE");
    contin.setPosition(480/2 + 20, 300);

    exit.setFont(font);
    exit.setCharacterSize(30);
    exit.setFillColor(sf::Color(255, 195, 77));
    exit.setString("EXIT");
    exit.setPosition(480/2 + 55, 450);

    view.setCenter(sf::Vector2f(640/2, 480/2));
}

void Pause::draw(sf::RenderTarget &target, int selector, sf::Time time){
    if(selector == 0){
        contin.setFillColor(sf::Color( 229, 44, 7 ));
        exit.setFillColor(sf::Color(255, 195, 77));
    }else if(selector == 1){
        contin.setFillColor(sf::Color(255, 195, 77));
        exit.setFillColor(sf::Color( 229, 44, 7 ));
    }

    if(time.asSeconds() <= .0175f)
    {
        if (move < -760)
            move = 0;
        else
            move -= 2;
    }
    view.setCenter(sf::Vector2f(640/2, 370));
    backgroundBack.setPosition(move, 0);
    target.setView(view);
    target.draw(backgroundBack);
    target.draw(contin);
    target.draw(exit);
}
