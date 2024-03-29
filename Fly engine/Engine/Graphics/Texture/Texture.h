#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Texture
{
public:
	unsigned int ID;
	GLenum BindTarget;
	Texture();
	Texture(GLenum target);
	~Texture();
	void Bind();
	void UnBind();
	void Use(unsigned int unit);
};