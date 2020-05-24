#include <SDL2/SDL.h>
#include <glad/glad.h>

#include <atomic>
#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "../inc/LoadShaders.hpp"
#include "../inc/Storage.hpp"
#include "../inc/linmath.h"
#include "../inc/DefaultComponents.hpp"
#include "../inc/RenderPipeline.hpp"




int main(int argc, char* args[]) {
    std::cout<<"hello world"<<std::endl;
    //Cow::TypeMap<uint32_t> T;
    //Cow::ComponentManager c;
    //Cow::InitDefault2D(c);
    //std::cout<<"test: "<<(c.TMap.find<Cow::Physics2D>()->second)<<std::endl;
    //auto window = std::move(CowGraphics::InitGLFW());
    return 0;
}