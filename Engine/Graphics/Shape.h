#ifndef COW_SHAPE_H 
#define COW_SHAPE_H
#include <SDL2/SDL.h>

enum ShapeFlags{
    Rect, Circle, Line
}ShapeFlags;

typedef struct SofaShape{
    double *shape;
    unsigned int size;
    enum ShapeFlags f;
} SofaShape;

void RenderShape(SofaShape *shape, SDL_Window *window){
    switch(shape -> f){
        case 0:
        renderRect(shape, window);
        break;
        case 1:
        renderCircle(shape, window);
        break;
        case 2:
        renderLine(shape, window);
        default:
        return;
    }
}

void renderRect(SofaShape *shape, SDL_Window *window) {

}

void renderCircle(SofaShape *shape, SDL_Window *window) {

}

void renderLine(SofaShape *shape, SDL_Window *window) {

}

#endif