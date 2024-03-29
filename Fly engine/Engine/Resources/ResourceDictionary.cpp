#include "ResourceDictionary.h"

ResourceDictionary::ResourceDictionary()
{
	asset = AssetPool();
	shader = ShaderResource(asset);
	texture = TextureResource(asset);
}