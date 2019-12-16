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
typedef struct SofAShape{
    double* P_shape;
    unsigned int Size;
    enum ShapeFlags F;
} SofAShape;

/**
 * rgba: [0] -> r, [1] -> g, [2] -> b, [3] -> a
 */
typedef struct RendererOptions{
    uint8_t *rgba;
} RendererOptions;

/**
 *  RenderShape accepts a pointer to Struct of Arrays Shape (SofAShape) a pointer to an SDL_Window, a pointer to a SDL_Renderer
 *  and a pointer to a RendererOptions
 *  
 *  P_shape should contain all the information about the shape, depending on the flag, a different shape will be rendered
 */
void RenderShape(SofAShape* P_shape, SDL_Window* p_window, SDL_Renderer* p_renderer, RendererOptions *p_r){
    switch(P_shape -> F){
        case 0:
        renderRect(P_shape, p_renderer, p_r);
        break;
        case 1:
        renderCircle(P_shape, p_renderer, p_r);
        break;
        case 2:
        renderLine(P_shape, p_renderer, p_r);
        default:
        return;
    }
}

void renderRect(SofAShape* P_shape, SDL_Renderer *renderer, RendererOptions *r) {
    SDL_Rect rect;
    for(unsigned int i = 0; i < P_shape -> Size; i++) {
        switch(i%4){
            case 0:
            rect.x = P_shape -> P_shape[i];
            break;
            case 1:
            rect.y = P_shape -> P_shape[i];
            break;
            case 2:
            rect.w = P_shape -> P_shape[i];
            break;
            case 3:
            rect.h = P_shape -> P_shape[i];
            break;
        }
        if((i+1)%4 == 0) {
            SDL_SetRenderDrawColor(renderer, r->rgba[4*(i/4+1)], r->rgba[4*(i/4+1)+1], r->rgba[4*(i/4+1)+2], r->rgba[4*(i/4+1)+3]);
            SDL_RenderDrawRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, r -> rgba[0], r->rgba[1], r->rgba[2], r->rgba[3]);
        }
    }
}

void renderCircle(SofAShape *shape, SDL_Renderer *renderer, RendererOptions *r) {

}

/**
 * Renders line
*/
void renderLine(SofAShape *shape, SDL_Renderer *renderer, RendererOptions *r) {
    for(unsigned int i = 0; i< (shape -> Size)/4; i++) {
        SDL_SetRenderDrawColor(renderer, r->rgba[4*(i/4+1)], r->rgba[4*(i/4+1)+1], r->rgba[4*(i/4+1)+2], r->rgba[4*(i/4+1)+3]);
        SDL_RenderDrawLine(renderer, shape -> P_shape[i], shape -> P_shape[i+1], shape -> P_shape[i+2], shape -> P_shape[i+3]);
        SDL_SetRenderDrawColor(renderer, r -> rgba[0], r->rgba[1], r->rgba[2], r->rgba[3]);
    }
}

#endif