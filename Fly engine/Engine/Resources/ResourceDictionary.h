#pragma once
#include "../Resources/ShaderResource.h"
#include "../Resources/TextureResource.h"

class ResourceDictionary
{
public:
	ShaderResource shader;
	TextureResource texture;
	AssetPool asset;
	ResourceDictionary();
};