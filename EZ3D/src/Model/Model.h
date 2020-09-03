#pragma once
#include "../Mesh/Mesh.h";
#include "../Shader/Shader.h";
#include "../Transform/Transform.h"
#include "../Texture/Texture.h"
#include "../Light/Light.h"

class Model
{
public:
	Model(const Mesh* mesh, const Shader* shader);
	void Draw();

private:
	const Mesh& _mesh;
	const Shader& _shader;
};

