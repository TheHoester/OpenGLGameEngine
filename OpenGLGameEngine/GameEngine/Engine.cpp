#include "Engine.h"

using namespace GameEngine;
using namespace Core;

Engine::Engine() { }

Engine::~Engine() 
{ 
	if (mSceneManager)
		delete mSceneManager;
	if (mShaderManager)
		delete mShaderManager;
	if (mModelsManager)
		delete mModelsManager;
	if (mTextureLoader)
		delete mTextureLoader;
}

Managers::SceneManager* Engine::GetSceneManager() const { return mSceneManager; }
Managers::ShaderManager* Engine::GetShaderManager() const { return mShaderManager; }
Managers::ModelsManager* Engine::GetModelsManager() const { return mModelsManager; }
TextureLoader* Engine::GetTextureLoader() const { return mTextureLoader; }

bool Engine::Init() 
{ 
	WindowInfo window(std::string("OpenGL Game Engine"), 10, 10, 800, 600, true);
	ContextInfo context(4, 4, true);
	FramebufferInfo framebufferInfo(true, true, true, true);
	Init::InitGLUT::Init(window, context, framebufferInfo);

	mSceneManager = new Managers::SceneManager();
	Init::InitGLUT::SetListener((IListener*&)mSceneManager);

	mShaderManager = new Managers::ShaderManager();
	mShaderManager->CreateProgram("colourShader", "..\\GameEngine\\Shaders\\VertexShader.glsl", "..\\GameEngine\\Shaders\\FragmentShader.glsl");
	mTextureLoader = new TextureLoader();

	if (mSceneManager && mShaderManager)
	{
		mModelsManager = new Managers::ModelsManager();
		mSceneManager->SetModelsManager(mModelsManager);
	}
	else
		return false;

	return true;
}

void Engine::Run() 
{
	Init::InitGLUT::Run();
}