#include "Model.h"
#include "../Camera/Camera.h"

Model::Model()
{
}

void Model::Init(const Mesh& mesh, const Shader& shader, const Texture& texture, const Texture& texture2)
{
	_mesh = mesh;
	_shader = shader;
	_texture = texture;
	_texture2 = texture2;
}

void Model::Draw()
{
	auto cam = Camera(glm::vec3(4,3,0), glm::vec3(), 90);
	auto transform = Transform(glm::vec3(0,0,0), glm::vec3(0, 0, 0), glm::vec3(50, 1, 50));
	_shader.Use();
	//_texture.Bind();

	_shader.UpdateTexture("myTextureSampler", _texture._texture, 0);
	_shader.UpdateTexture("myNormalSampler", _texture2._texture, 1);
	_shader.Update("MVP", cam.GetVP() * transform.GetTransform());
	_shader.Update("M", transform.GetTransform());

	auto light = Light();
	_shader.Update("lightPosition", glm::vec3(4, 10, 3));
	_shader.Update("LIGHT_INTENSITY", light.Intensity);

	_mesh.Draw();
}
