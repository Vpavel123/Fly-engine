#include "Texture2D.h"
#include <stb_image.h>
#include <iostream>

Texture2D::Texture2D()
{

}

Texture2D::Texture2D(GLint internalFormat, GLenum pixelFormat) : Texture(GL_TEXTURE_2D)
{
	this->internalFormat = internalFormat;
	this->pixelFormat = pixelFormat;
}

void Texture2D::Load(int Texture_Width, int Texture_Height, void* data)
{
	Bind();
	glTexParameteri(BindTarget, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(BindTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(BindTarget, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(BindTarget, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(BindTarget, 0, internalFormat, Texture_Width, Texture_Height, 0, pixelFormat, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(BindTarget);
	stbi_image_free(data);
	UnBind();
}