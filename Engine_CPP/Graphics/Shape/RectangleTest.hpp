#include "Rectangle.hpp"
#ifndef COW_RECTANGLETEST_HPP
#define COW_RECTANGLETEST_HPP
//#define AddElement(x...) AddElement(4, x);

namespace cow {
bool TestRectangle() {
    cow::Rectangle r{};
    double element[4] = {1, 2, 3, 4};
    r.AddElement(element);
    //r.AddElement(1.0, 2.0, 3.0, 4.0);
    //r.AddElement(5.0, 6.0, 7.0, 8.0);
    auto a = r.GetData();
    for (std::size_t i{0}; i < a.size(); i++) {
        if (a[i] != i + 1) {
            //test failed
            return false;
        }
    }
    return true;
}
}  // namespace cow

#endif