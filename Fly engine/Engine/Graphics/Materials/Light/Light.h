#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../../Systems/Components/MeshRenderer.h"

class Light
{
public:
	std::vector<glm::vec3> vecLightNormal;
	std::vector<glm::vec3> vecLightPos;
	struct MeshRenderer* meshRenderer;
	// Light attributes
	glm::vec3 lightPos = glm::vec3(1.2f, 1.0f, 2.0f);
	//struct lightRetraising {
	//public:
	//	glm::vec3 diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
	//	glm::vec3 ambient = glm::vec3(1.0f, 1.0f, 1.0f);
	//	glm::vec3 specular = glm::vec3(1.0f, 1.0f, 1.0f);
	//};
	Light();
	~Light();

	glm::vec3 GetDiffuse(MeshRenderer* meshRenderer);
	glm::vec3 GetAmbient();
	glm::vec3 GetSpecular();
	glm::vec3 GetLight();
private:
	glm::vec3 normal;
	glm::vec3 lightDir;

	float diff;
	float ambientStrength = 0.1f;
	glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
};