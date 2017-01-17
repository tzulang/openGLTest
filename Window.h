#pragma once

#include <string>
#include "Types.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

 class Window  
{

public:
	
	friend class Graphics;


	Window(GLuint width, GLuint height, String title, bool fullScreen);
	~Window();
	
	int open();

	
	int close();
	
	void getSize(GLint &width, GLint &height);
	int shouldClose();
	bool isOpen();
	
	GLFWwindow *window;
private :
	
	bool fullScreen;
	GLint width, height;
	String title;
	bool isOpen_;
	
		


};

