#include "StandartMaterial.h"
#include "../../Scenes/Scene.h"

StandartMaterial::StandartMaterial(std::string findShader) : Material()
{
	Material::shader = Scene::content.shader.Resources[findShader];
}

StandartMaterial::StandartMaterial(std::string findShader, std::string findTexture) : Material()
{
	Material::shader = Scene::content.shader.Resources[findShader];
	texture = Scene::content.texture.Find<Texture2D>(findTexture); 
}

void StandartMaterial::LoadParams()
{
	texture.Use(0);
}