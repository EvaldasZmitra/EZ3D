#pragma once
#include <assimp\mesh.h>
#include "..\ModelLoader\ModelLoader.h";
#include <GL\glew.h>
#include <glm\glm.hpp>

class Mesh
{
public:
	Mesh();
	~Mesh();
	void Draw();

	void AddBuffer(GLuint index, const std::vector<glm::vec3>& data);
	void AddBuffer(GLuint index, const std::vector<glm::vec2>& data);
	void AddIndexBuffer(const std::vector<unsigned>& data);

private:
	GLuint _vao;
	std::vector<GLuint> _vbos;

	ModelLoader _loader;
	aiMesh* _mesh;

	GLsizei _numIndices;
};

