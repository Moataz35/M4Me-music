#pragma once


#include "Command.h"
#include "raylib.h"
#include "Rectangle.h"

class Slider {
private:
	stu::Rectangle base;
	stu::Rectangle sliderPart;
	Command *onSliderMove;
	bool visible;
public:
	Slider();

	Slider(int x, int y, int width, int height);

	void setCommand(Command *toDo);

	void setVisibility(bool state);

	bool isVisible();

	// Draw the Slider on the window
	void draw(Color backgroundColor = GRAY, Color sliderColor = BLACK);

	// Do something When the user move the slider
	void handleSliderMove();

	// Set the new position of the slider
	void setPosition(int newX, int newY);
};