#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "SFML/Graphics.hpp"
#include "player.h"
#include "platform.h"
#include "world.h"
#include "button.h"
#include "pause.h"
#include "endwindow.h"
#include <iostream>


class GameLoop
{
    bool pause = false;
    int pauseMenu = 0;
    bool restart = false;
    Pause pauseWindow;
    EndWindow endWindow;
public:
    GameLoop();
};

#endif // GAMELOOP_H
