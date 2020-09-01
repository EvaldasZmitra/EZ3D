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
		auto loc = _shader.GetLocation("Keyword");
		_shader.UpdateMatrix(loc, _transform.GetTransform());
	}

private:
	Shader _shader;
	Mesh _mesh;
	Transform _transform;
};

