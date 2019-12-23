#include <vector>
#ifndef COW_RENDEROPTIONS_HPP
#define COW_RENDEROPTIONS_HPP
namespace cow{
    class RenderOptions{
        public:
        RenderOptions();
        private:
        std::vector<int> RGBARect;
        int RGBABackground[4];
    };
}
#endif