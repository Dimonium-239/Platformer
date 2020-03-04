#include "endwindow.h"

EndWindow::EndWindow() :
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
    /*
    restart.setFont(font);
    restart.setCharacterSize(30);
    restart.setFillColor(sf::Color(255, 195, 77));
    restart.setString("RESTART");
    restart.setPosition(480/2 + 20, 300);
    */

    exit.setFont(font);
    exit.setCharacterSize(30);
    exit.setFillColor(sf::Color(255, 195, 77));
    exit.setString("EXIT");
    exit.setPosition(480/2 + 55, 450);

    pressEnter.setString("[press ENTER to continue]");
    pressEnter.setFont(font);
    pressEnter.setCharacterSize(30);
    pressEnter.setFillColor(sf::Color(255, 195, 77));
    pressEnter.setPosition(480/2 - 60, 450);

    goodBay.setString("Thats all. Demonstration  of  this\ngame ended.\n\nHope you enjoid!\n");
    goodBay.setFont(font);
    goodBay.setCharacterSize(30);
    goodBay.setFillColor(sf::Color(255, 195, 77));
    goodBay.setPosition(480/2 - 60, 250);

    view.setCenter(sf::Vector2f(640/2, 480/2));
}

void EndWindow::draw(sf::RenderTarget &target, int selector, sf::Time time){
    //if(selector == 0){
        //restart.setFillColor(sf::Color( 229, 44, 7 ));
     //   exit.setFillColor(sf::Color(255, 195, 77));
    //}else if(selector == 1){
        //restart.setFillColor(sf::Color(255, 195, 77));
        exit.setFillColor(sf::Color( 229, 44, 7 ));
    //}

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
        target.draw(goodBay);
        if(time.asSeconds() <= .16f){
            target.draw(pressEnter);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
            enterPressed = true;
        }
        if(enterPressed){
            view.setCenter(sf::Vector2f(640/2, 370));
            backgroundBack.setPosition(move, 0);
            target.setView(view);
            target.draw(backgroundBack);
            //target.draw(restart);
            target.draw(exit);
    }
}
