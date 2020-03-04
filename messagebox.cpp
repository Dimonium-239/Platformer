#include "messagebox.h"

MessageBox::MessageBox()
{
    box.setSize(sf::Vector2f(255, 125));
    sf::Color frame( 195, 80, 60 );
    sf::Color bg(  238, 138, 69 );
    sf::Color textCol( 195, 80, 60 );
    box.setOutlineColor(frame);
    box.setOutlineThickness(10);
    box.setFillColor(bg);
    message.setFillColor(textCol);
    if (!font.loadFromFile("Assets/disposabledroid-bb.regular.ttf"))
    {
        std::cerr << "Font not founded" << std::endl;
    }
    message.setFont(font);
}


void MessageBox::draw(unsigned int number, bool onTable, MessageBox mb, std::vector<Platform> tables, sf::RenderTarget& target){
    mb.box.setPosition(tables.at(number).image.getGlobalBounds().left - mb.box.getSize().x, tables.at(number).image.getGlobalBounds().top - mb.box.getSize().y);
    mb.message.setPosition(tables.at(number).image.getGlobalBounds().left - mb.box.getSize().x + 5, tables.at(number).image.getGlobalBounds().top - mb.box.getSize().y - 5);
    if(number == 0 && onTable){
        message.setString("[w]\\[s] - up\\down\n(in stairs or water)\n[a]\\[d] - left\\right\n[space] - jump\n");
        target.draw(mb.box);
        target.draw(mb.message);
    }
    else if(number == 1 && onTable){
        message.setString("Here some coins!\nCollect 'em all.\nGood Luck!\n");
        target.draw(mb.box);
        target.draw(mb.message);
    }
    else if(number == 2 && onTable){
        message.setString("More features in\nprogress.\nComming soon...");
        target.draw(mb.box);
        target.draw(mb.message);
    }
}
