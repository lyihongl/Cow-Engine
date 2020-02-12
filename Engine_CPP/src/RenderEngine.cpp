#include "../inc/RenderEngine.hpp"
#include <iostream>
#include <map>
#include "../inc/PositionComponent.hpp"

cow::RenderEngine::RenderEngine(SDL_Window* w, SDL_Renderer* r) {
    this->w = w;
    this->r = r;
}

void cow::RenderEngine::RenderShape(std::vector<PositionComponent> p, std::vector<cow::ShapeComponent> s) {
    //std::cout << __FILE__ << __LINE__ << std::endl;
    //render shape to w and r here
    for (auto const& it : s) {
        switch (it.GetShape()) {
            case cow::rect:
                SDL_Rect rect;
                rect.x = p[&it-&s[0]].GetX();
                rect.y = p[&it-&s[0]].GetY();
                rect.w = it.GetWidth();
                rect.h = it.GetHeight();
                SDL_SetRenderDrawColor(this->r, 255, 255, 255, 0);
                SDL_RenderDrawRect(this->r, &rect);
                SDL_SetRenderDrawColor(this->r, 0, 0, 0, 0);
                break;
            default:
                std::cout << "Error: invalid shape" << std::endl;
                break;
        }
    }
}