#include "Event.h"


Event::Event()
{
	nr_of_events = 2;
}

Event::~Event()
{
}

void Event::gererate_event(Character & character_, dArr<Enemy>& enemies )
{
	int i = rand() % nr_of_events;
	switch (i)
	{
	case 0:
		//Enemy encounter
		enemy_encounter(character_,enemies);
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
void Event::enemy_encounter(Character& character_, dArr<Enemy>& enemies_)
{
	bool escape = false;
	bool playerDefeated = false;
	bool enemyDefeated = false;
	while (!escape && !playerDefeated && !enemyDefeated)
	{

	}
}

void Event::puzzle_encounter(Character& character_)
{
	//cin.ignore();
	bool completed = false;
	int user_ans = 0;
	int chances = 3;
	int gein_exp = (chances * character_.get_level() * (rand() % 10 + 1));
	Puzzle puzzle("Puzzles/1.txt");

	while (!completed && chances > 0)
	{
		cout << "Chances: " << chances << "\n\n";
		chances--;		
		cout << puzzle.get_as_string() << endl;

		cout << "\nYour ANSWER: " << endl;
		cin >> user_ans;
		
		while (cin.fail())//check cin
		{
			cout << "Faulty input!" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cout << endl << "\nYour ANSWER: ";
			cin >> user_ans;
		}
		cin.ignore(100, '\n');
		cout << endl;


		if (puzzle.get_correct_ans() == user_ans)
		{
			completed = true;
			character_.gain_exp(gein_exp);
			cout << "YOU GAUNED " << gein_exp << " EXP!\n\n";
		}
		
	}
	if (completed)
	{
		cout << "COngratz you succeded!!\n\n" << endl;
	}
	else
	{
		cout << "You FAILED BRAH!\n\n" << endl;
	}
}