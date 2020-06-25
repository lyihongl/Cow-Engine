#pragma once

#define STB_IMAGE_IMPLEMENTATION

#include <SDL2/SDL.h>
#include <glad/glad.h>

#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <memory>

#include "RenderUnit.hpp"
#include "linmath.h"
#include "shaders.hpp"
#include "stb_image.h"

namespace CowRender {

struct OpenGLContext;
struct DeleteGLFWwindow;
/*
Performs default initialization of glfw, returns an std::unique_ptr<GLFW
*/
std::unique_ptr<GLFWwindow, DeleteGLFWwindow> InitGLFW();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

struct DeleteGLFWwindow {
    void operator()(GLFWwindow* ptr) {
        glfwDestroyWindow(ptr);
    }
};

std::unique_ptr<GLFWwindow, DeleteGLFWwindow> InitGLFW() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    std::cout << "a" << std::endl;
    std::unique_ptr<GLFWwindow, DeleteGLFWwindow> window = std::unique_ptr<GLFWwindow, DeleteGLFWwindow>(glfwCreateWindow(800, 600, "title", nullptr, nullptr));
    //GLFWwindow* window = glfwCreateWindow(800, 600, "title", nullptr, nullptr);
    std::cout << "a" << std::endl;
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        //return -1;
    }
    std::cout << "a" << std::endl;
    glfwMakeContextCurrent(window.get());
    //glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    std::cout << "a" << std::endl;
    glViewport(0, 0, 800, 600);
    std::cout << "a" << std::endl;
    glfwSetFramebufferSizeCallback(window.get(), framebuffer_size_callback);
    //glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    std::cout << "a" << std::endl;
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    return window;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    if(height&1){
        height-=1;
    }
    glViewport(0, 0, width, height);
    std::cout << "window resized to (w, h): "
              << "( " << width << ", " << height << ") " << std::endl;
}
void DrawQuad2(RenderUnit::RenderUnit& r) {

    glm::vec4 translations[100];
    int index = 0;
    float offset = 0.1f;
    for (int y = -10; y < 10; y += 2) {
        for (int x = -10; x < 10; x += 2) {
            glm::vec4 translation;
            translation.x = (float)x / 10.0f + offset;
            translation.y = (float)y / 10.0f + offset;
            if(index%3 == 0){
                translation.z = 0;
                translation.w = 31;
            } else if(index%3==1){
                translation.z = 0;
                translation.w = 31;
            } else {
                translation.z = 0;
                translation.w = 31;
            }
            //translation.x =
            translations[index++] = translation;
        }
    }

    // store instance data in an array buffer
    // --------------------------------------
    unsigned int instanceVBO;
    glGenBuffers(1, &instanceVBO);
    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec4) * 100, &translations[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);



    float vertices[] = {
        0.1f, 0.1f, 0.0f, 1.0f, 1.0f,    // top right
        0.1f, -0.1f, 0.0f, 1.0f, 0.0f,   // bottom right
        -0.1f, 0.1f, 0.0f, 0.0f, 1.0f,    // top left

        -0.1f, -0.1f, 0.0f, 0.0f, 0.0f,  // bottom left
        -0.1f, 0.1f, 0.0f, 0.0f, 1.0f,    // top left
        0.1f, -0.1f, 0.0f, 1.0f, 0.0f,   // bottom right
    };

    //unsigned int indices[] = {
    //    // note that we start from 0!
    //    0, 1, 3,  // first triangle
    //    1, 2, 3   // second triangle
    //};
    std::cout << "DEBUG" << __LINE__ << std::endl;
    RenderUnit::RenderUnit ru;
    RenderUnit::SetVertexData(ru, vertices, 30, 5);
    //RenderUnit::SetIndexData(ru, indices, 6);

    glGenVertexArrays(1, &ru.VAO);
    glBindVertexArray(ru.VAO);

    //RenderUnit::InitVAO(ru);
    RenderUnit::InitVBO(ru);
    //RenderUnit::InitEBO(ru);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));

    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glVertexAttribDivisor(2, 1);
    //    glEnableVertexAttribArray(1);
    r = ru;
}

void Draw(GLFWwindow* window, Shader& shader) {
    std::cout << "Draw" << std::endl;

    //glUniform1i(glGetUniformLocation(shader.ID, "ourTexture1"), 0);
    // or set it via the texture class

    //DrawQuad2();
    RenderUnit::RenderUnit r;
    std::cout << __LINE__ << std::endl;
    DrawQuad2(r);
    //RenderUnit::RenderUnit r2;

    unsigned int texture1;
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);

    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, max_mipmap_level);

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("./Engine_OpenGL/assets/testsheet.png", &width, &height, &nrChannels, 0);

    if (data) {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        std::cout << "test1" << std::endl;
        //glPixelStorei(GL_UNPACK_ROW_LENGTH, width);
        //glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
        //glPixelStorei(GL_UNPACK_SKIP_ROWS, 16);
        std::cout << "width" << width << "height:" << height << std::endl;
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        //glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
        //glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
        //glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
        glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
        std::cout << "test2" << std::endl;

        glGenerateMipmap(GL_TEXTURE_2D);
        //glTexSubImage2D (GL_TEXTURE_2D, 0, 0, 0, 16, 16, GL_RGBA, GL_UNSIGNED_BYTE, data);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    //glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    stbi_image_free(data);
    std::cout << __LINE__ << std::endl;
    //shader.Set<int>("ourTexture2", 1);
    std::cout << "DEBUG" << __LINE__ << std::endl;
    while (!glfwWindowShouldClose(window)) {
        shader.Use();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        GLint m_viewport[4];
        glGetIntegerv(GL_VIEWPORT, m_viewport);
        std::cout << "viewport: " << m_viewport[0] << " " << m_viewport[1] << " " << m_viewport[2] << " " << m_viewport[3] << std::endl;
        unsigned int spriteLoc = glGetUniformLocation(shader.ID, "spriteLoc");

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::scale(model, glm::vec3((float)(m_viewport[3]) / (float)(m_viewport[2]), 1.0f, 1.0f));
        int modelLoc = glGetUniformLocation(shader.ID, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glm::mat4 view = glm::mat4(1.0f);

        int viewLoc = glGetUniformLocation(shader.ID, "view");

        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

        glBindVertexArray(r.VAO);  // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArraysInstanced(GL_TRIANGLES, 0, 6, 100);
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

}  // namespace CowRender