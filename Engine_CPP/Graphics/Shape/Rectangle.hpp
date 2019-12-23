#ifndef COW_RECTANGLE_HPP
#define COW_RECTANGLE_HPP
#include "Shape.hpp"
#include <cstdarg>
namespace cow{
    class Rectangle : public Shape{
        public:
        Rectangle();
        /**
         * AddElements will only add a single argument for rectangle.
         */
        int GetSingleUnitSize() const;
        void AddElement(double _data...);
        void Render() const;
    };
}
#endif