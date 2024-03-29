#include "Buffer.h"

Buffer::Buffer(GLenum Target, GLenum Usage)
{
	glGenBuffers(1, &ID);
	target = Target;
	usage = Usage;
}

void Buffer::Bind()
{
	glBindBuffer(target, ID);
}

void Buffer::UnBind()
{
	glBindBuffer(target, 0);
}