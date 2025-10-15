#pragma once

#include "raylib.h"
#include <utility>

namespace stu {

	class Rectangle	{
	protected:
		int x;
		int y;
		int end_x;
		int end_y;
		int width;
		int height;
	public:
		Rectangle();

		Rectangle(int x, int y, int width, int height);

		// Check if a point is in the rectangle boundaries
		bool contain(int posX, int posY);

		// Draw a rectangle with the selected color on the window
		void draw(Color backgroundColor = BLACK);

		// Return the position of the the Rectangle
		std::pair<int, int> getPosition();

		// Return the size of the Rectangle
		std::pair<int, int> getSize();

		// Change the position of the rectangle to (newX, newY)
		void setPosition(int newX, int newY);

		// Change the size of the rectangle to a new width and a new height
		void setSize(int newWidth, int newHeight);
	};

}

