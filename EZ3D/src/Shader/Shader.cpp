#include "Shader.h"

Shader::Shader()
{
	_programId = glCreateProgram();
}

Shader::~Shader()
{
	for (auto shaderId : _shaderIds)
	{
		glDetachShader(_programId, shaderId);
		glDeleteShader(shaderId);
	}
}

void Shader::AddShader(const std::string& shaderCode, GLenum type)
{
	auto shaderId = glCreateShader(type);
	char const* codePointer = shaderCode.c_str();
	glShaderSource(shaderId, 1, &codePointer, NULL);
	glCompileShader(shaderId);
	glAttachShader(_programId, shaderId);
	_shaderIds.push_back(shaderId);
}

void Shader::Compile()
{
	glLinkProgram(_programId);
}

void Shader::Use()
{
	glUseProgram(_programId);
}
