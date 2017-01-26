#include "Window.h"
#include "Types.h"
#include <iostream>



#include <GL/glew.h>
#include <GLFW/glfw3.h>

Window::Window(GLuint width, GLuint height, String title, bool fullScreen): 
			width(width), height(height), title (title), fullScreen (fullScreen), isOpen_(false)
{
	// Init GLFW
	glfwInit();

	// Set all the required options for GLFW
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
 
	
}


Window::~Window()
{
	//glfwTerminate();
}

 
int Window::open()
{
	GLFWmonitor* monitor = (!fullScreen) ? nullptr : glfwGetPrimaryMonitor();
	
 	window = glfwCreateWindow(width, height, title.c_str(), monitor, nullptr);

	glfwGetFramebufferSize(window, &width, &height);

	
	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return FAILURE;
	}

	glfwMakeContextCurrent(window);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;

	// Initialize GLEW to setup the OpenGL Function pointers
	if (GLEW_OK != glewInit())
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return FAILURE;
	}
		 
 
	if (nullptr == window)
	{
		std::cout << "Faile	d to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	if (GLEW_OK != glewInit())
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	isOpen_ = true;
	return SUCCESS;
}


int Window::close()
{
	isOpen_ = false;
	glfwTerminate();
	return SUCCESS;
}

void Window::getSize(GLint &width, GLint &height)
{
	width  = this->width;
	height = this->height;
 
}

int  Window::shouldClose()
{	
	return  glfwWindowShouldClose(window);
}

bool Window::isOpen()
{
	return isOpen_;
}

 



 





