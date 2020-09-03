#include "Model.h"
#include "../Camera/Camera.h"

Model::Model(const Mesh* mesh, const Shader* shader) :
	_mesh(*mesh),
	_shader(*shader)
{
}

void Model::Draw()
{
	auto cam = Camera(glm::vec3(4, 3, 0), glm::vec3(), 90);
	auto transform = Transform(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(50, 1, 50));

	_shader.Use();

	_shader.BindTextures();
	_shader.Update("MVP", cam.GetVP() * transform.GetTransform());
	_shader.Update("M", transform.GetTransform());

	auto light = Light();
	_shader.Update("lightPosition", glm::vec3(4, 10, 3));
	_shader.Update("LIGHT_INTENSITY", light.Intensity);

	_mesh.Draw();
}
