#pragma once

#include <GL\glew.h>

class TimeKeeper
{
public:
	

	TimeKeeper();
	~TimeKeeper();



	void tik();
	void reset();
	GLuint getFPS();
	GLfloat getDeltaTime();

private:

	

	GLfloat lastTik; 
	GLfloat secondTracker; 
	static TimeKeeper timeKeeper;
	GLuint framesCounter;
	GLuint framesPerSecond;


};

