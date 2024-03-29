#pragma once
#include "../Shader/Shader.h"

class Material
{
protected:
	Material();
public:
	Shader shader;
	virtual void LoadParams() = 0;
};