#include "RenderOptions.hpp"

cow::RenderOptions::RenderOptions() {}

std::vector<uint8_t> cow::RenderOptions::GetForeground() const {
    return RGBAForeground;
}