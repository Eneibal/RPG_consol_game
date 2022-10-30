#include "Event.h"


Event::Event()
{
	nr_of_events = 2;
}

Event::~Event()
{
}

void Event::gererate_event(Character & character_)
{
	int i = rand()%nr_of_events;
	switch (i)
	{
	case 0:
		//Enemy encounter
		enemy_encounter(character_);
		break;
	case 1:
		//puzzle
		puzzle_encounter(character_);
		break;
	case 2:
		break;
	default:
		break;
	}
}

//Different events
void Event::enemy_encounter(Character& character_)
{

}

void Event::puzzle_encounter(Character& character_)
{

}