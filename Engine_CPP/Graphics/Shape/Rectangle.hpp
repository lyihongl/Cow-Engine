#ifndef COW_RECTANGLE_HPP
#define COW_RECTANGLE_HPP
#include <cstdarg>
#include "Shape.hpp"
namespace cow {
class Rectangle : public Shape {
   private:
   public:
    Rectangle();
    /**
         * AddElements will only add a single argument for rectangle.
         */
    int GetSingleUnitSize() const;
    void AddElement(double _data[4]);
    void RemoveElement(int i);
    void Render(SDL_Renderer* r) const;
};
}  // namespace cow
#endif