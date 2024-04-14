#ifndef OBJECT_2D
#define OBJECT_2D

#include <SDL2/SDL.h>

struct Position2D {
    float x;
    float y;
};

typedef struct Position2D Vector2;

//An abstract representation of a 2D object, it does have the operations related with Vector2
class Object2D{
    private:
    //Base class member 
    float width;
    float height; 
    Vector2 position;

    //SDL members 
    SDL_Rect sourceRectangle; 
    SDL_Rect destinationRectangle;

    void updateRectangleDimension(float w, float h){
        this->destinationRectangle.w = this->sourceRectangle.w = w;
        this->destinationRectangle.h = this->sourceRectangle.h = h;
    }
    
    void updateRectanglePosition(float x, float y){
        this->destinationRectangle.x = this->sourceRectangle.w = x;
        this->destinationRectangle.y = this->sourceRectangle.h = y;    

        this->destinationRectangle.w = this->sourceRectangle.w;
        this->destinationRectangle.h = this->sourceRectangle.h;
    }

    //Getters 
    public:
    Object2D(float w, float h, float x, float y);
    float getWidth();
    float getHeight();
    Vector2 getPosition();

    //Setters
    void setWidth(float w);
    void setHeight(float h);
    void setPosition(float x, float y);

    //public functions 
    void translate(float dx, float dy);
    

};

#endif