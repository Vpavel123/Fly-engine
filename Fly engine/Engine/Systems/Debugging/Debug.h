#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Debug
{
public:
	static void Error(std::string message, GLenum error);
	static void Warning(std::string message, GLenum error);
	static void Information(std::string message, GLenum error);
	static void Msg(std::string message, std::string color, std::string name, GLenum error);
};