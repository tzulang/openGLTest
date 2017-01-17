#pragma once

#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include "Window.h"
#include "Shader.h"
#include "GameObject.h"
#include "Vector"
#include "Camera.h"

class Graphics
{

public:

	 

	Graphics(Window & window, std::vector<GameObject *> &objects);
	
	virtual ~Graphics();
	void freeResoucrces();
	void draw(Camera &camera);


protected:

	GLFWwindow *glfwWindow;
	GLint width, height;

	std::vector<GameObject *> *objectList;


};

