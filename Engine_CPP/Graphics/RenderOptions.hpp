#include <vector>
#ifndef COW_RENDEROPTIONS_HPP
#define COW_RENDEROPTIONS_HPP
#include <cstdint>
namespace cow {
class RenderOptions {
   public:
    RenderOptions();
    void AddForeground(int r, int g, int b, int a);
    /**
         * Pops the foreground off the end of the list
         */
    void RemoveForeground();
    void SetBackground(int r, int g, int b, int a);
    std::vector<uint8_t> GetForeground() const;
    int& GetBackground() const;
    auto GetColorFromVector(int index, char val);

   private:
    std::vector<uint8_t> RGBAForeground;
    uint8_t RGBABackground[4];
};
}  // namespace cow
#endif