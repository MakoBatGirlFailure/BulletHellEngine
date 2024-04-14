#ifndef PLAYER_H
#define PLAYER_H

#include "../2dObject/object2D.h"
#include "../sprite/sprite.h"

class Player: public Object2D{
    public:
    //Constructor
    Player();
    //Player's sprite texture
    Sprite s;
    //initialize the modules
    void init(SDL_Renderer * renderer);
    
    //render the player sprite 
    void render();
    void update(float dt);
    
};

#endif 
