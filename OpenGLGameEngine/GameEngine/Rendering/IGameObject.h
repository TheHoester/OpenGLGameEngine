#pragma once

#include "GL/glew.h"
#include "GL/freeglut.h"
#include "VertexFormat.h"
#include <vector>
#include <iostream>

namespace GameEngine
{
	namespace Rendering
	{
		class IGameObject
		{
		public:
			virtual ~IGameObject(void) = 0;

			virtual void Draw(void) = 0;
			virtual void Draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) = 0;
			virtual void Update(void) = 0;
			virtual void SetProgram(GLuint shaderName) = 0;
			virtual void Destroy(void) = 0;

			virtual GLuint GetVao(void) const = 0;
			virtual const std::vector<GLuint>& GetVbos(void) const = 0;

			virtual void SetTexture(std::string textureName, GLuint texture) = 0;
			virtual const GLuint GetTexture(std::string textureName) const = 0;
		};

		inline IGameObject::~IGameObject(void) { }
	}
}