#pragma once
#include <GLFW/glfw3.h>
#include "Container.h"
class Controller
{
private:
    static IShape* controlled;
public:
    static void setControlled(IShape* base)
    {
        controlled=base;
    }
	static IShape* getControlled()
    {
        return controlled;
    }
	static void initControlled(IShape* base)
    {
        controlled = base;
        Container::Insert(base);
        Controller::setControlled(controlled);
    }
    static void addChildToControlled(IShape* toAdd)
    {
        controlled->addChild(toAdd);
    }
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        IShape& temp = *controlled;
        if (key == GLFW_KEY_W)
        {    
           temp.moveUp();
        }
        if (key == GLFW_KEY_S)
        {
            temp.moveDown();
        }
        if (key == GLFW_KEY_A)
        {
            temp.moveLeft();
        }
        if (key == GLFW_KEY_D)
        {
            temp.moveRight();
        }
    }
};
IShape* Controller::controlled;