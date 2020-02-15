#include <SDL2\SDL.h>
#include <iostream>
#include "../inc/Engine.hpp"
#include "../inc/GameData.hpp"

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
 
#include "../inc/linmath.h"
 
#include <stdlib.h>
#include <stdio.h>
#include "../inc/LoadShaders.hpp"
#include <glm/gtc/matrix_transform.hpp>

int main(int argc, char** argv){
    if(!glfwInit()){
        std::cout << "failed to initialize" << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;
    window = glfwCreateWindow(1024, 768, "wow", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    if(window == nullptr){
        std::cout << "yo" << std::endl;
    }
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
    };

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    //system("dir");
    GLuint programID = LoadShaders(".\\Engine_CPP\\shaders\\learn.glsl", ".\\Engine_CPP\\shaders\\learn2.glsl");
    int width = 4;
    int height = 3;
    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float) width/ (float) height, 0.1f, 100.0f);
    glm::mat4 View = glm::lookAt(
        glm::vec3(4, 3, 3),
        glm::vec3(0, 0, 0),
        glm::vec3(0, 1, 0)
    );

    glm::mat4 Model = glm::mat4(1.0f);

    glm::mat4 mvp = Projection*View*Model;


    GLuint MatrixID = glGetUniformLocation(programID, "MVP");

    do{
        glClearColor(0.0f, 0.0f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(programID);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableVertexAttribArray(0);

        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

        glfwSwapBuffers(window);
        glfwPollEvents();
        //std::cout<<"a"<<std::endl;
    } while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
    return 0;
}
 
//int main(int argc, char** argv) {
//    cow::StartGame();
//    return 0;
//}
//
void cow::Tick(GameData& p_gd) {
}

void cow::Render(GameData& p_gd) {
    p_gd.P_getRenderEngine()->RenderShape(p_gd.P_getEntityManager()->Positions, p_gd.P_getEntityManager()->Shapes);
}

void cow::Init(GameData& p_gd){
    cow::ShapeComponent s{0, cow::rect, 20, 20};
    cow::PositionComponent p{0, 100, 100};
    p_gd.P_getEntityManager()->AddShape(s);
    p_gd.P_getEntityManager()->AddPosition(p);
}