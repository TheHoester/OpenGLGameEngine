#pragma once

#include "../IGameObject.h"
#include <vector>
#include <map>

namespace GameEngine
{
	namespace Rendering
	{
		namespace Models
		{
			class Model : public IGameObject
			{
			protected:
				GLuint vao;
				GLuint program;
				std::vector<GLuint> vbos;
				std::map<std::string, GLuint> textures;

			public:
				Model(void);
				virtual ~Model(void);

				virtual void Draw(void) override;
				virtual void Draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) override;
				virtual void Update(void) override;
				virtual void Destroy(void) override;

				virtual GLuint GetVao(void) const override;
				virtual const std::vector<GLuint>& GetVbos(void) const override;
				virtual const GLuint GetTexture(std::string textureName) const override;
				virtual void SetProgram(GLuint shaderName) override;
				virtual void SetTexture(std::string textureName, GLuint texture) override;
			};
		}
	}
}