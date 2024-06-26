#ifndef SPRITE_H
#define SPRITE_H
#include "../2dObject/object2D.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite: public Object2D{
    public:
    //The game renderer
    SDL_Renderer * renderer; 
    //Path for the resource file (the images files)
    
    
    const char * resourcePath;
    //Constructor
    Sprite(const char * resourcePath);
    //Destructor
    ~Sprite();
    //Initialize sprite from SDL
    void init(SDL_Renderer * gRenderer);
    //Set the game renderer 
    void setRenderer(SDL_Renderer * gRenderer);
    //Draw the object from scene
    void render();

    //Sprite texture
    SDL_Texture * spriteTex;
 };


#endif