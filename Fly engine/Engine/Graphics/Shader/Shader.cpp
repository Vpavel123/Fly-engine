#include <iostream>
#include <sstream>
#include <fstream>
#include "Shader.h"

Shader::Shader()
{

}

Shader::Shader(std::string name)
{
	ID = glCreateProgram();
}

Shader::~Shader()
{
	//glDeleteProgram(ID);
}

void Shader::Use()
{
	glUseProgram(ID);
}

void Shader::Reset()
{
	glUseProgram(0);
}

void Shader::Load(const char* vert, const char* frag)
{
	LoadShader(vert, GL_VERTEX_SHADER);
	LoadShader(frag, GL_FRAGMENT_SHADER);
	glLinkProgram(ID);
}

void Shader::LoadShader(const char* cstr, GLenum type)
{
	int id = glCreateShader(type);

	glShaderSource(id, 1, &cstr, NULL);
	glCompileShader(id);

	int compiled;
	glGetShaderiv(id, GL_COMPILE_STATUS, &compiled);
	if (compiled == GL_FALSE)
	{
		int log_length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &log_length);
		char* message = (char*)alloca(log_length * sizeof(char));
		glGetShaderInfoLog(id, log_length, &log_length, message);
		log->Error("Failed Shaders!");
		log->Error(message);
	}

	glAttachShader(ID, id);
}

void Shader::SetMatrix4(const std::string name, glm::mat4 model)
{
	int loc = glGetUniformLocation(ID, name.c_str());
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(model));
}

void Shader::SetUniform3f(std::string name, glm::vec3 lightPos)
{
	int loc = glGetUniformLocation(ID, name.c_str());
	glUniform3f(loc, lightPos.x, lightPos.y, lightPos.z);
}

void Shader::SetUniform3fv(std::string name, int count, const float* value)
{
	int loc = glGetUniformLocation(ID, name.c_str());
	glUniform3fv(loc, count, value);
}

void Shader::SetUniform1i(std::string name, int Points)
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), Points);
}

void Shader::SetTexture(Texture texture, unsigned int unit)
{
	assert(unit >= 0 && unit <= 31);

	if (unit == NULL) return;
	texture.Use(unit);
}