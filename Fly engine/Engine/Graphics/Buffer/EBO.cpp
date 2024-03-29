#include "EBO.h"

EBO::EBO() : Buffer(target, usage)
{
}

EBO::EBO(GLenum usage = GL_STATIC_DRAW) : Buffer(GL_ELEMENT_ARRAY_BUFFER, usage)
{
}