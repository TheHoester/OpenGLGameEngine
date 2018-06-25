#include "Cube.h"

using namespace GameEngine::Rendering;
using namespace GameEngine::Rendering::Models;

#define PI 3.14159265

Cube::Cube() { }

Cube::~Cube() { }

void Cube::Create()
{
	GLuint vao;
	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;
	//vertices for the front face of the cube
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0),
		glm::vec4(0.0, 0.0, 1.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, 1.0),
		glm::vec4(1.0, 0.0, 1.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0),
		glm::vec4(1.0, 1.0, 1.0, 1.0)));

	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0),
		glm::vec4(0.0, 1.0, 1.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0),
		glm::vec4(1.0, 1.0, 1.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0),
		glm::vec4(0.0, 0.0, 1.0, 1.0)));

	//vertices for the right face of the cube
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0),
		glm::vec4(1.0, 1.0, 1.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0),
		glm::vec4(1.0, 1.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0),
		glm::vec4(1.0, 0.0, 0.0, 1.0)));

	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0),
		glm::vec4(1.0, 1.0, 1.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0),
		glm::vec4(1.0, 0.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, 1.0),
		glm::vec4(1.0, 0.0, 1.0, 1.0)));

	//vertices for the back face of the cube
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0),
		glm::vec4(0.0, 0.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0),
		glm::vec4(1.0, 0.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0),
		glm::vec4(1.0, 1.0, 0.0, 1.0)));

	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0),
		glm::vec4(0.0, 0.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0),
		glm::vec4(1.0, 1.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0),
		glm::vec4(0.0, 1.0, 0.0, 1.0)));

	//vertices for the left face of the cube
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0),
		glm::vec4(0.0, 0.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0),
		glm::vec4(0.0, 0.0, 1.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0),
		glm::vec4(0.0, 1.0, 1.0, 1.0)));

	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0),
		glm::vec4(0.0, 0.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0),
		glm::vec4(0.0, 1.0, 1.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0),
		glm::vec4(0.0, 1.0, 0.0, 1.0)));

	//vertices for the upper face of the cube
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0),
		glm::vec4(1.0, 1.0, 1.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0),
		glm::vec4(0.0, 1.0, 1.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0),
		glm::vec4(1.0, 1.0, 0.0, 1.0)));

	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0),
		glm::vec4(0.0, 1.0, 1.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0),
		glm::vec4(1.0, 1.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0),
		glm::vec4(0.0, 1.0, 0.0, 1.0)));

	//vertices for the bottom face of the cube
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0),
		glm::vec4(0.0, 0.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0),
		glm::vec4(1.0, 0.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0),
		glm::vec4(0.0, 0.0, 1.0, 1.0)));

	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0),
		glm::vec4(1.0, 0.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0),
		glm::vec4(0.0, 0.0, 1.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, 1.0),
		glm::vec4(1.0, 0.0, 1.0, 1.0)));

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 36, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::colour)));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);

	rotationSpeed = glm::vec3(90.0, 90.0, 90.0);
	rotation = glm::vec3(0.0, 0.0, 0.0);
	prevTimeSinceStart = 0;
}

void Cube::Update() { }

void Cube::Draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix)
{
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	float deltaTime = (float)(timeSinceStart - prevTimeSinceStart) / 1000.0f;
	prevTimeSinceStart = timeSinceStart;
	rotation = (deltaTime * rotationSpeed) + rotation;

	glm::vec3 rotationSin = glm::vec3(rotation.x * PI / 180, rotation.y * PI / 180, rotation.z * PI / 180);

	glUseProgram(program);
	glUniform3f(glGetUniformLocation(program, "rotation"), rotationSin.x, rotationSin.y, rotationSin.z);
	glUniformMatrix4fv(glGetUniformLocation(program, "viewMatrix"), 1, false, &viewMatrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projectionMatrix"), 1, false, &projectionMatrix[0][0]);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}