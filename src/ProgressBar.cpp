#include "ProgressBar.h"
#include "raylib.h"
#include "Rectangle.h"

stu::ProgressBar::ProgressBar() : baseRec(0, 0, 150, 15), progressRec(0, 0, 0, 15) {
	x = y = 0;
	width = 150;
	height = 15;
}

stu::ProgressBar::ProgressBar(int x, int y, int width, int height) : baseRec(x, y, width, height), progressRec(x, y, 0, height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void stu::ProgressBar::draw(Color backgroundColor, Color progressColor) {
	baseRec.draw(backgroundColor);
	progressRec.draw(progressColor);
}

void stu::ProgressBar::setProgress(float progress) {
	// Time in seconds played from the song relative to the song total lenght is equal to the width of the progress rectangle relative to the base
	int progressNewWidth = static_cast<int>(progress * width);
	progressRec.setSize(progressNewWidth, height);
}

void stu::ProgressBar::setProgress(stu::Song& musicTrack) {
	float progress = musicTrack.getTotalLength() ? musicTrack.getElapsedTime() / musicTrack.getTotalLength() : 0.0f;
	int progressNewWidth = static_cast<int>(progress * width);
	progressRec.setSize(progressNewWidth, height);
}

void stu::ProgressBar::setPosition(int newX, int newY) {
	baseRec.setPosition(newX, newY);
	progressRec.setPosition(newX, newY);
}

void stu::ProgressBar::setSize(int newWidth, int newHeight) {
	baseRec.setSize(newWidth, newHeight);
	progressRec.setSize(0, newHeight);
}