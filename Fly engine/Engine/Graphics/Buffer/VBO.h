#pragma once
#include "Buffer.h"

class VBO : public Buffer
{
public:
	int ComponentSize;
	VBO(int componentSize, GLenum usage);
};