#pragma once
#include <string>
#include <GL\glew.h>

class Texture
{
public:
	Texture();
	void Init(const std::string& fileName);
	void Bind();

	virtual ~Texture();
protected:
private:
	GLuint _texture;
};
