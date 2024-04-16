#ifndef OBJECT_2D
#define OBJECT_2D

#include <SDL2/SDL.h>
#include "../helpers/helpers.h"

class Vector2 {
    public:
    Vector2();
    //Coordinates
    double x; 
    double y;

    void init(double x, double y);

    void setX(double x);
    void setY(double y);
    void setPos(double x, double y);
    
    double getX();
    double getY();

    //get the euclidian distance from a point to another
    double distance(Vector2 another);
    
    //Get another vector 2 reference 
    Vector2 * getPos();
};

//An abstract circle to handle collisions 
class Circle2D{
    public:
    //Constructor 
    Circle2D();
    
    void init(double x, double y, double r);

    Vector2 position;
    double radius;

    //Getter and setter
    double getRadius();
    void setRadius(double value);
};

//An abstract representation of a 2D object, it does have the operations related with Vector2
class Object2D{
    private:
    //Base class member 
    double width;
    double height; 
    Vector2 position;

    //SDL members 
    SDL_Rect sourceRectangle; 
    SDL_Rect destinationRectangle;


    void updateRectangleDimension(double w, double h){
        this->destinationRectangle.w = this->sourceRectangle.w = w;
        this->destinationRectangle.h = this->sourceRectangle.h = h;        
    }
    
    void updateRectanglePosition(double x, double y){
        this->sourceRectangle.x = static_cast<int>(x);
        this->sourceRectangle.y = static_cast<int>(y);
        
        this->destinationRectangle.x = this->sourceRectangle.x;
        this->destinationRectangle.y = this->sourceRectangle.y; 

        this->destinationRectangle.w = this->sourceRectangle.w;
        this->destinationRectangle.w = this->sourceRectangle.w;        
    }

    //Getters 
    public:
    Object2D(double w, double h, double x, double y);
    double getWidth();
    double getHeight();
    Vector2 getPosition();

    //Setters
    void setDimension(double w, double h);
    void setWidth(double w);
    void setHeight(double h);
    void setPosition(double x, double y);

    //public functions 
    void translate(double dx, double dy);
    void update(double dt);
    void render();

    SDL_Rect getSourceRect(){
        return this->sourceRectangle;
    }

    SDL_Rect getDestinationRect(){
        return this->destinationRectangle;
    }

    SDL_Rect * getSourceRectAddr(){
        return &sourceRectangle;
    }

    SDL_Rect * getDestRectAddr(){
        return &destinationRectangle;
    }

};

#endif