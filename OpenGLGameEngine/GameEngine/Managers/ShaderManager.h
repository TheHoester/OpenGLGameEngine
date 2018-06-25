#pragma once

#include "GL\glew.h"
#include "GL\freeglut.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

namespace GameEngine
{
	namespace Managers
	{
		class ShaderManager
		{
		private:
			std::string ReadShader(const std::string& filename);
			GLuint CreateShader(GLenum shaderType, std::string& source, std::string& shaderName);
			static std::map<std::string, GLuint> programs;

		public:
			ShaderManager(void);
			~ShaderManager(void);
			void CreateProgram(const std::string& shaderName, const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename);
			static const GLuint GetShader(const std::string& shaderName);
		};
	}
}