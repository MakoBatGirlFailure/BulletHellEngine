#ifndef GAME_H 
#define GAME_H 

#include <string>
#include <SDL2/SDL.h>
#include "../sprite/sprite.h"

class Game {
    public:
        //Temporary sprite component 
     

        //Class attributes 
        std::string title;
        SDL_Window * gWindow; 
        SDL_Renderer * gRenderer;
        bool running; 
        //Class methods 
        void render();
        void eventHandler();
        void update();
        Game(std::string title, int posx, int posy, int w, int h, int flag);
    private:
};


#endif 