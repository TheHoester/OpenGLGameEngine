#pragma once

#include "ModelsManager.h"
#include "../Core/Init/IListener.h"

namespace GameEngine
{
	namespace Managers
	{
		class SceneManager : public Core::IListener
		{
		private:
			ModelsManager* modelsManager;

			glm::mat4 projectionMatrix;
			glm::mat4 viewMatrix;

		public:
			SceneManager(void);
			~SceneManager(void);

			void SetModelsManager(ModelsManager*& modelsManager);

			virtual void NotifyBeginFrame(void);
			virtual void NotifyDisplayFrame(void);
			virtual void NotifyEndFrame(void);
			virtual void NotifyReshape(int width, int height, int prevWidth, int prevHeight);
		};
	}
}