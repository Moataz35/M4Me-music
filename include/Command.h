#pragma once

#include "Song.h"

class Command {
public:
	/*
		Make the destructor virtual because if you try to delete a derived class through a base class pointer
		it will only call the base class destructor and that may lead to a memory leak
	*/
	virtual ~Command();
	virtual void execute();
	virtual void execute(float ratio);
};


//---------------------------------------------------------------------play song command

class PlayCommand : public Command{
private:
	stu::Song* musicTrack;
public:
	PlayCommand(stu::Song* track);
	void execute();
};

//---------------------------------------------------------------------pause song command

class PauseCommand : public Command{
private:
	stu::Song* musicTrack;
public:
	PauseCommand(stu::Song* track);
	void execute();
};

//---------------------------------------------------------------------Loading a audio file

class LoadCommand : public Command{
private:
	stu::Song* musicTrack;
public:
	LoadCommand(stu::Song* track);
	void execute();
};

//---------------------------------------------------------------------Change the audio volume

class changeVolumeCommand : public Command {
private:
	stu::Song* musicTrack;
public:
	changeVolumeCommand(stu::Song* track);
	void execute(float ratio);
};

//---------------------------------------------------------------------Change the audio playing point

class ChangePlayingPoint : public Command {
private:
	stu::Song* musicTrack;
public:
	ChangePlayingPoint(stu::Song* track);
	void execute(float ratio);
};