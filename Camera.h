#pragma once


#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Types.h"
#include "Window.h"
#include "Object.h"


class Camera : public Object
{
public:
	
	Camera(Vec3 position, Vec3 orientation, Window &window);
	
	void move(Vec3 delta);
	void zoom(GLfloat delta);
	void changeAngle(Vec3 delta);
	
	Tmat getViewMatrix();
	Tmat getProjectionMatrix();
 

	virtual ~Camera();

	virtual String toString();

private: 

	Vec3 position;

	Vec3 forward;
	Vec3 up;
 
	
	Vec3 angles;
	
	GLfloat viewAngle;
	Window * window;
	Tmat projection;

	
	 

 
};

