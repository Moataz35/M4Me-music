#pragma once

#include "Command.h"
#include "raylib.h"
#include "Rectangle.h"
#include <string>

namespace stu {

	class TextButton : public Rectangle {
	private:
		std::string text;
		int textX;
		int textY;
		int fontSize;
		Command* onClicked;

		// Helper function to center the text in the rectangle
		void centerText();

		// Helper function to check if number in range [start, end]
		template<typename T>
		bool inRange(T target, T start, T end);
	public:
		TextButton();

		TextButton(std::string buttonText);

		~TextButton();

		/*
			Set the right command to do on clicked
			Note: It should be a dynamic allocated memory for the command
		*/
		void setCommand(Command* toDo);

		// Draw the button on the window
		void draw(Color backgroundColor = WHITE, Color textColor = BLACK);

		// Change the position of the button
		void setPosition(int newX, int newY);
		
		// Return true if the button is pressed
		bool isPressed();
	};

}

