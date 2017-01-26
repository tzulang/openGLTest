#pragma once

#include <GL/glew.h>
#include <glm\glm.hpp>
#include "types.h"
#include "Model.h"
#include "Shader.h"
#include "Camera.h"
#include "Window.h"

class GameObject
{

public:
	GameObject(Model * model);
	GameObject(Model * model, Vec3 position, Vec3 rotation);
	
	virtual ~GameObject();
	
	void freeResources();

	void setPosition(Vec3 &newPostition);
	void setRotation(Vec3 &newRotation);
	

	void move(Vec3 delta);
	void rotate(Vec3 degrees);
	void draw(Camera &camera);
	









private:

	Vec3 position;
	Vec3 rotation;
 
	 

	Model * model;
	

};

