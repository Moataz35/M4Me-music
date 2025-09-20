#pragma once

#include "../include/Song.h"

class Command {
public:
	/*
		Make the destructor virtual because if you try to delete a derived class through a base class pointer
		it will only call the base class destructor and that may lead to a memory leak
	*/
	virtual ~Command();
	virtual void execute();
};

class PlayCommand : public Command{
private:
	stu::Song* musicTrack;
public:
	PlayCommand(stu::Song* track);
	void execute();
};

class PauseCommand : public Command{
private:
	stu::Song* musicTrack;
public:
	PauseCommand(stu::Song* track);
	void execute();
};

class LoadCommand : public Command{
private:
	stu::Song* musicTrack;
public:
	LoadCommand(stu::Song* track);
	void execute();
};

