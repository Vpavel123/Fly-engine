#pragma once
#include "Texture.h"

class Texture2D : public Texture
{
public:
	GLint internalFormat;
	GLenum pixelFormat;
	Texture2D();
	Texture2D(GLint internalFormat, GLenum pixelFormat);
	void Load(int Texture_Width, int Texture_Height, void* data);
	//void CreateEmpty();
};