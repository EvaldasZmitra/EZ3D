#pragma once
#include <string>
#include <GL\glew.h>
#include <vector>
#include <glm/glm.hpp>
#include "../Texture/Texture.h"

class Shader
{
public:
	Shader();
	~Shader();

	void AddShader(const std::string& shaderCode, GLenum type);
	void Compile();
	void Use() const;

	void Update(const std::string name, glm::mat4 val) const
	{
		auto loc = glGetUniformLocation(_programId, name.c_str());
		glUniformMatrix4fv(loc, 1, false, &val[0][0]);
	}

	void Update(const std::string name, glm::vec3 val) const
	{
		auto loc = glGetUniformLocation(_programId, name.c_str());
		glUniform3f(loc, val.x, val.y, val.z);
	}

	void Update(const std::string name, glm::vec2 val) const
	{
		auto loc = glGetUniformLocation(_programId, name.c_str());
		glUniform2f(loc, val.x, val.y);
	}

	void Update(const std::string name, GLfloat val) const
	{
		auto loc = glGetUniformLocation(_programId, name.c_str());
		glUniform1f(loc, val);
	}

	void Update(const std::string name, GLint val) const
	{
		auto loc = glGetUniformLocation(_programId, name.c_str());
		glUniform1i(loc, val);
	}

	void Update(const std::string name, bool val) const
	{
		auto loc = glGetUniformLocation(_programId, name.c_str());
		glUniform1i(loc, val);
	}

	void AddTexture(const Texture *texture, const std::string &name)
	{
		_textureNames.push_back(name);
		_textures.push_back(texture);
	}

	void BindTextures() const
	{
		for (int i = 0; i < _textures.size(); i++)
		{
			auto loc = glGetUniformLocation(_programId, _textureNames[i].c_str());
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, _textures[i]->_texture);
			glUniform1i(loc, i);
		}
	}

private:
	GLuint _programId;
	std::vector<GLuint> _shaderIds;

	std::vector<const Texture*> _textures;
	std::vector<std::string> _textureNames;
};

