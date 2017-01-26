#pragma once

#include <GL/glew.h>
 
#include <vector>
#include "types.h"
#include "Shader.h"
#include "Camera.h"



struct Vertex {
	
	Vec3 position;
	Vec3 color;
	
	 

};
 


class Model
{

public:
	
	Model(std::vector<Vertex> * vertices, std::vector<GLuint> * indiecs, Shader *shader);
	virtual ~Model();
	void freeResources();
	
	void Model::draw(Tmat &model, Tmat &view,Tmat &projection);
	GLuint	vao,
			vbo,
			ebo;


 

 
	
	std::vector <Vertex> *vertices;
	std::vector <GLuint> *indices;
	Shader * shader;
	
	
	
};

