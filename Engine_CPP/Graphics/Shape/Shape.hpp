#ifndef COW_SHAPE_HPP
#define COW_SHAPE_HPP
#include <SDL2/SDL.h>
#include <vector>
namespace cow{
    class Shape{

        protected:

        std::vector<double>data;
        int dataSize;
        int singleUnitSize;

        public:

        enum EShape{Rect, Circle};

        const auto GetData(){
            return &data;
        }
        virtual int GetSingleUnitSize() const = 0;
        virtual void AddElement(double _data...) = 0;
        virtual void Render(SDL_Renderer* render) const = 0;
    };
}
#endif