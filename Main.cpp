#include <GLFW/glfw3.h>
#include "Scene.h"
#include "Primitives.h"
#include "Composite.h"

#include <math.h>
#include <iostream>
#include <vector>
#include <memory>

int main(void)
{ 


    
    Scene::get_instance();
    if (!glfwInit())
    {
        return -1;
    }
    glfwMakeContextCurrent(Scene::get_instance());

    
    while (!glfwWindowShouldClose(Scene::get_instance()))
    {
        glClear(GL_COLOR_BUFFER_BIT);
      
      
       

        glfwSwapBuffers(Scene::get_instance());
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
