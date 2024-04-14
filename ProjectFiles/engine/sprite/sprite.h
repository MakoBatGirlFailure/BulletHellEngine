#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite{
    public:
    //The game renderer
    SDL_Renderer * renderer; 
    //Path for the resource file (the images files)
    const char * resourcePath;
    //Constructor
    Sprite(const char * resourcePath);
    //Destructor
    ~Sprite();
    //Move the sprite 
    void move(float x, float y);
    //Initialize sprite from SDL
    void init();
    //Set the game renderer 
    void setRenderer(SDL_Renderer * gRenderer);
    //Draw the object from scene
    void render();

    //Sprite texture
    SDL_Texture * spriteTex;
    //first rectangle 
    SDL_Rect sourceRect;
    //destination rectangle 
    SDL_Rect destRect;
};


#endif