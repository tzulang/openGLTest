#pragma once



#include <GL/glew.h>
#include <GLFW\glfw3.h>

#include "UserInput.h"
#include "Camera.h"

class CameraMovment :
	public UserInput
{
public:
	CameraMovment();

	virtual ~CameraMovment();

	virtual void bind() override;


	private :

		static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
		static void MouseCallback(GLFWwindow *window, double xPos, double yPos);


		static double lastX, lastY;
		static bool keys[1024],
			   firstMouse ;
};

