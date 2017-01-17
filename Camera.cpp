#include "Camera.h"


#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Types.h"



Camera::Camera(Vec3 position, Vec3 lookAt, Vec3 up): position(position),up(up), viewAngle(45.f), forward(glm::normalize(lookAt))
{
}

void Camera::move(Vec3 delta)
{
	position += delta;
}


void Camera::changeAngle(Vec3 delta)
{
	angles += delta;		


	
	if (abs(angles[PITCH]) >=360 )
		angles[PITCH] -= 360;

	if (abs(angles[PITCH]) <= -360)
		angles[PITCH] += 360;

	if (abs(angles[YAW]) >= 360)
		angles[YAW] -= 360;

	if (abs(angles[YAW]) <= -360)
		angles[YAW] += 360;

	if (abs(angles[ROLL]) >= 360)
		angles[ROLL] -= 360;

	if (abs(angles[ROLL]) <= -360)
		angles[ROLL] += 360;
 
}

Tmat Camera::getViewMatrix()
{
	
	
	Tmat rotation(1.0F);

	rotation = glm::rotate(rotation, glm::radians(angles[YAW]), Vec3(0.0f, 1.0f, 0.0f));
	rotation = glm::rotate(rotation, glm::radians( angles[PITCH]) , Vec3(1.0f, 0.0f, 0.0f));
	rotation = glm::rotate(rotation, glm::radians(angles[ROLL]), Vec3(0.0f, 0.0f, 1.0f));
	
	Vec3 front = glm::normalize(rotation * Vec4(forward.x, forward.y, forward.z, 1));
	Vec3 top =  glm::normalize(rotation * Vec4(up.x, up.y, up.z, 1));

	return glm::lookAt(position, position + front, top);
}


Camera::~Camera()
{
}
