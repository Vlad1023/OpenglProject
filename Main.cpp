#include <GLFW/glfw3.h>
#include "Scene.h"
#include "Primitives.h"
#include "Composite.h"
#include <math.h>
#include <iostream>
#include <vector>
#include <memory>
using namespace std;
int main(void)
{ 
    Composite* com = new Composite();
    com->addChild(new Circle());
    if (!glfwInit())
    {
        return -1;
    }
    glfwMakeContextCurrent(Scene::get_instance());    
    while (!glfwWindowShouldClose(Scene::get_instance()))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        com->IDraw();
        glfwSwapBuffers(Scene::get_instance());
        glfwPollEvents();
    }
    glfwTerminate();
    delete com;
    return 0;
}
