#pragma once

#include "Core/Init/InitGLUT.h"
#include "Managers/SceneManager.h"

namespace GameEngine
{
	class Engine
	{
	private:
		Managers::SceneManager* mSceneManager;
		Managers::ShaderManager* mShaderManager;
		Managers::ModelsManager* mModelsManager;

	public:
		Engine(void);
		~Engine(void);

		bool Init(void);
		void Run(void);

		Managers::SceneManager* GetSceneManager(void) const;
		Managers::ShaderManager* GetShaderManager(void) const;
		Managers::ModelsManager* GetModelsManager(void) const;
	};
}