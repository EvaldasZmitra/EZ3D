#pragma once
#include <string>
#include <GL\glew.h>

class Texture
{
public:
	Texture(const std::string& fileName);
	void Bind() const;
	GLuint _texture;

	virtual ~Texture();
protected:
private:
};
