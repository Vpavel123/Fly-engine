#pragma once
#include <string>
#include "stb_image.h"
#include "Resource.h"
#include "../Graphics/Texture/Texture2D.h"
#include "../Debugging/Logger.h"
#include <format>

class TextureResource : public Resource<Texture>
{
public:
	Logger* log = Logger::getInstance();
	int Texture_Width, Texture_Height, nrChannels = 0;
	unsigned char* image;
	std::string ext = ".png";
	TextureResource();
	TextureResource(AssetPool assetpool);
	template<class T>
	T Find(std::string name);
	virtual void Load(std::string name) override;
};

inline void TextureResource::Load(std::string name)
{
	std::string Path = Root + Directory + name;

	if(Path.substr(Path.length() - 3, 3) == "png")
	{
		image = stbi_load(("..\\Fly engine\\" + Path).c_str(), &Texture_Width, &Texture_Height, &nrChannels, 4);
	}
	else if(Path.substr(Path.length() - 3, 3) == "jpg")
	{
		image = stbi_load(("..\\Fly engine\\" + Path).c_str(), &Texture_Width, &Texture_Height, &nrChannels, 0);
	}

	Texture2D texture = Texture2D(GL_RGBA, GL_RGBA); //<-- GL_RGB GL_RGB для jpg
	stbi_set_flip_vertically_on_load(1);
	image = stbi_load(("..\\Fly engine\\" + Path).c_str(), &Texture_Width, &Texture_Height, &nrChannels, 4);  //<-- 0 для jpg

	if (image == NULL) {
		log->Warning(std::format("can't, load texture from {0:} - {1:}",("..\\Fly engine\\" + Path).c_str(), stbi_failure_reason()));
	}
	else
	{
		log->Warning(std::format("Width {0:}, Height {1:}, nrChannels {2:}", Texture_Width, Texture_Height, nrChannels));
	}

	texture.Load(Texture_Width, Texture_Height, image);
	Resource::Resources.insert(std::pair<std::string, Texture>(name, texture));
	Resource::Load(name);
}

template<class T>
inline T TextureResource::Find(std::string name)
{
	//static_assert(std::is_same<T, Texture>::value, "template instantiation of Class are not Texture");
	T t;
	Texture& texture = t; // <--- The heir implicitly knows how to travel to the base class
	texture = Resource::Find(name);
	T& obj = static_cast<T&>(texture); // <--- Now we bring it back
	return obj;
}