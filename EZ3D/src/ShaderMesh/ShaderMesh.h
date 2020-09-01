#pragma once
#include "../Shader/Shader.h"
#include "../Mesh/Mesh.h"
#include "../Transform/Transform.h"

class ShaderMesh
{
public:
	void Draw();

	void UpdateUniforms()
	{
	}

private:
	Shader _shader;
	Mesh _mesh;
	Transform _transform;
};

