#pragma once
#include <vector>
#include "../../Graphics/Buffer/VAO.h"
#include "../../Systems/Components/Transform.h"

class Mesh
{
public:
	std::vector<float> Position;
	std::vector<float> Color;
	std::vector<float> Normaly;
	std::vector<float> UV;
	std::vector<unsigned int> Indices;
	VAO vao;
	Mesh();
	Mesh(GLenum Usage);
	~Mesh();
	void Upload();
	void Draw();
};