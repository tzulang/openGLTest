#include "Types.h"


#include <GL/glew.h>
#include <GLFW\glfw3.h>

#include "Shader.h"
#include "Window.h"
#include "Graphics.h"
#include "GameObject.h"
#include "Camera.h"





 
Graphics::Graphics(Window &window, std::vector<GameObject *> &objects): glfwWindow(window.window), objectList(&objects)
{	
	
	window.getSize(width, height);
	// Define the viewport dimensions
	glViewport(0, 0, width, height);
	
}


Graphics::~Graphics()
{
	// Properly de-allocate all resources once they've outlived their purpose
	
}

void Graphics::freeResoucrces()
{
	for (int i = 0; i < objectList->size(); i++) {
		objectList->at(i)->freeResources();
	}
}



void Graphics::draw(Camera &camera)
{
	// Render
	// Clear the colorbuffer
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < objectList->size(); i++) {
			objectList->at(i)->draw(camera);
	}

	// Swap the screen buffers
	glfwSwapBuffers(glfwWindow);

}
