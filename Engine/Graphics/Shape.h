#ifndef COW_SHAPE_H 
#define COW_SHAPE_H
#include <SDL2/SDL.h>
#include <stdio.h>

enum ShapeFlags{
    Rect, Circle, Line
}ShapeFlags;


// organization of shape array:
// rect: provide corner x, y, w, h
// circle: provide x y of center and r [x, y, r]
// line: provide 2 points [x,y,x,y]
typedef struct SofaShape{
    double *shape;
    unsigned int size;
    enum ShapeFlags f;
} SofaShape;

typedef struct RendererOptions{
    uint8_t *rgba;
} RendererOptions;

void RenderShape(SofaShape *shape, SDL_Window *window, SDL_Renderer *renderer, RendererOptions *r){
    //printf("f: %d\r\n",shape -> f);
    //printf("shape size: %d\r\n", shape->size);
    switch(shape -> f){
        case 0:
        renderRect(shape, renderer, r);
        break;
        case 1:
        renderCircle(shape, renderer, r);
        break;
        case 2:
        renderLine(shape, renderer, r);
        default:
        return;
    }
}

void renderRect(SofaShape *shape, SDL_Renderer *renderer, RendererOptions *r) {
    SDL_Rect rect;
    //printf("rendering rect\r\n");
    for(unsigned int i = 0; i < shape -> size; i++) {
        //printf("%d\r\n", i%4);
        switch(i%4){
            case 0:
            rect.x = shape -> shape[i];
            break;
            case 1:
            rect.y = shape -> shape[i];
            break;
            case 2:
            rect.w = shape -> shape[i];
            break;
            case 3:
            rect.h = shape -> shape[i];
            break;
        }
        if((i+1)%4 == 0) {
            //printf("color: %d %d %d %d\r\n", r->r, r->g, r->b, r-> a);
            //printf("rect: %d %d %d %d\r\n", rect.x, rect.y, rect.w, rect.h);
            SDL_SetRenderDrawColor(renderer, r->rgba[4*(i/4+1)], r->rgba[4*(i/4+1)+1], r->rgba[4*(i/4+1)+2], r->rgba[4*(i/4+1)+3]);
            SDL_RenderDrawRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, r -> rgba[0], r->rgba[1], r->rgba[2], r->rgba[3]);
        }
    }
}

void renderCircle(SofaShape *shape, SDL_Renderer *renderer, RendererOptions *r) {

}

void renderLine(SofaShape *shape, SDL_Renderer *renderer, RendererOptions *r) {
    for(unsigned int i = 0; i< (shape -> size)/4; i++) {
        SDL_SetRenderDrawColor(renderer, r->rgba[4*(i/4+1)], r->rgba[4*(i/4+1)+1], r->rgba[4*(i/4+1)+2], r->rgba[4*(i/4+1)+3]);
        SDL_RenderDrawLine(renderer, shape -> shape[i], shape -> shape[i+1], shape -> shape[i+2], shape -> shape[i+3]);
        SDL_SetRenderDrawColor(renderer, r -> rgba[0], r->rgba[1], r->rgba[2], r->rgba[3]);
    }
}

#endif