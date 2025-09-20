#include "../include/Window.h"
#include "raylib.h"

Window::Window(int width, int height, std::string title) : width(width), height(height), title(title) {
	InitWindow(width, height, this->title.c_str());
}

Window::~Window() {
	CloseWindow();
}