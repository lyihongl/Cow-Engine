#include "Rectangle.hpp"
#include <iostream>

using namespace cow;

cow::Rectangle::Rectangle() {
    singleUnitSize = 4;
}

int Rectangle::GetSingleUnitSize() const {
    return singleUnitSize;
}

void Rectangle::AddElement(double _data[4]) {
    std::va_list args;
    //va_start(args, _data);
    for (std::size_t i{0}; i < singleUnitSize; i++) {
        auto t = va_arg(args, double);
        data.push_back(t);
        std::cout << "pushing back" << t << std::endl;
    }
}

void Rectangle::Render(SDL_Renderer* r) const {
    SDL_Rect rect;
    for (std::size_t i{0}; i < dataSize; i++) {
        switch (i % 4) {
            case 0:
                rect.x = data[i];
                break;
            case 1:
                rect.y = data[i];
                break;
            case 2:
                rect.w = data[i];
                break;
            case 3:
                rect.h = data[i];
                break;
        }
        if ((i + 1) % 4 == 0) {
            SDL_SetRenderDrawColor(
                r,
                ro.GetForeground()[4 * i],
                ro.GetForeground()[4 * (i / 4 + 1)],
                ro.GetForeground()[4 * (i / 4 + 2)],
                ro.GetForeground()[4 * (i / 4 + 3)]);
        }
    }
}

void Rectangle::RemoveElement(int i) {}