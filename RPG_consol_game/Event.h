#pragma once
#include"Character.h"
#include"Puzzle.h"
#include <stdlib.h>

class Event
{
private:
	int nr_of_events;
public:
	Event();
	~Event();

	void gererate_event(Character& character_);

	//Events
	void enemy_encounter(Character& character_);
	void puzzle_encounter(Character& character_);
};

