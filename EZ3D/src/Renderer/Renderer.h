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

protected:
private:
	std::string ReadText(const std::string& file);
	Model _model;
};

