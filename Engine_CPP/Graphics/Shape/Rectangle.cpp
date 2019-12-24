#include "Rectangle.hpp"
#include <iostream>

using namespace cow;

cow::Rectangle::Rectangle(){
    singleUnitSize = 4;
}

int Rectangle::GetSingleUnitSize() const {
    return singleUnitSize;
}

void Rectangle::AddElement(double _data, ...){
    std::va_list args;
    va_start(args, _data);
    for(std::size_t i {0}; i < singleUnitSize; i++){
        auto t = va_arg(args, double);
        data.push_back(t);
        std::cout << "pushing back" << t <<std::endl;
    }
}

void  Rectangle::Render(SDL_Renderer* r) const{
    
}