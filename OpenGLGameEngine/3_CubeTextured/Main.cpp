#pragma once

#include <GameEngine\Engine.h>
#include "CubeTextured.h"

using namespace GameEngine;

int main(int argc, char** argv)
{
	Engine* engine = new Engine();
	engine->Init();
	engine->GetShaderManager()->CreateProgram("CubeShader", "Shaders\\CubeVertexShader.glsl", "Shaders\\CubeFragmentShader.glsl");

	CubeTextured* cube = new CubeTextured();
	int program = engine->GetShaderManager()->GetShader("CubeShader");
	if (program != 0)
	{
		cube->SetProgram(program);
		cube->Create();
	}
	else
	{
		std::cout << "Invalid program...";
		std::cin.get();
	}

	unsigned int texture = engine->GetTextureLoader()->LoadTexture("Textures\\Crate.bmp", 256, 256);
	cube->SetTexture("Create", texture);

	engine->GetModelsManager()->SetModel("Cube", cube);
	engine->Run();

	delete engine;
	return 0;
}