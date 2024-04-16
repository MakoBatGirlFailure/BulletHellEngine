#include "object2D.h"

Circle2D::Circle2D(): position(){

}

void Circle2D::init(double x, double y, double radius){
   this->position.init(x, y);
   this->setRadius(radius); 
}

void Circle2D::setRadius(double value){
    this->radius = value;
}

double Circle2D::getRadius(){
    return this->radius;
}
