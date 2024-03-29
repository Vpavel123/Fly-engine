#pragma warning(disable : 4996)
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <format>
#include "ConsoleColor.h"

class ILogger
{
public:
	ConsColor cons = ConsColor();
	std::string TimeLog();
	void Error(std::string message);
	void Warning(std::string message);
	void Information(std::string message);
	void Msg(std::string message, int color, std::string name);
	template<class T>
	void Msg(std::string message, int color, std::string name, T object);
};

inline std::string ILogger::TimeLog()
{
	time_t mytime = time(NULL);
	struct tm* now = localtime(&mytime);
	return std::format("{0:}:{1:}:{2:} - {3:}:{4:}:{5:}", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900, now->tm_hour, now->tm_min, now->tm_sec);
}

inline void ILogger::Error(std::string message)
{
	Msg(message, cons.Red, "Error");
}

inline void ILogger::Warning(std::string message)
{
	Msg(message, cons.Yellow, "Warning");
}

inline void ILogger::Information(std::string message)
{
	Msg(message, cons.White, "Information");
}

inline void ILogger::Msg(std::string message, int color, std::string name)
{
	cons.set_color(color);
	std::cout << TimeLog() << " [" + name + "] " << message << std::endl;
}

template<class T>
inline void ILogger::Msg(std::string message, int color, std::string name, T object)
{
	cons.set_color(color);
	std::cout << TimeLog() << " [" + name + "] " << message + " - " << object << std::endl;
}

