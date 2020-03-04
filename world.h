#ifndef WORLD_H
#define WORLD_H

#include <fstream>

#include "platform.h"
#include "player.h"
#include "platfomtexture.h"
#include "coins.h"
#include "messagebox.h"
#include "SFML/Graphics.hpp"


class World
{
public:
    World(Player &player);
    void draw(sf::RenderTarget& target, Player& player);
    sf::Sprite backgroundBack;
    sf::Sprite backgroundFront[16];
    sf::Texture bgTextureBack;
    sf::Texture bgTextureFront;
private:
    MessageBox table1;
    sf::Text coinsTextCounter;
    sf::Font font;
    int coinRect = 0;
    sf::Sprite coinsImg;
    sf::Texture coinsTexture;
    sf::Sprite coinsCounter;
    PlatfomTexture platformtexture = PlatfomTexture();
    std::map<std::string, sf::Sprite> sprites;
    sf::View view;
    bool isPlayer = true;
    std::vector<Platform> level;
    std::vector<Platform> decor;
    std::vector<Coins> coins;
    std::vector<Platform> grassNrock;
    std::vector<Platform> water;
    std::vector<Platform> tables;
    std::vector<Platform> starway;

    void readArr(char array[150][150], std::string PATH);
};

#endif // WORLD_H
