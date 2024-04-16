#ifndef OBJECT_2D
#define OBJECT_2D

#include <SDL2/SDL.h>

struct Position2D {
    double x;
    double y;
};

typedef struct Position2D Vector2;

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