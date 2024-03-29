#include "TextureResource.h"

TextureResource::TextureResource()
{
}

TextureResource::TextureResource(AssetPool assetpool) : Resource<Texture>(assetpool)
{
	Directory = "\\Textures\\";
}