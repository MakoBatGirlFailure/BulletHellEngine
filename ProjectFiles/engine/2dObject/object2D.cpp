#include "object2D.h"
#include <iostream>

//Object2D constructor 
Object2D::Object2D(double w, double h, double x, double y){
    this->width = w;
    this->height = h;
    this->position.x = x; 
    this->position.y = y; 
}


double Object2D::getWidth(){
    return this->width;
}

double Object2D::getHeight(){
    return this->height;
}

Vector2 Object2D::getPosition(){
    return this->position;
}

//Setters
void Object2D::setDimension(double w, double h){
    this->width = w; 
    this->height = h;
    updateRectangleDimension(this->width, this->height);
}

void Object2D::setWidth(double w){
    this->width = w;
    updateRectangleDimension(this->width, this->height);
}

void Object2D::setHeight(double h){
    this->height = h;
    updateRectangleDimension(this->width, this->height);
}

void Object2D::setPosition(double x, double y){
    this->position.x = x;
    this->position.y = y; 

    updateRectanglePosition(this->position.x, this->position.y);
}

//public functions 
void Object2D::translate(double dx, double dy){
    this->position.x += dx;
    this->position.y += dy; 

    updateRectanglePosition(this->position.x, this->position.y);
}

void Object2D::update(double dt){

}