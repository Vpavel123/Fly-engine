#include "VBO.h"

VBO::VBO(int componentSize, GLenum usage = GL_STATIC_DRAW) : Buffer(GL_ARRAY_BUFFER, usage)
{
	ComponentSize = componentSize;
}