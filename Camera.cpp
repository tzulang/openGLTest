#include "Camera.h"


#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include "Types.h"
#include "Window.h"
#include <iostream>




Camera::Camera(Vec3 position, Vec3 orientation, Window &window): 
	position(position),
	angles(orientation),
	viewAngle(45.f), 
	window(&window) ,
	forward( absoluteDirections.forward),
	up( absoluteDirections.up)

{
	
	 
	//Tmat rotation = glm::yawPitchRoll( angles[YAW], angles[PITCH], angles[ROLL] );	
	 

	//forward =  rotation * Vec4(forward.x, forward.y, forward.z, 1);
	//up		=  rotation * Vec4(up.x, up.y, up.z, 1);
	//forward =  glm::normalize(forward);
	//up		=  glm::normalize(up);
 
	 
		
	GLint width,height;
	window.getSize(width, height);
	projection = glm::perspective(viewAngle, (GLfloat) width / (GLfloat) height, 0.1f, 100.0f);
}


void Camera::move(Vec3 delta)
{
	delta =glm::yawPitchRoll( angles[YAW], angles[PITCH], angles[ROLL] ) * Vec4(delta,1)	;
	position+=  delta;
 
}


void Camera::changeAngle(Vec3 delta)
{
	angles += delta;		

	
	if ((angles[PITCH]) >=360 )
		angles[PITCH] -= 360;

	if ((angles[PITCH]) <= -360)
		angles[PITCH] += 360;

	if ((angles[YAW]) >= 360)
		angles[YAW] -= 360;

	if ((angles[YAW]) <= -360)
		angles[YAW] += 360;

	if ((angles[ROLL]) >= 360)
		angles[ROLL] -= 360;

	if ((angles[ROLL]) <= -360)
		angles[ROLL] += 360;

	 
 
}

Tmat Camera::getViewMatrix()
{
	
	Tmat rotation = glm::yawPitchRoll( angles[YAW], angles[PITCH], angles[ROLL] );	
	
	
	Vec3 f	=  rotation * Vec4(forward.x, forward.y, forward.z, 1);
	Vec3 u	=  rotation * Vec4(up.x, up.y, up.z, 1);
 

	Tmat view=glm::lookAt(position, position + f, u);
	return view;
}

Tmat Camera::getProjectionMatrix(){
	return projection;
}

 

Camera::~Camera()
{
	std::cout<<"exit"<<std::endl;
}

String Camera::toString(){
	
	return  "Camera("
			"\n position: " +Print::toString(this->position)+ 
			",\n forward: "+ Print::toString(this->forward)+ 
			",\n up"+ Print::toString(this->up)+
			",\n yaw-pitch-roll: "+ Print::toString(this->angles)+
			"       )\n";
			
}