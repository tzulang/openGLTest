#pragma once



#include <GL/glew.h>
#include <GLFW\glfw3.h>

#include "UserInput.h"
#include "Camera.h"
#include "Types.h"


class CameraMovment :
	public UserInput
{
public:
	CameraMovment(Window &window, Camera &camera);

	virtual ~CameraMovment();

	virtual void process() override;


	private :

		Camera * camera;

		bool moveCamera(Direction &direction);


		static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
		static void MouseCallback(GLFWwindow *window, double xPos, double yPos);


		 
		static GLfloat lastX, lastY ,xOffset ,yOffset, mouseSensitivity; 
		static bool keys[];
		static bool firstMouse ;


	 
		
		
		
		
};

