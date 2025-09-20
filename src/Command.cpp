#include "../include/Command.h"
#include "../include/Song.h"
#include <iostream>

Command::~Command() {}

void Command::execute() {}

/*------------------------------------------------------------------*/

PlayCommand::PlayCommand(stu::Song* track) : musicTrack(track) {}

void PlayCommand::execute() {
	if (!musicTrack) return;

	if (musicTrack->isPaused()) {
		musicTrack->play();
	}
}

/*------------------------------------------------------------------*/

PauseCommand::PauseCommand(stu::Song* track) : musicTrack(track) {}

void PauseCommand::execute() {
	if (!musicTrack) return;

	if (!musicTrack->isPaused()) {
		musicTrack->pause();
	}
}

/*------------------------------------------------------------------*/

LoadCommand::LoadCommand(stu::Song* track) : musicTrack(track) {}

void LoadCommand::execute() {
	if (!musicTrack) return;

	musicTrack->loadFromFile();
}