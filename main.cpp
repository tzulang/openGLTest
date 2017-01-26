#include <iostream>

// GLEW
 
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other includes
#include "Window.h"
#include <windows.h>
#include "Graphics.h"
#include "Shader.h"
#include "Model.h"
#include "GameObject.h"
#include "Camera.h"
#include <vector>
#include "UserInput.h"
#include "CameraMovment.h" 
#include "TimeKeeper.h"

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;



void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



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


		Vertex  v[] ={
			{Vec3(0.5f,  0.5f, 0.0f)   ,   Vec3(1.0f, 0.0f, 0.0f)} ,
			{Vec3(0.5f, -0.5f, 0.0f)   ,   Vec3(0.0f, 1.0f, 0.0f)},
			{Vec3(-0.5f, -0.5f, 0.0f)  ,   Vec3(0.0f, 0.0f, 1.0f)},
			{Vec3(-0.5f,  0.5f, 0.0f)  ,   Vec3(1.0f, 1.0f, 0.0f)}
		};
		
 
		std::vector <Vertex> vertices(0);
		
		for (int i= 0 ; i<4; i++){
			vertices.push_back(v[i]);
		}
		
 

		std::vector <GLuint> indices (0);
		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(3);
		indices.push_back(1);
		indices.push_back(2);
		indices.push_back(3);
		
		Model model(&vertices, &indices, &shader);
		GameObject object(&model, Vec3(0, 0, 0), Vec3(0, 0, 0));

		std::vector <GameObject *> objects(0);
		objects.push_back ( &object );

		Camera camera(Vec3(0, 0, 2), Vec3(0, 0, 0), myWindow);
		Graphics graphics(myWindow, objects);

		


	CameraMovment cameraMovment= CameraMovment(myWindow,camera);
		 
	 

	TimeKeeper  timer;

	timer.reset();

	while (!myWindow.shouldClose() )
	{
		GLfloat delta= timer.getDeltaTime();
		if (delta >= 1.0f/60.0f){
			timer.tik();
		/*	gotoxy(0,0);
			std::cout<<delta<<"\n" << timer.getFPS()<<std::endl;*/
			glfwPollEvents();
			cameraMovment.process();
		 
			graphics.draw(camera);
		} 
		
		
		

		

		
	}

	

	// Terminate GLFW, clearing any resources allocated by GLFW.
	graphics.freeResoucrces();
	
	myWindow.close();


	return SUCCESS;
}


