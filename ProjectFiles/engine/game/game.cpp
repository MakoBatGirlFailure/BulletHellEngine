#include "game.h"
#include "SDL2/SDL.h"

Game::Game(std::string title, int posx, int posy, int w, int h, int flag){
    //initialize SDL 
    this->title = title; 

    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0){
        this->gWindow = SDL_CreateWindow(this->title.c_str(), posx, posy, w, h, flag);

        if (this->gWindow != 0){
            this->gRenderer = SDL_CreateRenderer(this->gWindow, -1, 0);
            this->running = true;
            return;
        } 

        this->running = false;  
    }
}

void Game::render(){
    SDL_SetRenderDrawColor(this->gRenderer, 0, 0, 0, 255);
    SDL_RenderClear(this->gRenderer);
    SDL_RenderPresent(this->gRenderer);
    
}

void Game::eventHandler(){
    SDL_Event event; 
    if (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_QUIT:
                this->running = false;
            break;

            default:
            break;
        }
    }  
}

void Game::update(){
    while (this->running){
        this->render();
        this->eventHandler();
    }
}
