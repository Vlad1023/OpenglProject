#pragma once
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 1500
class Scene {
public:
	static GLFWwindow* get_instance() { static GLFWwindow* window; if (!window) { window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Course", NULL, NULL); } return window; }
private:	
    Scene(){}
};