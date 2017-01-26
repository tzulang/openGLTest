#include "CameraMovment.h"
#include "Window.h"
#include "Types.h"
#include "Camera.h"
		

bool CameraMovment::keys[1024];
bool CameraMovment::firstMouse=true;
GLfloat CameraMovment::mouseSensitivity=0.001f;
GLfloat CameraMovment::lastX=0.0;
GLfloat CameraMovment::lastY=0.0;
GLfloat CameraMovment::xOffset=0.0f;
GLfloat CameraMovment::yOffset=0.0f;
		

CameraMovment::CameraMovment(Window &window, Camera &camera): camera(&camera)
{
	
	glfwSetKeyCallback( window.window, KeyCallback );
	glfwSetCursorPosCallback( window.window, MouseCallback);
	 
}


CameraMovment::~CameraMovment()
{
	 
}

void CameraMovment::process() {
	 
	
	
		Direction direction;
		if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP]){
			direction= FORWARD;
			moveCamera(direction);
		}
		if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN]){
			direction= BACKWARD;
			moveCamera(direction);
		}

		if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT]){
			direction= LEFT;
			moveCamera(direction);
		}
		if (keys[GLFW_KEY_D] ||	keys[GLFW_KEY_RIGHT]){
			direction= RIGHT;
			moveCamera(direction);
		}

	 
        
            
	   this->camera->changeAngle( Vec3( xOffset, yOffset,0) );
		xOffset=0;
		yOffset=0;
		 
}

bool CameraMovment::moveCamera(Direction &direction){

	static GLfloat velocity =0.1f;

	if ( direction == FORWARD )
    {
		camera->move(Vec3(0,0,-velocity) );
    }
        
    if ( direction == BACKWARD )
    {
        camera->move(Vec3(0,0,velocity));
    }
        
    if ( direction == LEFT )
    {
        camera->move(Vec3(-velocity,0,0));
    }
        
    if ( direction == RIGHT )
    {
        camera->move(Vec3(velocity,0,0));
    }
	return true;
}

void CameraMovment::KeyCallback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	Direction direction;
	if (key == keys[GLFW_KEY_ESCAPE] && action == GLFW_PRESS)
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

	//std::cout<< "x:" << xPos <<", y:" << yPos << ", deltax:" << xOffset<<", deltaY: "<< yOffset<<std::endl;

	if( firstMouse )
		{
			lastX = xPos;
			lastY = yPos;
			firstMouse = false;
		}
		

	xOffset = xPos - lastX;
	yOffset = lastY - yPos;  // Reversed since y-coordinates go from bottom to left
	 
	//std::cout<< "x:" << xPos <<", y:" << yPos << ", deltax:" << xOffset<<", deltaY: "<< yOffset<<std::endl;

	xOffset *= mouseSensitivity;
    yOffset *= mouseSensitivity;




	lastX = xPos;
	lastY = yPos;
    
		
}


 