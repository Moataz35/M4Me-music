#include "../include/IconButton.h"
#include "raylib.h"
#include <string>

stu::IconButton::IconButton(std::string fileName) {
	iconFileName = fileName;
	icon = LoadTexture(iconFileName.c_str());
	x = y = 0;
	end_x = x + icon.width;
	end_y = y + icon.height;
}

stu::IconButton::~IconButton() {
	UnloadTexture(icon);
}

template<typename T>
bool stu::IconButton::inRange(T target, T start, T end) {
	if (target >= start && target <= end) {
		return true;
	}
	return false;
}

void stu::IconButton::setCommand(Command* toDo) {
	onClicked = toDo;
}

void stu::IconButton::draw() {
	DrawTexture(icon, x, y, WHITE);
}

bool stu::IconButton::isPressed() {
	int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();

	if (inRange(mouse_x, x, end_x) && inRange(mouse_y, y, end_y)) {
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			return true;
		}
		return false;
	}
	return false;
}

void stu::IconButton::handleButtonClick() {
	if (isPressed() && onClicked != nullptr) {
		onClicked->execute();
	}
}

bool stu::IconButton::loadIconFromFile(std::string fileName) {
	// First if there is already an icon loaded we will unload it
	UnloadTexture(icon);

	iconFileName = fileName;
	icon = LoadTexture(iconFileName.c_str());

	if (!IsTextureValid(icon)) {
		return false;    // Failed to load the image
	}

	// Update the end point with the new icon dimensions
	end_x = x + icon.width;
	end_y = y + icon.height;

	return true;
}

void stu::IconButton::setPosition(int newX, int newY) {
	x = newX;
	y = newY;
	end_x = x + icon.width;
	end_y = y + icon.height;
}