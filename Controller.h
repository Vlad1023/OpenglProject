#pragma once
#include <GLFW/glfw3.h>
#include "Scene.h"
#include "Primitives.h"
#include "Composite.h"
#include <iostream>
#include <vector>
#include <memory>
#include "Controller.h"
class Controller
{
private:
    static Composite controlled;
public:
    static void setCurControlled(Composite& base)
    {
        controlled = base;
    }
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        std::cout << key << std::endl;
        if (key == GLFW_KEY_W)
        {
            controlled.moveUp();
        }
        if (key == GLFW_KEY_S)
        {
            controlled.moveDown();
        }
        if (key == GLFW_KEY_A)
        {
            controlled.moveLeft();
        }
        if (key == GLFW_KEY_D)
        {
            controlled.moveRight();
        }

    }
};
Composite Controller::controlled;