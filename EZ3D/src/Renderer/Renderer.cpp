#include "Renderer.h"
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <iostream>
#include <fstream>

Renderer::Renderer()
{
	auto modelLoader = ModelLoader();
	auto _mesh = modelLoader.LoadModel("Resources/cube.obj");

	auto _shader = new Shader();
	auto vShader = ReadText("Resources/shaderVertex.glsl");
	auto fShader = ReadText("Resources/shaderFragment.glsl");
	_shader->AddShader(fShader, GL_FRAGMENT_SHADER);
	_shader->AddShader(vShader, GL_VERTEX_SHADER);
	_shader->Compile();

	auto texture = new Texture();
	texture->Init("Resources/brick_color.png");

	auto texture2 = new Texture();
	texture2->Init("Resources/brick_normal.png");

	_model = Model();
	_model.Init(*_mesh, *_shader, *texture, *texture2);
}

void Renderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0F, 0.2F, 0.6F, 1.0F);
	_model.Draw();
}

std::string Renderer::ReadText(const std::string &file)
{
	std::ifstream t(file);
	std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	return str;
}
