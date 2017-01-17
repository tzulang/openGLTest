#include <iostream>

// GLEW
 
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other includes
#include "Window.h"
#include "Graphics.h"
#include "Shader.h"
#include "Model.h"
#include "GameObject.h"
#include "Camera.h"
#include <vector>

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;



 

// The MAIN function, from here we start the application and run the game loop
int main()
{


 

	GLfloat z = 0;

	//std::vector <Vertex> vertices =	
	//{
	//	// Positions				// Colors
	//	 
	//	{ Vec3(0.5f,  0.5f,	z) ,  Vec3(1.0f, 0.0f, 0.0f) },
	//	{ Vec3(0.5f, -0.5f, z) ,  Vec3(0.0f, 1.0f, 0.0f) },
	//	{ Vec3(-0.5f, -0.5f, z) ,  Vec3(0.0f, 0.0f, 1.0f) },
	//	{ Vec3(-0.5f,  0.5f, z) ,  Vec3(1.0f, 1.0f, 0.0f) }

	//};

	Window myWindow(WIDTH, HEIGHT, "title", false);
	

	if (myWindow.open() == FAILURE) {
		return FAILURE;
	}


	//std::vector <GLuint> indices = { 0,1,3 };

	Shader shader("core.vs", "core.frag");
	 

	 


	// Game loop

		//GLfloat vertices[] =
		//{
		//	 Positions          // Colors           // Texture Coords
		//	0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,    // Top Right
		//	0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,    // Bottom Right
		//	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,  // Bottom Left
		//	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,  // Top Left
		//};


		std::vector <Vertex> vertices =
		{
		// Positions          // Colors           // Texture Coords
			{ Vec3(0.5f,  0.5f, 0.0f)   ,   Vec3(1.0f, 0.0f, 0.0f) },    // Top Right
			{ Vec3(0.5f, -0.5f, 0.0f)   ,   Vec3(0.0f, 1.0f, 0.0f) },    // Bottom Right
			{ Vec3(-0.5f, -0.5f, 0.0f)  ,   Vec3(0.0f, 0.0f, 1.0f) },  // Bottom Left
			{ Vec3(-0.5f,  0.5f, 0.0f)  ,   Vec3(1.0f, 1.0f, 0.0f) },  // Top Left
		};

 

		std::vector <GLuint> indices =
		{  // Note that we start from 0!
			0, 1, 3, // First Triangle
			1, 2, 3  // Second Triangle
		};

		Model model(&vertices, &indices, &shader);
		GameObject object(&model);

		std::vector <GameObject *> objects = { &object };

		Graphics graphics(myWindow, objects);

		Camera camera(Vec3(0, 0, 1), Vec3(0, 0, -1), Vec3(0, 1, 0));
		 
	while (glfwGetKey(myWindow.window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&  ! myWindow.shouldClose()		)
	{
		glfwPollEvents();
		camera.changeAngle(Vec3(.0f/50, 0.0, 1.0/50.f));
		
		graphics.draw(camera);

		 
		
	}

	 
	// Terminate GLFW, clearing any resources allocated by GLFW.
	graphics.freeResoucrces();
	
	myWindow.close();


	return SUCCESS;
}


