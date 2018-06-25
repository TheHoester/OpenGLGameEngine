#pragma once

#include "../GameEngine/Engine.h"
#include "Cube.h"

using namespace GameEngine;

int main(int argc, char** argv)
{
	Engine* engine = new Engine();
	engine->Init();
	engine->GetShaderManager()->CreateProgram("CubeShader", "Shaders\\CubeVertexShader.glsl", "Shaders\\CubeFragmentShader.glsl");

	Cube* cube = new Cube();
	cube->SetProgram(engine->GetShaderManager()->GetShader("CubeShader"));
	cube->Create();

	engine->GetModelsManager()->SetModel("Cube", cube);
	engine->Run();

	delete engine;
	return 0;
}