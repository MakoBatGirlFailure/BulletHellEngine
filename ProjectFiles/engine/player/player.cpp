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
    this->s.init(renderer);

    this->s.setPosition(this->getPosition().x, this->getPosition().y);
    
}

void Player::render(){
    this->s.setPosition(this->getPosition().x, this->getPosition().y);
    this->s.render();
}

void Player::update(double dt){
    SDL_Event event;
    double speed = 150.0;
    this->setPosition(this->getPosition().x + (speed * dt), this->getPosition().y);
    /**switch(SDL_PollEvent(&event)){
            case SDL_KEYDOWN: {
                std::cout << "Botão pressionado" << std::endl;
                switch(event.key.keysym.sym){
                    case SDLK_LEFT:
                        this->setPosition(this->getPosition().x - speed * dt, this->getPosition().y);
                    break;
                    case SDLK_RIGHT:
                        this->setPosition(this->getPosition().x + speed * dt, this->getPosition().y);
                    break;
                    case SDLK_UP:
                        this->setPosition(this->getPosition().x, this->getPosition().y - speed * dt);
                    break;
                    case SDLK_DOWN:
                        this->setPosition(this->getPosition().x, this->getPosition().y + speed * dt);
                    break;

                }
            }
            break;

            default:
            break;
    
    PLACEHOLDER CODE BY THE WAY
    }**/
}