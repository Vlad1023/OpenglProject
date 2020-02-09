#include <GLFW/glfw3.h>
#include "Scene.h"
#include <math.h>
#include <iostream>
#include <vector>
#include "Primitives.h"


int main(void)
{ 
    Circle cir;
    if (!glfwInit())
    {
        return -1;
    }
    glfwMakeContextCurrent(Scene::get_instance());
    float vertices[] =
    {
        0, 0.5, 0.0, // top corner
        -0.5, -0.5, 0.0, // bottom left corner
        0.5, -0.5, 0.0 // bottom right corner
    };
    while (!glfwWindowShouldClose(Scene::get_instance()))
    {
        glClear(GL_COLOR_BUFFER_BIT);
       

        glfwSwapBuffers(Scene::get_instance());

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
