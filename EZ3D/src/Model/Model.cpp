#include "Model.h"

void Model::Init(const Mesh& mesh, const Shader& shader)
{
	_mesh = mesh;
	_shader = shader;
}

void Model::Draw()
{
	_shader.Use();
	_mesh.Draw();
}
