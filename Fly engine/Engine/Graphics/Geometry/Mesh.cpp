#include "Mesh.h"
#include <string>
#include "../../Resources/ResourceDictionary.h"
#include "../Shader/Shader.h"

Mesh::Mesh()
{
}

Mesh::Mesh(GLenum Usage)
{
	vao = VAO(Usage);
	vao.AddVertexBufferObject(3);
	vao.AddVertexBufferObject(4);
	vao.AddVertexBufferObject(3);
	vao.AddVertexBufferObject(2);
	vao.AddElementBufferObject();
	vao.Init();
}

Mesh::~Mesh()
{
}

void Mesh::Upload()
{
	vao.m_vbo[0].SetData<float>(Position);
	vao.m_vbo[1].SetData<float>(Color);
	vao.m_vbo[2].SetData<float>(Normaly);
	vao.m_vbo[3].SetData<float>(UV);
	vao.ebo.SetData<unsigned int>(Indices);
}

void Mesh::Draw()
{
	vao.Bind();
	glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, nullptr);
	vao.UnBind();
}