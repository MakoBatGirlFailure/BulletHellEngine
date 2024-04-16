#include "helpers.h"

void drawCircle(SDL_Renderer * renderer, double centerX, double centerY, double radius){
    for (int width=0; width<(int)radius*2; ++width){
        for (int height=0; height<(int)radius*2; height++){
            int dx = (int)radius - width;
            int dy = (int)radius - height;

            if (dx*dx+dy*dy<= radius*radius){
                SDL_RenderDrawPoint(renderer, (int)centerX+dx, (int)centerY+dy);
            }
        }
    }
}
