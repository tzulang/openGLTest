#include "GameObject.h"
#include <GL/glew.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 

#include "Model.h"
#include "types.h"
#include "Shader.h"


 

GameObject::GameObject(Model * model): model(model), position(Vec3(0, 0, 0)), rotation(Vec3(0, 0, 0))
{}

GameObject::GameObject(Model * model, Vec3 position, Vec3 rotation):
	model(model), position(position) , rotation(rotation)
{}


GameObject::~GameObject()
{}

void GameObject::freeResources()
{
	model->freeResources();
}



void GameObject::setPosition(Vec3 & newPostition)
{
	position = newPostition;
}

void GameObject::setRotation(Vec3 & newRotation)
{
	rotation = newRotation;
}


void GameObject::move(Vec3 delta)
{
	position += delta;
}

void GameObject::rotate(Vec3 degrees)
{
	rotation += degrees;
}

static glm::mat4 projection = glm::perspective(45.0f, (GLfloat)800 / (GLfloat)600, 0.1f, 100.0f);

void GameObject::draw(Camera &camera)
{
	
	model->draw(camera.getViewMatrix(), projection);
}
 


