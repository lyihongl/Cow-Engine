#pragma once

#include <SDL2/SDL.h>
#include <glad/glad.h>

#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>

#include "../inc/LoadShaders.hpp"
#include "../inc/linmath.h"

namespace CowGraphics {

struct OpenGLContext;
struct DeleteGLFWwindow;

std::unique_ptr<GLFWwindow, DeleteGLFWwindow> InitGLFW();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

struct DeleteGLFWwindow{
    void operator()(GLFWwindow* ptr){
        glfwDestroyWindow(ptr);
    }
};

std::unique_ptr<GLFWwindow, DeleteGLFWwindow> InitGLFW() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    std::unique_ptr<GLFWwindow, DeleteGLFWwindow> window = std::unique_ptr<GLFWwindow, DeleteGLFWwindow>(glfwCreateWindow(800, 600, "title", nullptr, nullptr));
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        //return -1;
    }
    glfwMakeContextCurrent(window.get());
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window.get(), framebuffer_size_callback);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  
//std::unique_ptr<OpenGLContext> InitContext(uint32_t w, uint32_t h, const char* title, GLFWmonitor* monitor, GLFWwindow* share){
//    return std::make_unique<OpenGLContext>(w, h, title, monitor, share);
//}
//
//struct OpenGLContext {
//    OpenGLContext(uint32_t w, uint32_t h, const char* title, GLFWmonitor* monitor, GLFWwindow* share){
//        window = glfwCreateWindow(w, h, title, monitor, share);
//    }
//    GLFWwindow* window;
//};

}  // namespace CowGraphics