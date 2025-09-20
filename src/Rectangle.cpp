#include "../include/Rectangle.h"
#include "raylib.h"

stu::Rectangle::Rectangle() {
	x = y = 0;
	width = height = 50;
	end_x = x + width;
	end_y = y + height;
}

stu::Rectangle::Rectangle(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	end_x = x + width;
	end_y = y + height;
}

void stu::Rectangle::draw(Color backgroundColor) {
	::Rectangle roundedRectangle = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height)};
	DrawRectangleRounded(roundedRectangle, 2.0f, 0, backgroundColor);
	//DrawRectangle(x, y, width, height, backgroundColor);
}

void stu::Rectangle::setPosition(int newX, int newY) {
	x = newX;
	y = newY;
	end_x = x + width;
	end_y = y + height;
}

void stu::Rectangle::setSize(int newWidth, int newHeight) {
	width = newWidth;
	height = newHeight;
	end_x = x + width;
	end_y = y + height;
}