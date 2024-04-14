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
        this->sourceRectangle.x = static_cast<int>(x);
        this->sourceRectangle.y = static_cast<int>(y);
        
        this->destinationRectangle.x = this->sourceRectangle.x;
        this->destinationRectangle.y = this->sourceRectangle.y; 

        this->destinationRectangle.w = this->sourceRectangle.w;
        this->destinationRectangle.w = this->sourceRectangle.w;        
    }

    //Getters 
    public:
    Object2D(float w, float h, float x, float y);
    float getWidth();
    float getHeight();
    Vector2 getPosition();

    //Setters
    void setDimension(float w, float h);
    void setWidth(float w);
    void setHeight(float h);
    void setPosition(float x, float y);

    //public functions 
    void translate(float dx, float dy);

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