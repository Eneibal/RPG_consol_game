#pragma once
#include"Character.h"
#include"Puzzle.h"
#include <stdlib.h>
#include"dArr.h"

class Event
{
private:
	int nr_of_events;
public:
	Event();
	~Event();

	void gererate_event(Character& character_, dArr<Enemy>& enemies_);

	//Events
	void enemy_encounter(Character& character_, dArr<Enemy>& enemies_);
	void puzzle_encounter(Character& character_);
};

