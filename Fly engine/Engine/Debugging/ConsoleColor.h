#pragma once
#include<Windows.h>

class ConsColor
{
public:
	enum DefaultColor : int
	{
		Red = 12,
		Green = 2,
		Blue = 3,
		Yellow = 6,
		White = 7,
		Black = 16,
		Gray = 8
	};
	ConsColor();
	~ConsColor();
	void set_color(int color);
	void clear();
	void clear_all();
private:
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
};

inline ConsColor::ConsColor()
{
}

inline ConsColor::~ConsColor()
{
	CloseHandle(hConsoleOutput);
}

inline void ConsColor::set_color(int color)
{
	SetConsoleTextAttribute(hConsoleOutput, color);
}

inline void ConsColor::clear() {
	SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

inline void ConsColor::clear_all() {
	system("color 7");
}