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
    return window;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    std::cout << "window resized to (w, h): "
              << "( " << width << ", " << height << ") " << std::endl;
}

void StartRender(GLFWwindow* window) {
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f};

    const char* vertexShaderSource =
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    const char* fragmentShaderSource =
        " #version 330 core \n"
        "out vec4 FragColor;\n"
        "void main() { FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); }";

    unsigned int vertexShaderId;
    vertexShaderId = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShaderId, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShaderId);

    
	int InfoLogLength;
	GLint Result = GL_FALSE;
	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(vertexShaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(vertexShaderId, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}

    unsigned int fragmentShaderId;

    fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderId, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShaderId);

    unsigned int VBO;
    glGenBuffers(1, &VBO);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int programId, program2;
    //unsigned int programId = LoadShaders(
    //    "./Engine_OpenGL/shaders/vertexShader.glsl",
    //    "./Engine_OpenGL/shader/fragmentShader.glsl");
    programId = glCreateProgram();
    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);
    glLinkProgram(programId);

    program2 = LoadShaders( "./Engine_OpenGL/shaders/vertexShader.glsl", "./Engine_OpenGL/shaders/fragmentShader.glsl");

    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glUseProgram(program2);
    glBindVertexArray(VAO);

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
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