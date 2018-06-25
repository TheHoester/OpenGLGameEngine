#include "Quad.h"

using namespace GameEngine::Rendering::Models;

Quad::Quad() { }

Quad::~Quad() { }

void Quad::Create()
{
	GLuint vao;
	GLuint vbo;

	//VAO Handler
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Triangle vertices on stack
	std::vector<Rendering::VertexFormat> vertices;
	vertices.push_back(VertexFormat(glm::vec3(-0.25, 0.5, 0.0),
		glm::vec4(1, 0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-0.25, 0.75, 0.0),
		glm::vec4(0, 0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(0.25, 0.5, 0.0),
		glm::vec4(0, 1, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(0.25, 0.75, 0.0),
		glm::vec4(0, 0, 1, 1)));

	// VBO Handler
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 4, &vertices[0], GL_STATIC_DRAW);

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

void Quad::Update() { }

void Quad::Draw()
{
	glUseProgram(program);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}