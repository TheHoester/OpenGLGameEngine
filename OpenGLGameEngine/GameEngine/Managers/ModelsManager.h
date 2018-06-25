#pragma once

#include "ShaderManager.h"
#include "../Rendering/IGameObject.h"
#include "../Rendering/Models/Quad.h"
#include "../Rendering/Models/Triangle.h"

using namespace GameEngine::Rendering;

namespace GameEngine
{
	namespace Managers
	{
		class ModelsManager
		{
		private:
			std::map<std::string, IGameObject*> gameModelList;

		public:
			ModelsManager(void);
			~ModelsManager(void);

			void Draw(void);
			void Draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix);
			void Update(void);
			void DeleteModel(const std::string& gameModelName);
			void SetModel(const std::string& gameModelName, IGameObject* gameModel);
			const IGameObject& GetModel(const std::string& gameModelName) const;
		};
	}
}