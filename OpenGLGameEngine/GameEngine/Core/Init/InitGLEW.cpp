#include "InitGLEW.h"

using namespace GameEngine::Core;
using namespace GameEngine::Core::Init;

void InitGLEW::Init()
{
	glewExperimental = true;
	if (glewInit() == GLEW_OK)
		std::cout << "GLEW: Initialize" << std::endl;
	if (glewIsSupported("GL_VERSION_4_4"))
		std::cout << "GLEW GL_4_4 is 4.4\n";
	else
		std::cout << "GLEW GL_VERSION_4_4 not supported\n";
}