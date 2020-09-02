#include "Model.h"
#include "../Camera/Camera.h"

Model::Model()
{
}

void Model::Init(const Mesh& mesh, const Shader& shader, const Texture& texture)
{
	_mesh = mesh;
	_shader = shader;
	_texture = texture;
}

void Model::Draw()
{
	auto cam = Camera(glm::vec3(4,3,3), glm::vec3(), 45);
	auto transform = Transform(glm::vec3(0,0,0), glm::vec3(0, 0, 0), glm::vec3(1));
	_shader.Use();
	_texture.Bind();
	_shader.Update("MVP", cam.GetVP() * transform.GetTransform());
	_shader.Update("M", transform.GetTransform());

	auto light = Light();
	_counter += 0.001F;
	_shader.Update("lightPosition", glm::vec3(4, 5 * sin(_counter), 3));
	_shader.Update("LIGHT_INTENSITY", light.Intensity);

	_mesh.Draw();
}
