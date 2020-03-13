#pragma once
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
class Scene {
public:
	static GLFWwindow* get_instance()
	{
		static GLFWwindow* window;
		if (!window)
		{
			window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Course", NULL, NULL);
		}
		return window;
	}
private:	
    Scene(){}
};