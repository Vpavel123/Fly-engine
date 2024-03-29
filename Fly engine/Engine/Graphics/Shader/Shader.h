#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include "../Texture/Texture.h"
#include "../../Debugging/Logger.h"

class Shader
{
public:
	Logger* log = Logger::getInstance();
	unsigned int ID;
	std::string Path;
	Shader();
	Shader(std::string name);
	~Shader();
	void Use();
	void Reset();
	void Load(const char* vert, const char* frag);
	void LoadShader(const char* cstr, GLenum type);
	void SetMatrix4(const std::string name, glm::mat4 model);
	void SetUniform3f(std::string name, glm::vec3 lightPos);
	void SetUniform3fv(std::string name, int count, const float *value);
	void SetUniform1i(std::string name, int Points);
	void SetTexture(Texture texture, unsigned int unit);
};