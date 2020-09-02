#pragma once
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/matrix4x4.h>
#include <assimp/cimport.h>

#include <Windows.h>
#include <iostream>
#include <stdint.h>
#include <vector>
#include <glm/glm.hpp>
#include "../Mesh/Mesh.h"

class ModelLoader
{
public:
	Mesh* LoadModel(const std::string& file);

private:
};

