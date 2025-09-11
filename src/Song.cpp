#include "raylib.h"
#include "tinyfiledialogs.h"
#include "Song.h"

stu::Song::Song() : audio() {
	fileName = "";
	paused = false;
	speed = 1.0f;
	InitAudioDevice();
}

stu::Song::~Song() {
	// Unload music stream buffers from RAM
	UnloadMusicStream(audio);

	// Close audio device (music streaming is automatically stopped)
	CloseAudioDevice();
}

float stu::Song::getProgress() {
	// Believe me you don't want to divide by zero
	if (GetMusicTimeLength(audio) == 0) return 0;
	return GetMusicTimePlayed(audio) / GetMusicTimeLength(audio);
}

bool stu::Song::isPaused() {
	return paused;
}

bool stu::Song::loadFromFile(std::string fileName) {
	this->fileName = fileName;
	audio = LoadMusicStream(
				this->fileName.c_str()
			);

	if (!IsMusicValid(audio)) {
		return false;
	}
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
	audio = LoadMusicStream(filePath);

	if (!IsMusicValid(audio)) {
		return false;
	}
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
	UpdateMusicStream(audio);
}