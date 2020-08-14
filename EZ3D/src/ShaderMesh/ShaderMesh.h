#pragma once
#include "Shader.h"
#include "Mesh.h"

class ShaderMesh
{
public:
	void Draw();

private:
	Shader _shader;
	Mesh _mesh;
};

