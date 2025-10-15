#pragma once

#include "Command.h"
#include "raylib.h"
#include "Rectangle.h"
#include "Song.h"

namespace stu {
	
	class ProgressBar {
	private:
		Rectangle baseRec;
		Rectangle progressRec;
		int x;
		int y;
		int width;
		int height;
		Command* onMoving;
	public:
		ProgressBar();

		ProgressBar(int x, int y, int width, int height);

		// Draw the progress bar on the window with the selected colors
		void draw(Color backgroundColor = GRAY, Color progressColor = RED);

		// Make the user to be able to move the sliding part
		void handleMovingPart();

		// Something to do when the user move the sliding part
		void setCommand(Command* toDo);

		// Set the progress according to a ratio = where we are now / the total length
		void setProgress(float progress);

		// Set the progress according to a real song
		void setProgress(stu::Song& musicTrack);

		// Change the positon to a new x and y
		void setPosition(int newX, int newY);

		// Change the size of the bar to a new width and height
		void setSize(int newWidth, int newHeight);
	};

}

