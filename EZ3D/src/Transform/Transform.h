#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform
{
public:
	Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale)
	{
		_pos = pos;
		_rot = rot;
		_scale = scale;
	}

	glm::mat4 GetTransform()
	{
		return Translate() * Scale() * Rotate();
	}

private:
	glm::mat4 Rotate()
	{
		return glm::rotate(_rot.x, glm::vec3(1, 0, 0)) *
			glm::rotate(_rot.y, glm::vec3(0, 1, 0)) *
			glm::rotate(_rot.z, glm::vec3(0, 0, 1));
	}

	glm::mat4 Scale()
	{
		return glm::scale(_scale);
	}

	glm::mat4 Translate()
	{
		return glm::translate(_pos);
	}

	glm::vec3 _pos;
	glm::vec3 _scale;
	glm::vec3 _rot;
};

