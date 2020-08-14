#pragma once
#include "../Shader/Shader.h"
#include "../Mesh/Mesh.h"

class ShaderMesh
{
public:
	void Draw();

private:
	Shader _shader;
	Mesh _mesh;
};

