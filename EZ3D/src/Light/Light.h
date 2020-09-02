#pragma once
#include <glm/glm.hpp>

class Light
{
public:
	glm::vec3 Position;
	glm::vec4 Color = glm::vec4(1);
	float Intensity = 1;
};

