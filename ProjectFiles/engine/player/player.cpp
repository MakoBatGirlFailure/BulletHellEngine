#include "player.h"

//Instantiate the player (extending Object2D and instantiate the Sprite object)
Player::Player(): Object2D(0,0,0,0), s("assets/sprites/placeholder.png"){
   return;
}

void Player::init(SDL_Renderer * renderer){
    //Set the player's position
    this->setPosition(0,0);

    //Initialize the sprite object
    this->s.setRenderer(renderer);
    this->s.init();

    this->s.setPosition(this->getPosition().x, this->getPosition().y);
    
}

void Player::render(){
    this->s.setPosition(this->getPosition().x, this->getPosition().y);
    this->s.render();
}

void Player::update(float dt){

}