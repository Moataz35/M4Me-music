#pragma once

#include "raylib.h"

namespace stu {

	class Rectangle	{
	private:
		int x;
		int y;
		int width;
		int height;
	public:
		Rectangle();

		Rectangle(int x, int y, int width, int height);

		// Draw a rectangle with the selected color on the window
		void draw(Color backgroundColor = BLACK);

		// Change the position of the rectangle to (newX, newY)
		void setPosition(int newX, int newY);

		// Change the size of the rectangle to a new width and a new height
		void setSize(int newWidth, int newHeight);
	};

}

