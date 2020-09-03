#include "Renderer.h"
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <iostream>
#include <fstream>

Renderer::Renderer()
{
}

void Renderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0F, 0.2F, 0.6F, 1.0F);
	
	for (auto model : _models)
	{
		model.Draw();
	}
}

void Renderer::AddModel(const Model &model)
{
	_models.push_back(model);
}
