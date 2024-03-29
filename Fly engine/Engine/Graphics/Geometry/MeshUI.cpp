#include "MeshUI.h"

MeshUI::MeshUI()
{
}

MeshUI::MeshUI(GLenum Usage)
{
	vao = VAO(Usage);
	vao.AddVertexBufferObject(2);
	vao.AddVertexBufferObject(4);
	vao.AddVertexBufferObject(2);
	vao.AddElementBufferObject();
	vao.Init();
}

void MeshUI::Upload()
{
	vao.m_vbo[0].SetData<float>(Position);
	vao.m_vbo[1].SetData<float>(Color);
	vao.m_vbo[2].SetData<float>(UV);
	vao.ebo.SetData<unsigned int>(Indices);
}

void MeshUI::Draw()
{
	vao.Bind();
	glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, nullptr);
	vao.UnBind();
}