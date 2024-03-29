#pragma once
#include <vector>
#include "../Buffer/VAO.h"

class MeshUI
{
public:
	MeshUI();
	MeshUI(GLenum Usage);
	~MeshUI();
	std::vector<float> Position;
	std::vector<float> Color;
	std::vector<float> UV;
	std::vector<unsigned int> Indices;
	VAO vao;
	void Upload();
	void Draw();
};