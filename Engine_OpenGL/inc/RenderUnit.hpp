#pragma once

#define STB_IMAGE_IMPLEMENTATION

#include <SDL2/SDL.h>
#include <glad/glad.h>

#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <glm/gtx/string_cast.hpp>
#include <memory>

//#include "../inc/Shaders.hpp"
//#include "../inc/linmath.h"
//#include "../inc/stb_image.h"

namespace CowRender {
struct RenderUnit {
    std::unique_ptr<float> VertexData = nullptr;
    std::unique_ptr<float> IndexData = nullptr;
    std::size_t DataSize, Stride;
    unsigned int VBO, VAO, EBO;
};
void SetVertexData(RenderUnit& r, std::unique_ptr<float> data, std::size_t size, std::size_t stride){
    r.VertexData = std::move(data);
    r.DataSize = size;
    r.Stride = stride;
}

void InitVBO(RenderUnit& r){
    if(r.VertexData!=nullptr){
        glGenBuffers(1, &r.VBO);
        glBindBuffer(GL_ARRAY_BUFFER, r.VBO);
        glBufferData(GL_ARRAY_BUFFER, (r.DataSize*sizeof(float)), r.VertexData.get(), GL_STATIC_DRAW);
    }
}

void InitEBO(RenderUnit& r){
    if(r.IndexData != nullptr){
        glGenBuffers(1, &r.EBO);
        glBindBuffer(GL_ARRAY_BUFFER, r.EBO);
        glBufferData(GL_ARRAY_BUFFER, (r.DataSize*sizeof(float)), r.IndexData.get(), GL_STATIC_DRAW);
    }
}

void InitVAO(RenderUnit& r){
    glGenVertexArrays(1, &r.VAO);
    glBindVertexArray(r.VAO);
    glVertexAttribPointer(0, r.Stride, GL_FLOAT, GL_FALSE, r.Stride*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

};  // namespace CowRender