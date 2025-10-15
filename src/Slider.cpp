#include "Slider.h"

Slider::Slider() : base(0, 0, 20, 100), sliderPart(0, 80, 20, 20) { 
	/*
		At first the slider is 20% of the base.
		To calculate the position of the slider part -> basePosY + baseHeight - sliderPartHeight
	*/
	visible = false;
}

Slider::Slider(int x, int y, int width, int height) : base(x, y, width, height), sliderPart(x, y + height - 0.2f * height, width, height) {}

void Slider::setCommand(Command* toDo) {
	onSliderMove = toDo;
}

void Slider::setVisibility(bool state) {
	visible = state;
}

bool Slider::isVisible() {
	return visible;
}

void Slider::draw(Color backgroundColor, Color sliderColor) {
	if (visible) {
		base.draw(backgroundColor);
		sliderPart.draw(sliderColor);
	}
}

void Slider::handleSliderMove() {
	if (!visible) return;

	int mousePosX = GetMouseX();
	int mousePosY = GetMouseY();

	if (base.contain(mousePosX, mousePosY)) {

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {

			// Set the new position of the silder to the mouse y position
			sliderPart.setPosition(
				sliderPart.getPosition().first,
				mousePosY
			);

			// Change the size of the slider to the new size
			sliderPart.setSize(
				sliderPart.getSize().first,
				base.getSize().second - (mousePosY - base.getPosition().second)
			);

			float percent = (float)sliderPart.getSize().second / base.getSize().second;

			if (onSliderMove != nullptr) {
				onSliderMove->execute(percent);
			}
		}
	}
}



void Slider::setPosition(int newX, int newY) {
	base.setPosition(newX, newY);
	int newSliderY = newY + (base.getSize().second - sliderPart.getSize().second);
	sliderPart.setPosition(newX, newSliderY);
}