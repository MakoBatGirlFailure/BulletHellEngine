#include "sprite.h"
//Destructor 
Sprite::~Sprite(){
    
}

//Instantiate the sprite given the path
Sprite::Sprite(const char * resourcePath): Object2D(0, 0, 0, 0){
    this->resourcePath = resourcePath;
}

//Init the sprite parameters (this should be called after the constructor)
void Sprite::init(SDL_Renderer * gRenderer){
    //set the renderer 
    this->setRenderer(gRenderer);
    //Temporary surface to be freed 
    SDL_Surface * surface;
    //Load from resource (the path given)
    surface = IMG_Load(resourcePath);
    //Create a texture from surface i think
    this->spriteTex = SDL_CreateTextureFromSurface(this->renderer, surface);
    //free surface 
    SDL_FreeSurface(surface);
    
    //get the texture dimensions into the rects 
    int w, h;
    SDL_QueryTexture(this->spriteTex, nullptr, nullptr, &w, &h);
    

    //Set the position to zero, and adjust the destination rectangle to texture resolution
    this->setPosition(0, 0);
    this->setDimension(w, h);
}

//Set the main game renderer
void Sprite::setRenderer(SDL_Renderer * gRenderer){
    this->renderer = gRenderer;
}


//Render the sprite 
void Sprite::render(){
    //put this between the RenderClear and RenderPresent     
    SDL_RenderCopy(this->renderer, this->spriteTex, nullptr, this->getDestRectAddr());
}

