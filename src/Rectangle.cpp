#include "Rectangle.h"
#include "raylib.h"

stu::Rectangle::Rectangle() {
	x = y = 0;
	width = height = 50;
}

stu::Rectangle::Rectangle(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void stu::Rectangle::draw(Color backgroundColor) {
	DrawRectangle(x, y, width, height, backgroundColor);
}

void stu::Rectangle::setPosition(int newX, int newY) {
	x = newX;
	y = newY;
}

void stu::Rectangle::setSize(int newWidth, int newHeight) {
	width = newWidth;
	height = newHeight;
}