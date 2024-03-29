#include "Texture.h"
#include <iostream>

Texture::Texture()
{

}

Texture::Texture(GLenum target)
{
	BindTarget = target;
	glGenTextures(1, &ID);
}

Texture::~Texture()
{
	//glDeleteTextures(1, &ID);
}

void Texture::Bind()
{
	glBindTexture(BindTarget, ID);
}

void Texture::UnBind()
{
	glBindTexture(BindTarget, 0);
}

void Texture::Use(unsigned int unit)
{
	glActiveTexture(GL_TEXTURE0 + unit);
	Bind();
}

//	unsigned char* image = stbi_load(path.c_str(), &Texture_Width, &Texture_Height, &nrChannels, 4);
// 
//	//if (nrChannels == 3)
//	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Width, Texture_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//	//else if (nrChannels == 4)
//		//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Texture_Width, Texture_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, Texture_Width, Texture_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);