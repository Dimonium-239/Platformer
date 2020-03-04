#include "gameloop.h"

static unsigned int WIN_WIGHT = 640;
static unsigned int WIN_HEIHT = 480;

GameLoop::GameLoop()
{
    sf::RenderWindow renderWindow(sf::VideoMode(WIN_WIGHT, WIN_HEIHT), "Dude");
    renderWindow.setFramerateLimit(60);

    sf::Clock clock;
    Player player = Player(WIN_WIGHT, WIN_HEIHT);
    World world = World(player);

      sf::Event event;
      player.time = clock.getElapsedTime();
      if(player.time.asSeconds() > .2f)
          player.time = clock.restart();
      while (renderWindow.isOpen()){

      while (renderWindow.pollEvent(event)){
        if (event.type == sf::Event::EventType::Closed)
          renderWindow.close();
        else if(event.type == sf::Event::KeyPressed){
            if (event.key.code == sf::Keyboard::Escape){
                pause = true;
            }
            if(pause && (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)){
                pauseMenu ++;
                if(pauseMenu == 2)
                    pauseMenu = 0;
            }
            else if(pause && (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)){
                pauseMenu --;
                if(pauseMenu == -1)
                    pauseMenu = 1;
            }

            if(pause && pauseMenu == 0 && event.key.code == sf::Keyboard::Enter){
                pause = false;
            }
            else if(((pause && pauseMenu == 1) || player.theEnd) && event.key.code == sf::Keyboard::Enter){
                renderWindow.close();
            }

            /*if(player.theEnd && (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)){
                pauseMenu ++;
                if(pauseMenu == 2 || pauseMenu == -2)
                    pauseMenu = 0;
            }
            else if(player.theEnd && (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)){
                pauseMenu --;
                if(pauseMenu == -1|| pauseMenu == -2)
                    pauseMenu = 1;
            }*/

        }
        }
       renderWindow.clear();
      if(!(pause || player.theEnd)){

          renderWindow.draw(world.backgroundBack);
          for (int i = 0; i < 16; i++) {
           renderWindow.draw(world.backgroundFront[i]);
          }
          world.draw(renderWindow, player);

        }else if(pause){
            pauseWindow.draw(renderWindow, pauseMenu, player.time);
        }else if(player.theEnd){
            endWindow.draw(renderWindow, pauseMenu, player.time);
        }
        renderWindow.display();
     }
}
