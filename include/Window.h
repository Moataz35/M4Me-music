#pragma once

#include <string>

class Window {
private:
	int width;
	int height;
	std::string title;
public:
	Window(int width, int height, std::string title);
	~Window();
};

