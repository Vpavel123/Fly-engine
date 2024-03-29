#include "Screen.h"

Screen::Screen()
{

}

int Screen::width()
{
	return Width;
}

void Screen::width(int _width)
{
	Width = _width;
}

int Screen::height()
{
	return Height;
}

void Screen::height(int _height)
{
	Height = _height;
}

int Screen::Height;
int Screen::Width;
GLFWwindow* Screen::window;