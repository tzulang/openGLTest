#include "TimeKeeper.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>


 

TimeKeeper::TimeKeeper() : lastTik( glfwGetTime() ), framesCounter(0), framesPerSecond(0), secondTracker(lastTik)
{

}


TimeKeeper::~TimeKeeper()
{
}
 

void TimeKeeper::tik(){
	 lastTik= glfwGetTime();
	 framesCounter++;
	 if (lastTik-secondTracker>=1.0f){
		  framesPerSecond=framesCounter;
		  framesCounter=0;
		  secondTracker=lastTik;
	 }
}

 GLfloat TimeKeeper::getDeltaTime(){

	GLfloat currentTik= glfwGetTime();
	GLfloat delta = currentTik-lastTik;
	return delta;
}

 void TimeKeeper::reset(){
	
	 
	 framesPerSecond=framesCounter/60;
	 framesCounter=0;
	 secondTracker=0;
 }

 GLuint TimeKeeper:: getFPS(){
	 return framesPerSecond;
 }
