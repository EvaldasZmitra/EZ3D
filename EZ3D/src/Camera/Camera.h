#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera
{
public:
	Camera(glm::vec3 pos, glm::vec3 lookAt, float fov)
	{
		_pos = pos;
		_lookAt = lookAt;
		_fov = fov;
	}

	glm::mat4 GetVP()
	{
		auto view = glm::lookAt(_pos, _lookAt, glm::vec3(0,1,0) );
		auto projection = glm::perspective(
			(float)glm::radians(_fov),
			_aspect,
			_zNear,
			_zFar);
		auto model = glm::mat4(1);

		return projection * view * model;
	}

private:
	float _fov = 60;
	float _aspect = (16.0 / 9.0);
	float _zNear = 0.1f;
	float _zFar = 100.0f;

	glm::vec3 _pos;
	glm::vec3 _lookAt;
};

