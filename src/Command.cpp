#include "Command.h"


Command::~Command() {}

void PlayCommand::execute() {
	if (!musicTrack) return;

	if (musicTrack->isPaused()) {
		musicTrack->play();
	}
}

void PauseCommand::execute() {
	if (!musicTrack) return;

	if (!musicTrack->isPaused()) {
		musicTrack->pause();
	}
}

void LoadCommand::execute() {
	if (!musicTrack) return;

	musicTrack->loadFromFile();
}