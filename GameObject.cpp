#include "GameObject.h"
#include <GL/glew.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 

#include "Model.h"
#include "types.h"
#include "Shader.h"
#include "Window.h"


 

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

 
void GameObject::draw(Camera &camera)
{
	
	Tmat modelMAtrix= glm::translate(Tmat(1.0), position);

	model->draw(modelMAtrix , camera.getViewMatrix(), camera.getProjectionMatrix() );
}
 


