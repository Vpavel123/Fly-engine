#pragma once
#include "Material.h"
#include "..//Texture/Texture2D.h"

class StandartMaterial : public Material
{
public:
	Texture2D texture;
	// Implementation of output of shader materials
	StandartMaterial(std::string findShader);
	// Implementation of output of texture and shader materials
	StandartMaterial(std::string findShader, std::string findTexture);
	void LoadParams() override;
};