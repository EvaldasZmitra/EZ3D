#include "Renderer.h"
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <iostream>
#include <fstream>

Renderer::Renderer()
{
	std::vector<glm::vec3> vertices = {
	glm::vec3(-1.0, -1.0, 0.0),
	glm::vec3(1.0, -1.0, 0.0),
	glm::vec3(0.0, 1.0, 0.0)
	};
	std::vector<unsigned int> indices = { 0, 1, 2 };

	auto _mesh = new Mesh();
	_mesh->AddBuffer(0, vertices);
	_mesh->AddIndexBuffer(indices);

	auto _shader = new Shader();
	auto vShader = ReadText("Resources/shader.fragment");
	auto fShader = ReadText("Resources/shader.vertex");
	_shader->AddShader(vShader, GL_FRAGMENT_SHADER);
	_shader->AddShader(fShader, GL_VERTEX_SHADER);
	_shader->Compile();

	_model = Model();
	_model.Init(*_mesh, *_shader);
}

void Renderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0F, 0.2F, 0.6F, 1.0F);
	_model.Draw();
}

std::string Renderer::ReadText(const std::string &file)
{
	std::ifstream t(file);
	std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	return str;
}
