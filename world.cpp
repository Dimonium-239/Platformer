#include "world.h"
#include <iostream>

World::World(Player &player) :
    view(sf::Vector2f(0, 0), sf::Vector2f(640, 480))
{
    bgTextureBack.loadFromFile("Assets/Background/back.png");
    bgTextureFront.loadFromFile("Assets/Background/middle.png");
    backgroundBack.setTexture(bgTextureBack);

    if (!font.loadFromFile("Assets/ARCADECLASSIC.TTF")) ///home/dimonium_239/Game1
    {
        std::cerr << "Font not founded" << std::endl;
    }
    coinsTextCounter.setFont(font);
    coinsTextCounter.setCharacterSize(30);

    coinsTextCounter.setFillColor(sf::Color(255, 195, 77));


    view.setCenter(sf::Vector2f(640/2, 480/2));
    sprites = {
        std::make_pair("grass1", platformtexture.setTexture(16*7, 0)),
        std::make_pair("grass1", platformtexture.setTexture(16*8, 0)),
        std::make_pair("grass3", platformtexture.setTexture(16*9, 0)),

        std::make_pair("undGravel", platformtexture.setTexture(16*8, 16*7)),
        std::make_pair("undGravelL", platformtexture.setTexture(16*7, 16*7)),
        std::make_pair("undGravelR", platformtexture.setTexture(16*9, 16*7)),

        std::make_pair("undGrassR", platformtexture.setTexture(16*13, 16*7)),
        std::make_pair("undGrassL", platformtexture.setTexture(16*16, 16*7)),
        std::make_pair("undGrass", platformtexture.setTexture(16*14, 16*7)),

        std::make_pair("gravelCornerLeft", platformtexture.setTexture(16*10, 0)),
        std::make_pair("gravel2", platformtexture.setTexture(16*11, 0)),
        std::make_pair("gravelCornerRight", platformtexture.setTexture(16*12, 0)),

        std::make_pair("gravelStack", platformtexture.setTexture(16*13, 0)),
        std::make_pair("undergroundWithRock", platformtexture.setTexture(16*7, 16)),

        std::make_pair("grassCornerLeft", platformtexture.setTexture(16*8, 16)),
        std::make_pair("grassCornerRight", platformtexture.setTexture(16*9, 16)),
        std::make_pair("gravelWallLeft", platformtexture.setTexture(16*10, 16)),
        std::make_pair("gravelWallRight", platformtexture.setTexture(16*12, 16)),

        std::make_pair("undergound", platformtexture.setTexture(16*11, 16)),
        //std::make_pair("table", platformtexture.setTexture(16*14, 16)),
        std::make_pair("grasBottLeft", platformtexture.setTexture(16*10, 16*5)),

        std::make_pair("water", platformtexture.setTexture(16*8, 16*5)),
        std::make_pair("deepWater", platformtexture.setTexture(16*8, 16*6)),

        std::make_pair("decLDCorn", platformtexture.setTexture(16*9, 16*3)),
        std::make_pair("decRDCorn", platformtexture.setTexture(16*10, 16*3)),
        std::make_pair("decLTCorn", platformtexture.setTexture(16*9, 16*4)),
        std::make_pair("decRTCorn", platformtexture.setTexture(16*10, 16*4)),
        std::make_pair("decBg1", platformtexture.setTexture(16*9, 16*6)),
        std::make_pair("decBg2", platformtexture.setTexture(16*10, 16*6)),
        std::make_pair("decGrass", platformtexture.setTexture(16*11, 16*3)),
        std::make_pair("decBgTop", platformtexture.setTexture(16*12, 16*4)),
        std::make_pair("decBgL", platformtexture.setTexture(16*11, 16*4)),
        std::make_pair("decBgR", platformtexture.setTexture(16*13, 16*4)),
        std::make_pair("decBgWalL", platformtexture.setTexture(16*11, 16*5)),
        std::make_pair("decBgWalR", platformtexture.setTexture(16*13, 16*5)),
        std::make_pair("decBgBotL", platformtexture.setTexture(16*11, 16*6)),
        std::make_pair("decBgBot", platformtexture.setTexture(16*12, 16*6)),
        std::make_pair("decBgBotR", platformtexture.setTexture(16*13, 16*6)),

        std::make_pair("holeL", platformtexture.setTexture(16*9, 16*4)),
        std::make_pair("holeR", platformtexture.setTexture(16*10, 16*4)),
        std::make_pair("holeD", platformtexture.setTexture(16*9, 16*5)),
        std::make_pair("holeB", platformtexture.setTexture(16*10, 16*5)),

        std::make_pair("flowers1", platformtexture.setTexture(16*15, 16*5)),
        std::make_pair("flowers2", platformtexture.setTexture(16*14, 16*5)),
        std::make_pair("flowers3", platformtexture.setTexture(16*15, 16*6)),
        std::make_pair("flowers4", platformtexture.setTexture(16*14, 16*6)),
        std::make_pair("sterwayTop", platformtexture.setTexture(16*7, 16*4)),
        std::make_pair("sterwayMidd", platformtexture.setTexture(16*7, 16*5)),
        std::make_pair("sterwayDown", platformtexture.setTexture(16*7, 16*6)),

        std::make_pair("fanceFrontStart", platformtexture.setTexture(16*14, 16*2)),
        std::make_pair("fanceFrontMid", platformtexture.setTexture(16*15, 16*2)),
        std::make_pair("fanceFrontEnd", platformtexture.setTexture(16*16, 16*2)),

        std::make_pair("fanceBackStart", platformtexture.setTexture(16*14, 16*3)),
        std::make_pair("fanceBackMid", platformtexture.setTexture(16*15, 16*3)),
        std::make_pair("fanceBackEnd", platformtexture.setTexture(16*16, 16*3)),

        std::make_pair("rock1", platformtexture.setTexture(16*16, 16*5)),
        std::make_pair("rock2", platformtexture.setTexture(16*16, 16*6)),

        std::make_pair("table", platformtexture.setTexture(16*16, 0)),

        std::make_pair("bg", platformtexture.setTexture(16*12, 16*5))
    };

    for(int i = 0; i < 16; i++){
        backgroundFront[i].setTexture(bgTextureFront);
        backgroundFront[i].scale(3, 3);
        backgroundFront[i].setPosition(i*backgroundFront[0].getGlobalBounds().width, 480/2);
    }


    coinsTexture.loadFromFile("Assets/coins2.png");

    coinsImg.setTexture(coinsTexture);
    coinsCounter.setTexture(coinsTexture);
    coinsCounter.setTextureRect(sf::IntRect(0, 0, 167, 150));
    coinsCounter.setScale(.2f, .2f);

    backgroundBack.scale(2, 2);
    backgroundBack.setPosition(0, 0);


    char map[150][150];
    char deco[150][150];
    char grassNrockArr[150][150];

    readArr(map, "Maps/map1.m");
    readArr(deco, "Maps/deco1.m");
    readArr(grassNrockArr, "Maps/grassNrock.m");

    for(unsigned int y = 0; y <= 150; y++){
        for(unsigned int x = 0; x <= 150; x++){
            if(map[y][x] == '-') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["grass1"]));
            if(map[y][x] == '_') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["gravel2"]));
            if(map[y][x] == '#') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["undergound"]));
            if(map[y][x] == 'l') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["grassCornerLeft"]));
            if(map[y][x] == 'u') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["gravelCornerLeft"]));
            if(map[y][x] == 'r') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["grassCornerRight"]));
            if(map[y][x] == 'b') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["gravelCornerRight"]));
            if(map[y][x] == 's') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["gravelWallLeft"]));
            if(map[y][x] == 'c') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["gravelWallRight"]));
            if(map[y][x] == 'm') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["grasBottLeft"]));
            if(map[y][x] == '=') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["undGravel"]));
            if(map[y][x] == '[') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["undGravelL"]));
            if(map[y][x] == ']') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["undGravelR"]));
            if(map[y][x] == 'z') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["undGrassR"]));
            if(map[y][x] == 'x') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["undGrassL"]));
            if(map[y][x] == 'v') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["undGrass"]));
            if(map[y][x] == '.') level.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["undergroundWithRock"]));

            if(map[y][x] == 'T') starway.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["sterwayTop"]));
            if(map[y][x] == 'H') starway.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["sterwayMidd"]));
            if(map[y][x] == 'U') starway.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["sterwayDown"]));

            if(map[y][x] == 'w') water.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["water"]));
            if(map[y][x] == 'd') water.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["deepWater"]));

            if(map[y][x] == '"') tables.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["table"]));

            if(deco[y][x] == '1') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["decBg1"]));
            if(deco[y][x] == '2') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["decBg2"]));
            if(deco[y][x] == 'q') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["decBgL"]));
            if(deco[y][x] == 'w') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["decBgTop"]));
            if(deco[y][x] == 'e') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["decBgR"]));
            if(deco[y][x] == 'a') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["decBgWalL"]));
            if(deco[y][x] == 's') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["bg"]));
            if(deco[y][x] == 'd') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["decBgWalR"]));
            if(deco[y][x] == 'z') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["decBgBotL"]));
            if(deco[y][x] == 'x') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["decBgBot"]));
            if(deco[y][x] == 'c') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["decBgBotR"]));
            if(grassNrockArr[y][x] == 'N') grassNrock.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["water"]));
            if(grassNrockArr[y][x] == 'M') grassNrock.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["deepWater"]));

            if(deco[y][x] == '4') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["holeL"]));
            if(deco[y][x] == '5') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["holeR"]));
            if(deco[y][x] == '6') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["holeD"]));
            if(deco[y][x] == '7') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["holeB"]));

            if(grassNrockArr[y][x] == 'g') grassNrock.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["decGrass"]));
            if(grassNrockArr[y][x] == 'r') grassNrock.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["rock1"]));
            if(grassNrockArr[y][x] == 'o') grassNrock.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["rock2"]));
            if(grassNrockArr[y][x] == '1') grassNrock.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["flowers1"]));
            if(grassNrockArr[y][x] == '2') grassNrock.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["flowers2"]));
            if(grassNrockArr[y][x] == '3') grassNrock.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["flowers3"]));
            if(grassNrockArr[y][x] == '4') grassNrock.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["flowers4"]));

            if(grassNrockArr[y][x] == '[') grassNrock.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["fanceFrontStart"]));
            if(grassNrockArr[y][x] == '=') grassNrock.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["fanceFrontMid"]));
            if(grassNrockArr[y][x] == ']') grassNrock.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["fanceFrontEnd"]));

            if(grassNrockArr[y][x] == '{') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["fanceBackStart"]));
            if(grassNrockArr[y][x] == '+') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["fanceBackMid"]));
            if(grassNrockArr[y][x] == '}') decor.push_back(Platform(sf::Vector2f(FRAME*x, FRAME*y), sprites["fanceBackEnd"]));

            if(grassNrockArr[y][x] == '*') coins.push_back(Coins(sf::Vector2f(FRAME*x, FRAME *y), coinsImg));

            if(map[y][x] == '@'){
                player.sprite.setPosition(x*FRAME, y*FRAME);
            }
        }
    }

    for (unsigned int i = 0; i < tables.size(); i++){
        tables.at(i).image.setScale(3, 3);
        tables.at(i).image.setPosition(tables.at(i).image.getPosition().x - 16,
                                       tables.at(i).image.getPosition().y - 16);
    }
}


void World::draw(sf::RenderTarget &target, Player &player)
{
    coinsTextCounter.setString(" " + std::to_string(player.getMoneyCounter()));

    if(player.sprite.getPosition().x + 640/2 <= player.WIN_WIGHT){
        view.setCenter(sf::Vector2f(640/2, view.getCenter().y)); //270
        coinsCounter.setPosition(player.WIN_WIGHT - 100, 150);
        coinsTextCounter.setPosition(player.WIN_WIGHT - 60, 155);
        backgroundBack.setPosition(0, 64);
        for(int i = 0; i < 16; i++){
            backgroundFront[i].setPosition(i*backgroundFront[0].getGlobalBounds().width + 95, 480 - 4*34);
        }
    }
    else if(player.sprite.getPosition().x >= 145*FRAME - 640/2){
        view.setCenter(sf::Vector2f(145*FRAME - 640/2, view.getCenter().y));
        coinsCounter.setPosition(145*FRAME - 100, 150);
        coinsTextCounter.setPosition(145*FRAME - 60, 155);
        backgroundBack.setPosition(145*FRAME - 768 + 95, 64);
        for(int i = 0; i < 16; i++){
            backgroundFront[i].setPosition(i*backgroundFront[0].getGlobalBounds().width + 236, 480 - 4*34);
        }
    }
    else{
        view.setCenter(sf::Vector2f(player.sprite.getPosition().x, view.getCenter().y));
        backgroundBack.setPosition(player.sprite.getPosition().x*0.8f - (640*.8f)/2, 64);
        coinsCounter.setPosition(player.sprite.getPosition().x + 220, 150);
        coinsTextCounter.setPosition(player.sprite.getPosition().x + 260, 150);
        for(int i = 0; i < 16; i++){
            backgroundFront[i].setPosition(i*backgroundFront[0].getGlobalBounds().width + player.sprite.getPosition().x*0.3f, 480 - 4*34);
        }
    }

    if(player.sprite.getPosition().y <= player.WIN_HEIGHT + 32){
        view.setCenter(sf::Vector2f(view.getCenter().x, 480 - 100));
        coinsCounter.setPosition(coinsCounter.getPosition().x, 150);
        coinsTextCounter.setPosition(coinsTextCounter.getPosition().x, 145);
        backgroundBack.setPosition(backgroundBack.getPosition().x, -64);
        for(int i = 0; i < 16; i++){
            backgroundFront[i].setPosition(backgroundFront[i].getPosition().x, 480 - 4*34);
        }
    }
    else{
        view.setCenter(sf::Vector2f(view.getCenter().x, 32*FRAME - 480/2));
        backgroundBack.setPosition(backgroundBack.getPosition().x, 64);
        coinsTextCounter.setPosition(coinsTextCounter.getPosition().x, 18*FRAME - 27);
        coinsCounter.setPosition(coinsCounter.getPosition().x, 18*FRAME - 22);
        for(int i = 0; i < 16; i++){
            backgroundFront[i].setPosition(backgroundFront[i].getPosition().x, 480 - 4*34);
        }
    }

    target.setView(view);
    for (unsigned int i = 0; i < decor.size(); i++)
        target.draw(decor.at(i).image);
    for (unsigned int i = 0; i < starway.size(); i++)
        target.draw(starway.at(i).image);
    for (unsigned int i = 0; i < tables.size(); i++){
        target.draw(tables.at(i).image);
    }
    table1.draw(player.tableNumber, player.onTable, table1, tables, target);
        player.draw(target);
    for (unsigned int i = 0; i < water.size(); i++)
        target.draw(water.at(i).image);
    for (unsigned int i = 0; i < grassNrock.size(); i++)
        target.draw(grassNrock.at(i).image);
    for (unsigned int i = 0; i < level.size(); i++)
        target.draw(level.at(i).image);

    target.draw(coinsTextCounter);
    target.draw(coinsCounter);

    if(player.time.asSeconds() <= .04f)
    {
        if (coinRect == 1002)
            coinRect = 0;
        else
            coinRect += 167;
    }
    for (unsigned int i = 0; i < coins.size(); i++){
        coins.at(i).coins.setTextureRect(sf::IntRect(coinRect, 0, 167, 150));
        target.draw(coins.at(i).coins);
    }

    player.update(level, water, starway, coins, tables);
}

void World::readArr(char array[150][150], std::string PATH){
    try{
    std::ifstream fp(PATH);
    if(!fp.good())
        throw "Error opening file!";
    std::string line;
    int y = 0;
    while (std::getline(fp, line, '\n')){
        int x = 0;
        for(char ascii : line){
            if(ascii == '|'){
                break;
            }
            array[y][x] = ascii;
            x++;
        }
        y++;
    }
    fp.close();
    } catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

