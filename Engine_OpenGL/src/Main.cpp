#include <SDL2\SDL.h>
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



class Position: public Cow::Component{
    public:
    Position(){}
};

int main(int argc, char* args[]) {
    Cow::TypeMap<uint32_t> T;
    //T.put<int>(true);
    //T.put<double>(true);
    Cow::ComponentManager c;
    c.Register<Position>();
    std::cout<<"test: "<<(c.TMap.find<Position>()->second)<<std::endl;
    //Cow::ArchetypeFactory(4, 1, 2, 3, 4);
    return 0;
}