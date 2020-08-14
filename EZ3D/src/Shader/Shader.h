#pragma once
#include <string>

class Shader
{
	void Use();
	void AddData();
	void AddUniform(std::string name, float data);
};

