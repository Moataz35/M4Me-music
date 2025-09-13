#pragma once

#include "raylib.h"
#include <string>

namespace stu {

	class IconButton {
	private:
		Texture2D icon;
		std::string iconFileName;
		int x;
		int y;
		int end_x;
		int end_y;

		// Helper function to check if number in range [start, end]
		template<typename T>
		bool inRange(T target, T start, T end);
	public:
		IconButton(std::string fileName);

		~IconButton();

		// Draw the button on the window (that you call this method inside its drawing area in its main loop)
		void draw();

		// Check if the button is pressed
		bool isPressed();

		// Load an icon by providing its path
		bool loadIconFromFile(std::string fileName);

		// Change the position of the button
		void setPosition(int newX, int newY);
	};

}

