#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera
{
public:
	glm::mat4 GetVP()
	{
		auto view = glm::lookAt(_pos, _lookAt, glm::vec3(0,1,0) );
		auto projection = glm::perspective(
			(float)glm::radians(_fov),
			_aspect,
			_zNear,
			_zFar);

		return projection * view; // Remember : inverted !

	}

private:
	float _fov = 60;
	float _aspect = (16.0 / 9.0);
	float _zNear = 0.1f;
	float _zFar = 100.0f;

	glm::vec3 _pos;
	glm::vec3 _lookAt;
};

