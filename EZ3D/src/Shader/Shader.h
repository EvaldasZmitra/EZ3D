#pragma once
#include <string>
#include <GL\glew.h>
#include <vector>

class Shader
{
public:
	Shader();
	~Shader();

	void AddShader(const std::string& shaderCode, GLenum type);
	void Compile();
	void Use();

private:
	GLuint _programId;
	std::vector<GLuint> _shaderIds;
};

