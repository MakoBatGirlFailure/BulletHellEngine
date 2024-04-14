#include "sprite.h"
//Destructor 
Sprite::~Sprite(){
    
}

//Instantiate the sprite given the path
Sprite::Sprite(const char * resourcePath){
    this->resourcePath = resourcePath;
}

//Init the sprite parameters (this should be called after the constructor)
void Sprite::init(){
    //Temporary surface to be freed 
    SDL_Surface * surface;
    //Load from resource (the path given)
    surface = IMG_Load(resourcePath);
    //Create a texture from surface i think
    this->spriteTex = SDL_CreateTextureFromSurface(this->renderer, surface);
    //free surface 
    SDL_FreeSurface(surface);
    SDL_QueryTexture(this->spriteTex, nullptr, nullptr, &(this->sourceRect.w), &(this->sourceRect.h));
    
    //Set the position to zero, and adjust the destination rectangle to texture resolution
    this->destRect.x = this->sourceRect.x = 0;
    this->destRect.y = this->sourceRect.y = 0;
    
    this->destRect.w = this->sourceRect.w;
    this->destRect.h = this->sourceRect.h;
    
}

//Set the main game renderer
void Sprite::setRenderer(SDL_Renderer * gRenderer){
    this->renderer = gRenderer;
}

//Move the sprite to the given coordinate 
void Sprite::move(float x, float y){
    this->destRect.x = this->sourceRect.x = x;
    this->destRect.y = this->sourceRect.y = y;
    
    this->destRect.w = this->sourceRect.w;
    this->destRect.h = this->sourceRect.h;
}

//Render the sprite 
void Sprite::render(){
    //put this between the RenderClear and RenderPresent     
    SDL_RenderCopy(this->renderer, this->spriteTex, &(this->sourceRect), &(this->destRect));
}

