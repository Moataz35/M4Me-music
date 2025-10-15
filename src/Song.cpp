#include "raylib.h"
#include "tinyfiledialogs.h"
#include "Song.h"
#include <iostream>
#include <string>

stu::Song::Song() : audio() {
	fileName = "";
	paused = true;
	speed = 1.0f;
	isReadyToPlay = false;
	InitAudioDevice();
}

stu::Song::~Song() {
	// Unload music stream buffers from RAM
	UnloadMusicStream(audio);

	// Close audio device (music streaming is automatically stopped)
	CloseAudioDevice();
}

void stu::Song::changeSongVolume(float volumePercent) {
	SetMusicVolume(audio, volumePercent);
}

void stu::Song::changePlayingPoint(float elapsedTimeRatio) {
	float elapsedTime = elapsedTimeRatio * getTotalLength();
	SeekMusicStream(audio, elapsedTime);
}

float stu::Song::getProgress() {
	// Believe me you don't want to divide by zero
	if (getTotalLength() == 0) return 0;
	return getElapsedTime() / getTotalLength();
}

float stu::Song::getTotalLength() {
	if (!isReadyToPlay) return 0;

	float musicLength = GetMusicTimeLength(audio); 

	return musicLength > 0 ? musicLength : 0;
}


float stu::Song::getElapsedTime() {
	if (!isReadyToPlay) return 0;

	float timePlayed = GetMusicTimePlayed(audio); // Throwing exception integer dividing by zero

	return timePlayed > 0 ? timePlayed : 0;
}

std::string stu::Song::getSongName() {
	std::string reversedName = "";
	for (int i = fileName.length() - 1; i >= 0; i--) {
		if (fileName[i] == '/' || fileName[i] == '\\') break;
		reversedName += fileName[i];
	}

	std::string songName = "";
	for (int i = reversedName.length() - 1; i >= 0; i--) {
		songName += reversedName[i];
	}
	return songName;
}

bool stu::Song::isPaused() {
	return paused;
}

bool stu::Song::isReady() {
	return isReadyToPlay;
}

bool stu::Song::loadFromFile(std::string fileName) {
	// If there is already a loaded audio unload it first
	UnloadMusicStream(audio);

	this->fileName = fileName;
	audio = LoadMusicStream(
				this->fileName.c_str()
			);

	if (!IsMusicValid(audio)) {
		return false;
	}

	std::cout << "Valid audio\n";
	PlayMusicStream(audio);
	return true;
}

bool stu::Song::loadFromFile() {

	const char* supportedFormats[3] = {"*.mp3", "*.ogg", "*.wav"};  // const char** -> Pointer (char*) to array of (const char*) or C-strings
	const char* filePath = tinyfd_openFileDialog(
								"Choose a song",
								NULL,
								3,
								supportedFormats,
								"Audio files",
								0
							);

	if (filePath == NULL) {
		return false;
	}

	fileName = filePath;
	audio = LoadMusicStream(
				fileName.c_str()
			);

	if (!IsMusicValid(audio)) {
		return false;
	}

	isReadyToPlay = true;
	paused = false;
	PlayMusicStream(audio);
	return true;
}

void stu::Song::play() {
	paused = false;
	ResumeMusicStream(audio);
}

void stu::Song::pause() {
	paused = true;
	PauseMusicStream(audio);
}

void stu::Song::setAudioSpeed(float audioSpeed) {
	// Keep the speed between 1.0 and 2.0
	if (audioSpeed < 1.0f) {
		audioSpeed = 1.0f;
	}
	else if (audioSpeed > 2.0f) {
		audioSpeed = 2.0f;
	}
	speed = audioSpeed;
	SetMusicPitch(audio, audioSpeed);
}

void stu::Song::updateStream() {
	// Note: It's important to update the music stream every frame
	if (isReadyToPlay) {
		UpdateMusicStream(audio);
	}
}