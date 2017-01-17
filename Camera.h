#pragma once


#include <GL/glew.h>
#include "Types.h"



class Camera
{
public:
	
	Camera(Vec3 position, Vec3 lookAt, Vec3 up);
	
	void move(Vec3 delta);
	void zoom(GLfloat delta);
	void changeAngle(Vec3 delta);
	
	Tmat getViewMatrix();


	virtual ~Camera();

	
private: 

	Vec3 position;
	Vec3 forward;
	Vec3 up;
	Vec3 angles;
	GLfloat viewAngle;



	
};

