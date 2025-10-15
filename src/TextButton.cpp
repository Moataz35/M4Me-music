#include "TextButton.h"
#include "raylib.h"
#include "Rectangle.h"
#include <string>


void stu::TextButton::centerText() {
	// Make the text fit in the rectangle
	while (MeasureText(text.c_str(), fontSize) >= width) {
		fontSize--;
	}

	int textWidth = MeasureText(text.c_str(), fontSize);

	textX = x + (width - textWidth) / 2;
	textY = y + (height - fontSize) / 2;   // Consider the height equal to the font size
}

template<typename T>
bool stu::TextButton::inRange(T target, T start, T end) {
	if (target >= start && target <= end) {
		return true;
	}
	return false;
}

stu::TextButton::TextButton() : Rectangle(0, 0, 150, 25) {
	text = "Push button";
	textX = textY = 0;
	fontSize = 20;
	centerText();
}

stu::TextButton::TextButton(std::string buttonText) : Rectangle(0, 0, 150, 25) {
	text = buttonText;
	textX = textY = 0;
	fontSize = 20;
	centerText();
}

void stu::TextButton::setCommand(Command* toDo) {
	onClicked = toDo;
}

void stu::TextButton::draw(Color backgroundColor, Color textColor) {
	stu::Rectangle::draw(backgroundColor);
	DrawText(text.c_str(), textX, textY, fontSize, textColor);
}

void stu::TextButton::setPosition(int newX, int newY) {
	stu::Rectangle::setPosition(newX, newY);
	centerText();
}

bool stu::TextButton::isPressed() {
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

void stu::TextButton::handleButtonClick() {
	if (isPressed() && onClicked != nullptr) {
		onClicked->execute();
	}
}