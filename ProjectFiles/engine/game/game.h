#ifndef GAME_H 
#define GAME_H 

#include <string>
#include <SDL2/SDL.h>
#include <iostream>
#include "../sprite/sprite.h"
#include "../player/player.h"
#include "../helpers/helpers.h"

class Game {
    public:
        Sprite s;
        Player p;

        //Class attributes 
        std::string title;
        SDL_Window * gWindow; 
        SDL_Renderer * gRenderer;
        bool running; 
        //Class methods 
        void render();
        void eventHandler();
        void update();
        //getters and setters
        SDL_Renderer * getRenderer();
        
        SDL_Window * getWindow();
        
        const char * getTitle();
        void setTitle(const char * title);

        //Constructor 
        Game(std::string title, int posx, int posy, int w, int h, int flag);
    private:
};


#endif 