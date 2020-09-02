#pragma once
#include "../Mesh/Mesh.h";
#include "../Shader/Shader.h";
#include "../Transform/Transform.h"
#include "../Texture/Texture.h"
#include "../Light/Light.h"

class Model
{
public:
	Model();
	void Init(const Mesh& mesh, const Shader& shader, const Texture &texture);
	void Draw();

private:
	Mesh _mesh;
	Shader _shader;
	Texture _texture;
	float _counter = 0;
};

