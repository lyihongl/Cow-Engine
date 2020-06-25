#include <SDL2/SDL.h>
#include <glad/glad.h>

#include <atomic>
#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "../inc/Storage.hpp"
#include "../inc/linmath.h"
#include "../inc/DefaultComponents.hpp"
#include "../inc/RenderPipeline.hpp"
#include "../inc/Shaders.hpp"
#include "../inc/RenderUnit.hpp"
#include "../inc/RenderAPI.hpp"
#include "../inc/Entity.hpp"




int main(int argc, char* args[]) {
    std::cout<<"hello world"<<std::endl;
    //Cow::TypeMap<uint32_t> T;
    Cow::ComponentManager c;
    Cow::InitDefault2D(c);
    std::cout<<"test: "<<(c.TMap.find<Cow::Physics2D>()->second)<<std::endl;
    //auto window = std::move(CowGraphics::InitGLFW());
    std::cout<<"test"<<std::endl;
    auto window = CowRender::InitGLFW();

    //auto positionID = c.Register<Cow::Position2D>();
    //Cow::InitDefault2D();
    auto test = Cow::NewEntity();
    Cow::Position2D position{0, 0};
    c.MapComponent<decltype(position)>(test->ID, position);
    //float teset[] = {1.0f, 1.0f, 1.0f};
    //std::cout<<"size"<<sizeof(teset)<<std::endl; 
    CowRender::Shader s{"./Engine_OpenGL/shaders/quadVertexShader.glsl", "./Engine_OpenGL/shaders/quadFragShader.glsl"};

    //CowGraphics::StartRender(window.get());
    CowRender::Draw(window.get(), s);

    std::cout<<"crash"<<std::endl;
    glfwTerminate();
    return 0;
}