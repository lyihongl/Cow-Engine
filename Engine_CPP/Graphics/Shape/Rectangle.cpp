#include "Rectangle.hpp"

using namespace cow;

Rectangle::Rectangle(){
    singleUnitSize = 4;
}

int Rectangle::GetSingleUnitSize() const {
    return singleUnitSize;
}

void Rectangle::AddElement(double _data...){
    va_list args;
    va_start(args, _data);
    for(std::size_t i {0}; i < singleUnitSize; i++){
        data.push_back(va_arg(args, double));
    }
}

void  Rectangle::Render() const{

}