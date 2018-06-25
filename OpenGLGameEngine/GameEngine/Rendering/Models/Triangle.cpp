#include "Triangle.h"

using namespace GameEngine::Rendering::Models;

Triangle::Triangle() { }

Triangle::~Triangle() { }

void Triangle::Create()
{
	unsigned int vao;
	unsigned int vbo;

	//VAO Handler
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Triangle vertices on stack
	std::vector<Rendering::VertexFormat> vertices;
	vertices.push_back(VertexFormat(glm::vec3(0.25, -0.25, 0.0),
		glm::vec4(1, 0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-0.25, -0.25, 0.0),
		glm::vec4(0, 1, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(0.25, 0.25, 0.0),
		glm::vec4(0, 0, 1, 1)));

	// VBO Handler
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 3, &vertices[0], GL_STATIC_DRAW);

	// Buffer is binded to context
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::colour)));
	glBindVertexArray(0);

	// Assign values
	this->vao = vao;
	this->vbos.push_back(vbo);
}

void Triangle::Update() { }

void Triangle::Draw() 
{ 
	glUseProgram(program);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}