#include <vector>
#ifndef COW_RENDEROPTIONS_HPP
#define COW_RENDEROPTIONS_HPP
namespace cow{
    class RenderOptions{
        public:
        RenderOptions();
        void AddForeground(int r, int g, int b, int a);
        void SetBackground(int r, int g, int b, int a);
        auto GetForeground();
        int& GetBackground();
        private:
        std::vector<int> RGBAForeground;
        int RGBABackground[4];
    };
}
#endif