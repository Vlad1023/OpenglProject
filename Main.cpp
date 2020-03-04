#include <GLFW/glfw3.h>
#include "Scene.h"
#include "Primitives.h"
#include "Composite.h"
#include <iostream>
#include <vector>
#include <memory>
#include "Controller.h"
using namespace std;
int main(void)
{ 
    unique_ptr<Composite> com(new Composite);
    com->addChild(new Rectangle());
    if (!glfwInit())
    {
        return -1;
    }
    glfwMakeContextCurrent(Scene::get_instance());
    glfwSetKeyCallback(Scene::get_instance(), Controller::keyCallback);
    Controller::setCurControlled(*com);
    while (!glfwWindowShouldClose(Scene::get_instance()))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        com->IDraw();
        glfwSwapBuffers(Scene::get_instance());
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
