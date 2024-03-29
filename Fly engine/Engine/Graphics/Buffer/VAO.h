#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "VBO.h"
#include "EBO.h"

class VAO
{
public:
	GLenum usage;
	EBO ebo;
	unsigned int ID;
	VAO();
	VAO(GLenum Usage);
	void Bind();
	void UnBind();
	void AddVertexBufferObject(int component);
	void AddElementBufferObject();
	void Init();
	std::vector<VBO> m_vbo;
};