#pragma once
#include <GLFW/glfw3.h>

class Screen
{
public:
	Screen();
	static GLFWwindow* window;
	static int width();
	void width(int _width);
	static int height();
	void height(int _height);
private:
	static int Width;
	static int Height;
};