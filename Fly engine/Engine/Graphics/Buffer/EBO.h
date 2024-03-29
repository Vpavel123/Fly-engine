#pragma once
#include "Buffer.h"

class EBO : public Buffer
{
public:
	EBO();
	EBO(GLenum usage);
};