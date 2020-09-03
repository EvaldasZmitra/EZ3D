#pragma once
#include "../Shader/Shader.h"
#include "../Texture/Texture.h"

class Material
{
public:
	Material(const Shader* shader);

private:
	const Shader& _shader;
	const Texture& _texture;
};

