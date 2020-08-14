#pragma once
#include "../Mesh/Mesh.h";
#include "../Shader/Shader.h";

class Model
{
public:
	void Init(const Mesh& mesh, const Shader& shader);
	void Draw();

private:
	Mesh _mesh;
	Shader _shader;
};

