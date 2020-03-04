#include "player.h"
#include <iostream>

Player::Player(unsigned int WIN_WIGHT, unsigned int WIN_HEIGHT)
{
    static sf::Texture texture;
    texture.loadFromFile("Assets/characters.png");

    rectSourceSprite.top = KING;
    rectSourceSprite.left = 0;
    rectSourceSprite.width =  32;
    rectSourceSprite.height = 32;

    sprite.setTexture(texture);
    sprite.setTextureRect(rectSourceSprite);
    sprite.scale(2, 2);

    this->WIN_WIGHT = WIN_WIGHT;
    this->WIN_HEIGHT = WIN_HEIGHT;
}


void Player::setStartPosition(float x, float y)
{
    sprite.setPosition(x, y);
}


void Player::draw(sf::RenderTarget& target)
{
    sprite.setTextureRect(rectSourceSprite);
    target.draw(sprite);
}


void Player::update(std::vector <Platform> platforms, std::vector <Platform> water, std::vector <Platform> starway, std::vector<Coins> &coins, std::vector<Platform> tables)
{

    if(onGround || onStar)
        velocity.y = 0;
    else if(!(onGround || onStar))
        velocity.y += .5f;

    if((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && !onTheWater)
    {
        velocity.x = -STEP;
        if(!jumping)
            spriteMove(2*MIDDLE-RIGHT_END, 2*MIDDLE-RIGHT_BEGIN, .05f);
        faceRight = false;
        faceBack = false;
    }

    if((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && !onTheWater)
    {
        velocity.x = STEP;
        if(!jumping)
            spriteMove(RIGHT_BEGIN, RIGHT_END, .05f);
        faceRight = true;
        faceBack = false;
    }

    if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
    sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
    {
        velocity.x = 0;
        if(faceRight){
            spriteMove(STAND_BEGIN, STAND_END, .0175f);
        }
        else if(!faceRight){
            spriteMove(2*MIDDLE-STAND_END, 2*MIDDLE-STAND_BEGIN, .0175f);
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && onGround)
    {
        jumping = true;
        velocity.y = -7;
        onGround = false;
    }
    if(jumping)
    {
        if(faceRight)
            spriteMove(JUMP_BEGIN, JUMP_END, .04f);
        else
            spriteMove(2*MIDDLE-JUMP_END, 2*MIDDLE-JUMP_BEGIN, .04f);
    }

    onGround = false;
    sprite.move(sf::Vector2f(velocity.x, 0));
    collide(velocity.x, 0, platforms, water, starway, coins, tables);
    sprite.move(sf::Vector2f(0, velocity.y));
    collide(0, velocity.y, platforms, water, starway, coins, tables);
}

void Player::collide(float x, float y, std::vector <Platform> platforms, std::vector <Platform> water, std::vector<Platform> starway, std::vector<Coins>& coins, std::vector<Platform> tables)
{
    if(sprite.getPosition().x + 16 < 0){
        sprite.setPosition(-16, sprite.getPosition().y);
    }
    if(sprite.getPosition().x  > 144*FRAME){
        sprite.setPosition(144*FRAME, sprite.getPosition().y);
        theEnd = true;
        std::cout << "THIS IS THE END" << std::endl;
    }

    for (auto c = coins.begin(); c != coins.end(); c++)
    {
        if(sprite.getGlobalBounds().intersects(c->coins.getGlobalBounds())){
           c = coins.erase(c);
           money += 10;
        }
    }

    for (auto t : tables){
        if(sprite.getGlobalBounds().intersects(tables.at(0).image.getGlobalBounds())){
            tableNumber = 0;
            onTable = true;
        }
        else if(sprite.getGlobalBounds().intersects(tables.at(1).image.getGlobalBounds())){
            tableNumber = 1;
            onTable = true;
        }

        else if(sprite.getGlobalBounds().intersects(tables.at(2).image.getGlobalBounds())){
            tableNumber = 2;
            onTable = true;
        }

        else onTable = false;
    }

    for(auto p : platforms){
        if(sprite.getPosition().x + sprite.getLocalBounds().width + 11 > p.left &&
           sprite.getPosition().x + 17 < p.right &&
           sprite.getPosition().y + sprite.getLocalBounds().height*1.5f + 16 > p.top &&
           sprite.getPosition().y + 16 < p.bottom){

           isCollide = true;
        }else {
            isCollide = false;
        }
        if(isCollide){
            if(x > 0){
                sprite.setPosition(sf::Vector2f(p.left - sprite.getLocalBounds().width - 11, sprite.getPosition().y));
            }
            if(x < 0){
                sprite.setPosition(sf::Vector2f(p.right - 17, sprite.getPosition().y));
            }
            if(y > 0){
                sprite.setPosition(sf::Vector2f(sprite.getPosition().x, p.top - sprite.getLocalBounds().height *2.f));
                onGround = true;
                jumping = false;
            }
            if(y < 0){
                sprite.setPosition(sf::Vector2f(sprite.getPosition().x, p.bottom - 16));
            }
        }
    }
    for(auto s : starway){
        if(sprite.getPosition().x + sprite.getLocalBounds().width + 11 > s.left &&
           sprite.getPosition().x + 17 < s.right &&
           sprite.getPosition().y + sprite.getLocalBounds().height*1.5f + 16 > s.top &&
           sprite.getPosition().y + 16 < s.bottom){

           onStar = true;
           onGround = true;
           //velocity.y = 0;
           spriteMove(BACK_START, BACK_END, .023f);

        }else {
           onStar = false;
        }
        if(onStar){
            if((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
            {
                velocity.y = -STEP;
                velocity.x = 0;
                faceBack = true;
                onGround = true;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                velocity.y = STEP;
                velocity.x = 0;
                faceBack = true;
                onGround = true;
            }
        }
    }
    for(auto w : water){
        if(sprite.getPosition().x + sprite.getLocalBounds().width + 11 > w.left &&
           sprite.getPosition().x + 17 < w.right &&
           sprite.getPosition().y + sprite.getLocalBounds().height*1.5f + 16 > w.top &&
           sprite.getPosition().y + 16 < w.bottom){

           isWater = true;
            velocity.y = .5f;
        }else {
           isWater = false;
        }
        if(isWater){
            if((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
            {
                spriteMove(BACK_START, BACK_END, .023f);
                velocity.y = -1;
                faceBack = true;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                spriteMove(BACK_START, BACK_END, .023f);
                velocity.y = 1;
                faceBack = true;
            }
        }
    }
}

void Player::spriteMove(int begin, int end, float delay)
{
    if(time.asSeconds() <= delay)
    {
        if(rectSourceSprite.left < begin || rectSourceSprite.left > end)
            rectSourceSprite.left = begin;
        else if (rectSourceSprite.left == end)
            rectSourceSprite.left = begin;
        else
            rectSourceSprite.left += FRAME;
    }
}

std::string Player::testMePleas(int a, std::string b){
    std::string str;
    for(int i = 0; i < a; i++){
        str += b;
    }
    return str;
}




