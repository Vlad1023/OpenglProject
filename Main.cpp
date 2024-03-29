#include <GLFW/glfw3.h>
#include "Scene.h"
#include "Primitives.h"
#include "Composite.h"
#include <iostream>
#include <vector>
#include "Controller.h"
using namespace std;
int main(void)
{
  
    if (!glfwInit())
    {
        return -1;
    }
    glfwMakeContextCurrent(Scene::get_instance());
    glfwSetKeyCallback(Scene::get_instance(), Controller::keyCallback);
    Controller::initControlled(new Composite());
    Controller::displayMenu();
    while (!glfwWindowShouldClose(Scene::get_instance()))
    {
        glClear(GL_COLOR_BUFFER_BIT);;
        Controller::Process();
        Controller::CheckCollision();
        glfwSwapBuffers(Scene::get_instance());
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
