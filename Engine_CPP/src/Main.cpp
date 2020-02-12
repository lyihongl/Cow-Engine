#include <SDL2\SDL.h>
#include <iostream>
#include "../inc/Engine.hpp"
#include "../inc/GameData.hpp"
#include <GLFW/glfw3.h>
#include <GL/gl.h>

int main(int argc, char** argv)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
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