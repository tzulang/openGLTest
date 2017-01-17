#include "CameraMovment.h"
 



CameraMovment::CameraMovment()
{
 
	CameraMovment::firstMouse = true;
}


CameraMovment::~CameraMovment()
{
}

void CameraMovment::bind() {

}

void CameraMovment::KeyCallback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			keys[key] = false;
		}
	}
		
}

void CameraMovment::MouseCallback(GLFWwindow * window, double xPos, double yPos)
{
}
