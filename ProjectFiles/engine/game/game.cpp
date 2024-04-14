#include "game.h"

Game::Game(std::string title, int posx, int posy, int w, int h, int flag): p(), s("assets/sprites/placeholder.png"){
    //initialize SDL 
    this->title = title; 

    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0){
        this->gWindow = SDL_CreateWindow(this->title.c_str(), posx, posy, w, h, flag);

        if (this->gWindow != 0){
            this->gRenderer = SDL_CreateRenderer(this->gWindow, -1, 0);
            this->running = true;
            
            //Debug zone for another components 
            this->s.setRenderer(this->gRenderer);
            this->s.init();
            this->p.init(this->gRenderer);
            this->p.translate(30, 0);
            return;
        } 

        this->running = false;  
    }

}

void Game::render(){
    SDL_SetRenderDrawColor(this->gRenderer, 0, 0, 0, 255);
    SDL_RenderClear(this->gRenderer);
    this->s.render();
    this->p.render();
    SDL_RenderPresent(this->gRenderer);
    
    //s.move(640/2, 420/2);    
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
