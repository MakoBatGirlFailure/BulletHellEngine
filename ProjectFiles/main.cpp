#include <iostream>
#include "SDL2/SDL.h"
#include "engine/game/game.h"
#include "engine/sprite/sprite.h"

SDL_Window   *    g_pWindow     = 0;
SDL_Renderer *    g_pRenderer   = 0;
bool              g_bRunning    = false;

bool init(const char * title, int posx, int posy, int w, int h, int flag);
void render();
void handleEvents();


int main(int argc, char* args[]){

    Game g("Teste 123", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 420, SDL_WINDOW_SHOWN);
    g.update();
}   
