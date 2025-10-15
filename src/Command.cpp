#include "Command.h"
#include "Song.h"
#include <iostream>

Command::~Command() {}

void Command::execute() {}

void Command::execute(float ratio) {}

/*------------------------------------------------------------------*/

PlayCommand::PlayCommand(stu::Song* track) : musicTrack(track) {}

void PlayCommand::execute() {
	if (!musicTrack) return;

	if (musicTrack->isPaused()) {
		musicTrack->play();
	}
}

/*--------------------------------------------------------------------------------Pause command*/

PauseCommand::PauseCommand(stu::Song* track) : musicTrack(track) {}

void PauseCommand::execute() {
	if (!musicTrack) return;

	if (!musicTrack->isPaused()) {
		musicTrack->pause();
	}
}

/*---------------------------------------------------------------------------------Load music track command*/

LoadCommand::LoadCommand(stu::Song* track) : musicTrack(track) {}

void LoadCommand::execute() {
	if (!musicTrack) return;

	musicTrack->loadFromFile();
}

/*----------------------------------------------------------------------------------Changing the volume*/

changeVolumeCommand::changeVolumeCommand(stu::Song* track) : musicTrack(track) {}

void changeVolumeCommand::execute(float ratio) {
	if (!musicTrack) return;

	musicTrack->changeSongVolume(ratio);
}

//-------------------------------------------------------------------------------------

ChangePlayingPoint::ChangePlayingPoint(stu::Song* track) : musicTrack(track) {}

void ChangePlayingPoint::execute(float ratio) {
	if (musicTrack != nullptr && musicTrack->isReady()) {
		musicTrack->changePlayingPoint(ratio);
	}
}

