#pragma once
#include <string>
#include <GL\glew.h>
#include <vector>
#include <glm/glm.hpp>

class Shader
{
public:
	Shader();
	~Shader();

	void AddShader(const std::string& shaderCode, GLenum type);
	void Compile();
	void Use();

	void Update(const std::string name, glm::mat4 val)
	{
		auto loc = glGetUniformLocation(_programId, name.c_str());
		glUniformMatrix4fv(loc, sizeof(GLint) * 16, false, &val[0][0]);
	}

	void Update(const std::string name, glm::vec3 val)
	{
		auto loc = glGetUniformLocation(_programId, name.c_str());
		glUniform3f(loc, val.x, val.y, val.z);
	}

	void Update(const std::string name, glm::vec2 val)
	{
		auto loc = glGetUniformLocation(_programId, name.c_str());
		glUniform2f(loc, val.x, val.y);
	}

	void Update(const std::string name, GLfloat val)
	{
		auto loc = glGetUniformLocation(_programId, name.c_str());
		glUniform1f(loc, val);
	}

	void Update(const std::string name, GLint val)
	{
		auto loc = glGetUniformLocation(_programId, name.c_str());
		glUniform1i(loc, val);
	}

	void Update(const std::string name, bool val)
	{
		auto loc = glGetUniformLocation(_programId, name.c_str());
		glUniform1i(loc, val);
	}

	void UpdateTexture(const std::string name, GLuint texture, GLint unit)
	{
		auto loc = glGetUniformLocation(_programId, name.c_str());
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, texture);
		glUniform1f(loc, unit);
	}

private:
	GLuint _programId;
	std::vector<GLuint> _shaderIds;
};

