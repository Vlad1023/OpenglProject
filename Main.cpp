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
    Controller::addChildToControlled(new Rectangle());
    Controller::addChildToControlled(new Circle());
    Container::Insert(new Circle());
    while (!glfwWindowShouldClose(Scene::get_instance()))
    {
        glClear(GL_COLOR_BUFFER_BIT);;
        Container::manEvs();
        glfwSwapBuffers(Scene::get_instance());
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
