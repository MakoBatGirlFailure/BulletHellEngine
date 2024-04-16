#include "object2D.h"

Vector2::Vector2(){

}

void Vector2::init(double x, double y){
    this->setPos(x, y);
}

void Vector2::setX(double x){
    this->x = x;
}

void Vector2::setY(double y){
    this->y = y;
}

void Vector2::setPos(double x, double y){
    this->x = x;
    this->y = y;
}
    
double Vector2::getX(){
    return this->x;
}

double Vector2::getY(){
    return this->y;   
}

Vector2* Vector2::getPos(){
    return this;
}

double Vector2::distance(Vector2 another){
    return SDL_sqrt((this->x*this->x) - (this->y*this->y)) + ((another.x*another.x) - (another.y*another.y));
}