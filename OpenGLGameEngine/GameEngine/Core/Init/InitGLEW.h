#pragma once

#include <iostream>
#include "GL\glew.h"
#include "GL\freeglut.h"

namespace GameEngine
{
	namespace Core
	{
		namespace Init
		{
			class InitGLEW
			{
			public:
				static void Init();
			};
		}
	}
}