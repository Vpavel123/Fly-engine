#include "VAO.h"

VAO::VAO()
{
}

VAO::VAO(GLenum Usage)
{
	usage = Usage;
	glGenVertexArrays(1, &ID);
}

void VAO::Bind()
{
	glBindVertexArray(ID);
}

void VAO::UnBind()
{
	glBindVertexArray(0);
}

void VAO::AddVertexBufferObject(int component)
{
	m_vbo.push_back(VBO(component, usage));
}

void VAO::AddElementBufferObject()
{
	ebo = EBO(usage);
}

void VAO::Init()
{
	Bind();
	int index = 0;

	for (VBO Vbo : m_vbo)
	{
		Vbo.Bind();
		glVertexAttribPointer(index, Vbo.ComponentSize, GL_FLOAT, GL_FALSE, 0, nullptr);
		glEnableVertexAttribArray(index);
		index++;
		Vbo.UnBind();
	}

	ebo.Bind();
	UnBind();
}