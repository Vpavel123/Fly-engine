#pragma once
#include "ILogger.h"

class Logger : public ILogger 
{
public:
	static Logger* getInstance()
	{
		if (instance == nullptr)
		{
			instance = new Logger();
		}
		return instance;
	}
private:
	Logger() : ILogger()
	{
	}

    Logger(Logger const&) = delete;             // Copy construct
    Logger(Logger&&) = delete;                  // Move construct
    Logger& operator=(Logger const&) = delete;  // Copy assign
    Logger& operator=(Logger&&) = delete;      // Move assign

	static Logger* instance;
};