#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

class Buffer
{
public:
	unsigned int ID;
	GLenum target;
	GLenum usage;
	Buffer(GLenum Target, GLenum Usage = GL_STATIC_DRAW);
	void Bind();
	void UnBind();
	template<typename T>
	void SetData(std::vector<T> buffer)
	{
		Bind();
		glBufferData(target, buffer.size() * sizeof(T), buffer.data(), usage);
		UnBind();
	}
};