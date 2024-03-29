#include "ShaderResource.h"

ShaderResource::ShaderResource()
{

}

ShaderResource::ShaderResource(AssetPool assetpool) : Resource<Shader>(assetpool)
{
	Directory = "\\Shaders\\";
}