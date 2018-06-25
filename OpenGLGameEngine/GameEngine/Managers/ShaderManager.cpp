#include "ShaderManager.h"

using namespace GameEngine::Managers;

std::map<std::string, GLuint> ShaderManager::programs;

ShaderManager::ShaderManager(void) {}

ShaderManager::~ShaderManager(void) 
{
	for (std::map<std::string, GLuint>::iterator i = programs.begin(); i != programs.end(); ++i)
		glDeleteProgram(i->second);

	programs.clear();
}

std::string ShaderManager::ReadShader(const std::string& filename)
{
	std::string shaderCode;
	std::ifstream file(filename, std::ios::in);

	if (!file.good())
	{
		std::cout << "Can't read file " << filename.c_str() << std::endl;
		std::terminate();
	}

	file.seekg(0, std::ios::end);
	shaderCode.resize((unsigned int)file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&shaderCode[0], shaderCode.size());
	file.close();

	return shaderCode;
}

GLuint ShaderManager::CreateShader(GLenum shaderType, std::string& source, std::string& shaderName)
{
	int compileResult = 0;
	GLuint shader = glCreateShader(shaderType);
	const char* shaderCodePtr = source.c_str();
	const int shaderCodeSize = source.size();

	glShaderSource(shader, 1, &shaderCodePtr, &shaderCodeSize);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);

	// Check for errors
	if (compileResult == GL_FALSE)
	{
		int infoLogLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
		std::vector<char> shaderLog(infoLogLength);
		glGetShaderInfoLog(shader, infoLogLength, NULL, &shaderLog[0]);
		std::cout << "ERROR compiling shader: " << shaderName.c_str() << std::endl << &shaderLog[0] << std::endl;
	}

	return shader;
}

void ShaderManager::CreateProgram(const std::string& shaderName, const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename)
{
	// Read the shader files and save the code
	std::string vertexShaderCode = ReadShader(vertexShaderFilename);
	std::string fragmentShaderCode = ReadShader(fragmentShaderFilename);
	std::string vertexShaderName = "vertex shader";
	std::string fragmentShaderName = "fragment shader";
	GLuint vertexShader = CreateShader(GL_VERTEX_SHADER, vertexShaderCode, vertexShaderName);
	GLuint fragmentShader = CreateShader(GL_FRAGMENT_SHADER, fragmentShaderCode, fragmentShaderName);

	int linkResult = 0;
	// Create the program handle, attach the shaders and link it
	GLuint program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &linkResult);

	// Check for link errors
	if (linkResult == GL_FALSE)
	{
		int infoLogLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
		std::vector<char> programLog(infoLogLength);
		glGetProgramInfoLog(program, infoLogLength, NULL, &programLog[0]);
		std::cout << "Shader Manager : LINK ERROR" << std::endl << &programLog[0] << std::endl;
	}

	if (programs.find(shaderName) != programs.end())
		programs[shaderName] = program;
	else
		programs.insert(std::pair<std::string, GLuint>(shaderName, program));
}


const GLuint ShaderManager::GetShader(const std::string& shaderName)
{
	if (programs.find(shaderName) != programs.end())
		return programs.at(shaderName);
	else
		return -1;
}