#include "Model.h"
#include <vector>
#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 



#include "Types.h"
#include "Shader.h"


enum VBO_ATTRIBUTE_TYPE { POISTION = 0, COLOR, VBO_ATTRIB_NUMBER };

struct VBO_ATTRIBUTE {

	VBO_ATTRIBUTE_TYPE attribute;
	int size;
	GLvoid * offset;

};
	
const VBO_ATTRIBUTE  vbo_attributes[VBO_ATTRIB_NUMBER] = {
	//attribute			//size	//offset
	{POISTION,	3,		(GLvoid *)(0 * sizeof(GLfloat)) },
	{COLOR,		3,		(GLvoid *)(3 * sizeof(GLfloat)) }
};

const int TOTAL_DATA_SIZE = 6 * sizeof(GLfloat);

 

Model::Model(std::vector<Vertex>* vertices, std::vector<GLuint>* indices, Shader *shader ): vertices(vertices), indices(indices), shader(shader)
{	

	glGenVertexArrays(1, &vao);
	glGenBuffers(1 ,&vbo);
	glGenBuffers(1, &ebo);
	
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, this->vertices->size() * sizeof(Vertex) , &(this->vertices->front()), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices->size() * sizeof(GLuint), &(this->indices->front()) , GL_STATIC_DRAW);

	// iterate attributes
	//for (int i = POISTION; i < VBO_ATTRIB_NUMBER; i++) {
	//	glVertexAttribPointer(i, vbo_attributes[i].size , GL_FLOAT, GL_FALSE, TOTAL_DATA_SIZE, vbo_attributes[i].offset);
	//	glEnableVertexAttribArray(i);
	//}
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)0);
	// Vertex Normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)( 3* sizeof(GLfloat)) );
	 

	glBindVertexArray(0); // Unbind VAO
	
}

	
 
 

Model::~Model()
{
}

void Model::freeResources()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
}

 
 




void Model::draw(Tmat &view, Tmat &projection)
{

	Tmat rot, trans, model;
	
	rot = Tmat();//glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 50.0f), Vec3(1.0f, 0.0f, 0.0f)); // use with perspective projection
	trans = glm::translate(Tmat(1.0f), Vec3(0, 0, -2.0f));
	model = trans * rot;
 

	// Draw the triangle
	shader->Use();



	
	GLint modLoc = glGetUniformLocation(shader->Program, "model");
	GLint viewLoc = glGetUniformLocation(shader->Program, "view");
	GLint projLoc = glGetUniformLocation(shader->Program, "projection");


	glUniformMatrix4fv(modLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, this->indices->size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

