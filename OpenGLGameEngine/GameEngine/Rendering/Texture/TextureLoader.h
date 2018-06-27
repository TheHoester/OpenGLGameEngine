#pragma once

#include <GL\glew.h>
#include <fstream>
#include <iostream>
#include <string>
#include "BMPHeaders.h"

namespace GameEngine
{
	namespace Rendering
	{
		class TextureLoader
		{
		private:
			void LoadBMPFile(const std::string& filename, unsigned int& width, unsigned int& height, unsigned char*& data);

		public:
			TextureLoader();
			~TextureLoader();

			unsigned int LoadTexture(const std::string& filename, unsigned int width, unsigned int height);
		};
	}
}