#include "../inc/RenderEngine.hpp"
#include <iostream>
#include <map>
#include "../inc/PositionComponent.hpp"

cow::RenderEngine::RenderEngine(SDL_Window* w, SDL_Renderer* r) {
    this->w = w;
    this->r = r;
}

void cow::RenderEngine::RenderShape(std::map<int, PositionComponent> p, std::map<int, cow::ShapeComponent> s) {
    //render shape to w and r here
    for (auto const& it : s) {
        switch (it.second.GetShape()) {
            case cow::ShapeComponent::rect:
                SDL_Rect rect;
                rect.x = p[it.first].GetX();
                rect.y = p[it.first].GetY();
                rect.w = it.second.GetWidth();
                rect.h = it.second.GetHeight();
                SDL_RenderDrawRect(this->r, &rect);
                break;
            default:
                std::cout << "Error: invalid shape" << std::endl;
                break;
        }
    }
}