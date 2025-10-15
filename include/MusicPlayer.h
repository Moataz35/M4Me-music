#pragma once

#include "IconButton.h"
#include "ProgressBar.h"
#include "raylib.h"
#include "Slider.h"
#include "Song.h"
#include "TextButton.h"
#include "Window.h"
#include <iostream>

class MusicPlayer {
private:
	Window mainWindow;
	int songLength = 0;
	int elapsedTime = 0;  // In seconds
	stu::Song musicTrack;
	std::string songName;
	std::string progressInNumbers;
	stu::IconButton playButton;
	stu::IconButton pauseButton;
	stu::IconButton volumeButton;
	stu::TextButton changeSongButton;
	stu::ProgressBar songProgressBar;
	Slider volumeSlider;

	// Commands
	PlayCommand* playCommand;
	PauseCommand* pauseCommand;
	LoadCommand* loadCommand;
	changeVolumeCommand* changeVolume;
	ChangePlayingPoint* changePlayingPoint;

	// Used colors in the application
	Color textColor = { 228, 24, 78, 255 };
	Color appBackground = { 36, 36, 36, 255 };
	Color buttonColor = { 155, 93, 229, 255 };
	Color progressColor = { 155, 93, 229, 255 };
	Color ProgressBarBackground = { 170, 170, 170, 255 };

	// Window properties
	static constexpr int screenWidth = 800;
	static constexpr int screenHeight = 500;

	// Progress bar properties
	static constexpr int progressBarWidth = 350;
	static constexpr int progressBarHeight = 15;
	static constexpr int progressBarX = screenWidth / 2 - progressBarWidth / 2;
	static constexpr int progressBarY = 300;

	// Icon buttons
	static constexpr int iconButtonDiameter = 50;

	// Text buttons
	static constexpr int buttonWidth = 150;
	static constexpr int buttonHeight = 25;

	static constexpr int fontSize = 20;

	// Slider
	static constexpr int sliderX = 170;
	static constexpr int sliderY = 170;


	void updateStates();

	void eventHandling();

	void drawing();

public:
	MusicPlayer(std::string appName);
	~MusicPlayer();
	void run();
};

