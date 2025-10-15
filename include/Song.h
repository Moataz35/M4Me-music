#pragma once

#include "raylib.h"
#include <string>

namespace stu {

	class Song {
	private:
		Music audio;
		std::string fileName;
		bool paused;
		float speed;
		bool isReadyToPlay;
	public:
		Song();
		~Song();

		// Change the song volume with a percent %
		void changeSongVolume(float volumePercent);

		// Change the point which song starts playing from
		void changePlayingPoint(float elapsedTimeRatio);

		// Get the time played from the song as a ratio
		float getProgress();

		// Get the total length of the song in seconds
		float getTotalLength();

		// Return the elapsed time in seconds
		float getElapsedTime();

		// Return the song name not the full path
		std::string getSongName();

		/*
			Return the state of the song
			true if the song is paused
			false if the song is playing
		*/
		bool isPaused();

		// Check if the audio is ready to play
		bool isReady();

		// Load the song from a file by providing its path
		bool loadFromFile(std::string fileName);

		/*
			Opens a file dialog to choose the song.
			It returns true if the song is successfully loaded.
		*/
		bool loadFromFile();

		// Play the song if it's paused
		void play();

		// Pause the song if it's playing
		void pause();

		// Set the playing speed from 1.0 to 2.0
		void setAudioSpeed(float audioSpeed);

		// Update the music stream with the new content
		void updateStream();
	};

}

