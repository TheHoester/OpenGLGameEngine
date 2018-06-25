#include "Model.h"

using namespace GameEngine::Rendering::Models;

Model::Model() { }

Model::~Model()
{
	Destroy();
}

GLuint Model::GetVao() const { return vao; }
const std::vector<GLuint>& Model::GetVbos() const { return vbos; }
void Model::SetProgram(GLuint program) { this->program = program; }

void Model::Draw() { }

void Model::Draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) { }

void Model::Update() { }

void Model::Destroy()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(vbos.size(), &vbos[0]);
	vbos.clear();
}