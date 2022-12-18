#pragma once
#include"Character.h"
#include"Puzzle.h"
#include <stdlib.h>
#include"dArr.h"
enum BattleMenu
{
	ESCAPE=1,
	ATTACK,
	DEFEND,
	USEITEM,
};

class Event
{
private:
	BattleMenu get_battle_menu_choice();
	int nr_of_events;
public:
	Event();
	~Event();

	void gererate_event(Character& character_, dArr<Enemy>& enemies_);

	//Events
	void enemy_encounter(Character& character_, dArr<Enemy>& enemies_);
	void puzzle_encounter(Character& character_);
};

