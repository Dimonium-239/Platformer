#ifndef PLAYER_H
#define PLAYER_H
#include "SFML/Graphics.hpp"
#include "coins.h"
#include "platform.h"

enum moving
{
    RIGHT_BEGIN = 13*32,
    RIGHT_END = 17*32,
    JUMP_BEGIN = 4*32,
    JUMP_END = 7*32,
    STAND_BEGIN = 2*32,
    STAND_END = 3*32,
    BACK_START = 19*32,
    BACK_END = 24*32,
    MIDDLE = 736,

    FRAME = 32,
    BABY = 0,
    KING = 32,
    SOLDER = 64,
    STEP = 3
};

class Player
{
public:
    Player();
    Player(unsigned int WIN_WIGHT, unsigned int WIN_HEIGHT);
    void draw(sf::RenderTarget& target);
    void collide(float x, float y, std::vector <Platform> platforms, std::vector <Platform> water, std::vector<Platform> starway, std::vector<Coins> &coins, std::vector<Platform> tables);
    void update(std::vector <Platform> platforms, std::vector <Platform> water, std::vector<Platform> starway, std::vector<Coins> &coins, std::vector<Platform> tables);
    void spriteMove(int begin, int end, float delay);
    void setStartPosition(float x, float y);
    int getMoneyCounter(){ return money; }
    std::string testMePleas(int a, std::string b);

    sf::Time time;
    sf::Sprite sprite;
    sf::Vector2f velocity;
    bool theEnd = false;
    bool onTable = false;
    unsigned int tableNumber;
    unsigned int WIN_WIGHT;
    unsigned int WIN_HEIGHT;
private:
    sf::IntRect rectSourceSprite;

    int money = 0;
    float left;
    float right;
    float top;
    float bottom;
    bool pickUpCoin = false;
    bool isCollide = false;
    bool isWater = false;
    bool onStar = false;
    bool onGround = false;
    bool faceRight = true;
    bool faceBack = false;
    bool jumping = false;
    bool onTheWater = false;
    bool playerFaceRight;
    bool playerFaceBack;
    float gravity = 0.01f;
};

#endif // PLAYER_H
