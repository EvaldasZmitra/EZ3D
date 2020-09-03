#pragma once
#include "../ModelLoader/ModelLoader.h"
#include "../Shader/Shader.h"
#include "../Mesh/Mesh.h"
#include "../Texture/Texture.h"
#include "../Material/Material.h"
#include <nlohmann/json.hpp>
#include <map>
#include <string>
#include <iostream>
#include <fstream>

class AssetManager
{
public:
	AssetManager();

	std::map<std::string, Shader*> ShaderStore;
	std::map<std::string, Texture*> TextureStore;
	std::map<std::string, Mesh*> MeshStore;
	std::map<std::string, Material*> MaterialStore;

private:
	std::string ReadText(const std::string& file);
};

