#include <stdlib.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Debug.h"

void Debug::Error(std::string message, GLenum error)
{
	Msg(message, "0C", "Error", error);
}

void Debug::Warning(std::string message, GLenum error)
{
	Msg(message, "0F", "Warning", error);
}

void Debug::Information(std::string message, GLenum error)
{
	Msg(message, "0E", "Information", error);
}

void Debug::Msg(std::string message, std::string color, std::string name, GLenum error)
{
	color = "Color " + color;
	system(color.c_str());
	std::cout << "Time(): " << " [" + name + "] " << message + " - " << error<< std::endl;
}

//std::string Time()
//{
//	time_t rawtime;
//	struct tm* timeinfo;
//	time(&rawtime);
//	timeinfo = localtime(&rawtime);
//	return asctime(timeinfo);
//}