#include "Mesh.h"

Mesh::Mesh()
{
	glGenVertexArrays(1, &_vao);
}

Mesh::~Mesh()
{
	for (auto vbo : _vbos)
	{
		glDeleteBuffers(1, &vbo);
	}
	glDeleteVertexArrays(1, &_vao);
}

void Mesh::Draw() const
{
	glBindVertexArray(_vao);
	glDrawElements(GL_TRIANGLES, _numIndices, GL_UNSIGNED_INT, 0);
}

void Mesh::AddBuffer(GLuint index, const std::vector<glm::vec3>& data)
{
	glBindVertexArray(_vao);
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glEnableVertexAttribArray(index);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data[0]), &data[0], GL_STATIC_DRAW);
	glVertexAttribPointer(index, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	_vbos.push_back(vbo);
}

void Mesh::AddBuffer(GLuint index, const std::vector<glm::vec2>& data)
{
	glBindVertexArray(_vao);
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glEnableVertexAttribArray(index);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data[0]), &data[0], GL_STATIC_DRAW);
	glVertexAttribPointer(index, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
	_vbos.push_back(vbo);
}

void Mesh::AddIndexBuffer(const std::vector<unsigned>& data)
{
	_numIndices = data.size();
	glBindVertexArray(_vao);
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(unsigned int), &data[0], GL_STATIC_DRAW);
	_vbos.push_back(vbo);
}
