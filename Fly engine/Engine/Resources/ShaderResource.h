#pragma once
#include "Resource.h"
#include <sstream>
#include <fstream>
#include "../Graphics/Shader/Shader.h"

class ShaderResource : public Resource<Shader>
{
public:
	std::string VERT_EXT = ".vert";
	std::string FRAG_EXT = ".frag";
	ShaderResource();
	ShaderResource(AssetPool assetpool);
	virtual void Load(std::string name) override;
};

inline std::string LoadShader(std::string path)
{
	std::ifstream file(path);
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string str(buffer.str());
	return str;
}

inline void ShaderResource::Load(std::string name)
{
	std::string vertPath = Root + Directory + name + VERT_EXT;
	std::string fragPath = Root + Directory + name + FRAG_EXT;
	Shader shader = Shader(name);
	shader.Load(LoadShader("..\\Fly engine\\" + vertPath).c_str(), LoadShader("..\\Fly engine\\" + fragPath).c_str());
	Resource::Resources.insert(std::pair<std::string, Shader>(name, shader));
	Resource::Load(name);
}

