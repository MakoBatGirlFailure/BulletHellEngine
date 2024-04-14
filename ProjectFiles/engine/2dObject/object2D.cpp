#include "object2D.h"
#include <iostream>

//Object2D constructor 
Object2D::Object2D(float w, float h, float x, float y){
    this->width = w;
    this->height = h;
    this->position.x = x; 
    this->position.y = y; 
}


float Object2D::getWidth(){
    return this->width;
}

float Object2D::getHeight(){
    return this->height;
}

Vector2 Object2D::getPosition(){
    return this->position;
}

//Setters
void Object2D::setDimension(float w, float h){
    this->width = w; 
    this->height = h;
    updateRectangleDimension(this->width, this->height);
}

void Object2D::setWidth(float w){
    this->width = w;
    updateRectangleDimension(this->width, this->height);
}

void Object2D::setHeight(float h){
    this->height = h;
    updateRectangleDimension(this->width, this->height);
}

void Object2D::setPosition(float x, float y){
    this->position.x = x;
    this->position.y = y; 

    updateRectanglePosition(this->position.x, this->position.y);
}

//public functions 
void Object2D::translate(float dx, float dy){
    this->position.x += dx;
    this->position.y += dy; 

    updateRectanglePosition(this->position.x, this->position.y);
}