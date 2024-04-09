#include <iostream>
#include "SDL2/SDL.h"

SDL_Window   *    g_pWindow     = 0;
SDL_Renderer *    g_pRenderer   = 0;
bool              g_bRunning    = false;

bool init(const char * title, int posx, int posy, int w, int h, int flag);
void render();
void handleEvents();


int main(int argc, char* args[]){

    g_bRunning = init("Insert Text Here", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    while (g_bRunning){
        render();
        handleEvents();
    }

    SDL_Quit();
    return 0;
}   

void render(){
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(g_pRenderer);
    SDL_RenderPresent(g_pRenderer);
    
}

bool init(const char * title, int posx, int posy, int w, int h, int flag){
    //initialize SDL 
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0){
        g_pWindow = SDL_CreateWindow(title, posx, posy, w, h, flag);

        if (g_pWindow != 0){
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
            return true;
        } 

        return false; 

    }
}

void handleEvents(){
    SDL_Event event; 
    if (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_QUIT:
                g_bRunning = false;
            break;

            default:
            break;
        }
    }
}