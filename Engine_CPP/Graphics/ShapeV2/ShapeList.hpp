#ifndef COW_SHAPELIST_HPP
#define COW_SHAPELIST_HPP
#include <vector>
namespace cow {
template <typename T>
class ShapeList {
   protected:
    std::vector<T> data;
    std::size_t dataSize;

   public:
    enum EShape { Rect,
                  Circle };
    virtual const std::vector<T> GetData() const;
    virtual void AddElement(T* data) = 0;
    virtual std::size_t dataSize() const;
};
}  // namespace cow
#endif