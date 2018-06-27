#include "Model.h"

using namespace GameEngine::Rendering::Models;

Model::Model() { }

Model::~Model()
{
	Destroy();
}

GLuint Model::GetVao() const { return vao; }
const std::vector<GLuint>& Model::GetVbos() const { return vbos; }
const GLuint Model::GetTexture(std::string textureName) const { return textures.at(textureName); }

void Model::SetProgram(GLuint program) 
{
	if (program == 0) return;
	this->program = program; 
}

void Model::SetTexture(std::string textureName, GLuint texture)
{
	if (texture == 0) return;
	textures[textureName] = texture;
}

void Model::Draw() { }

void Model::Draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) { }

void Model::Update() { }

void Model::Destroy()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(vbos.size(), &vbos[0]);
	vbos.clear();

	if (textures.size() > 0)
	{
		for (auto t : textures)
			glDeleteTextures(1, &t.second);

		textures.clear();
	}
}

