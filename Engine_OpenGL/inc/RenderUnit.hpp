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
namespace RenderUnit {

struct RenderUnit {
    float* VertexData;
    unsigned int* IndexData;
    std::size_t VertexDataSize, IndexDataSize, Stride;
    unsigned int VBO, VAO, EBO;
};
void SetVertexData(RenderUnit& r, float* data, std::size_t size, std::size_t stride) {
    r.VertexData = data;
    r.VertexDataSize = size;
    r.Stride = stride;
}

void SetIndexData(RenderUnit& r, unsigned int * data, std::size_t size) {
    r.IndexData = data;
    r.IndexDataSize = size;
}

void InitVBO(RenderUnit& r) {
    if (r.VertexData != nullptr) {
        glGenBuffers(1, &r.VBO);
        glBindBuffer(GL_ARRAY_BUFFER, r.VBO);
        glBufferData(GL_ARRAY_BUFFER, (r.VertexDataSize * sizeof(float)), r.VertexData, GL_STATIC_DRAW);
        std::cout<<"DEBUG vbo size"<<r.VertexDataSize * sizeof(float) << std::endl;
    }
}

void InitEBO(RenderUnit& r) {
    if (r.IndexData != nullptr) {
        glGenBuffers(1, &r.EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, r.EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, (r.IndexDataSize * sizeof(unsigned int)), r.IndexData, GL_STATIC_DRAW);
        std::cout<<"DEBUG ebo size"<<r.IndexDataSize* sizeof(unsigned int) << std::endl;
    }
}

void InitVAO(RenderUnit& r) {
    glGenVertexArrays(1, &r.VAO);
    glBindVertexArray(r.VAO);
    glVertexAttribPointer(0, r.Stride, GL_FLOAT, GL_FALSE, r.Stride * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

};  // namespace RenderUnit
};  // namespace CowRender