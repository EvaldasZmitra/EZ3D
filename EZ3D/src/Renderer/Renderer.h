#pragma once
#include "../Mesh/Mesh.h";
#include "../Shader/Shader.h"
#include "../Model/Model.h"
#include "../ModelLoader/ModelLoader.h"
#include "../Texture/Texture.h"

class Renderer
{
public:
	Renderer();
	void Render();

	void AddModel(const Model &model);

protected:
private:
	std::vector<Model> _models;
};

