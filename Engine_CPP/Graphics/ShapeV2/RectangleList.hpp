#ifndef COW_RECTANGLE_HPP
#define COW_RECTANGLE_HPP
#include "Shape.hpp"
template <class T>
class RectangleList : public ShapeList<T> {
   public:
    const std::vector<T> GetData() const;
    void AddElement(T* data);
};
#endif