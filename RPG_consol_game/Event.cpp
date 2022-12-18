#include "Event.h"

BattleMenu Event::get_battle_menu_choice()
{
	int choice = 0;

	cout << " = BAttle menu = \n\n";

	cout << "\n" << (int)BattleMenu::ESCAPE << ". Escape" << endl;
	cout << "\n" << (int)BattleMenu::ATTACK << ". Attack" << endl;
	cout << "\n" << (int)BattleMenu::DEFEND << ". Defend" << endl;
	cout << "\n" << (int)BattleMenu::USEITEM << ". Use item" << endl;

	cout << "\n\n" << "Choice: ";
	cin >> choice;

	while (cin.fail() || choice > 4 || choice < 0)//check cin
	{
		cout << "Faulty input!" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << endl << "Choice ";
		cin >> choice;
	}

	cin.ignore(100, '\n');
	cout << endl;

	return static_cast<BattleMenu>(choice);
}

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
	bool playerTurn = false;
	int choice = 0;
	//Coin toss for turn
	int coinToss = rand() % 2 + 1;
	if (coinToss ==1)
	{
		playerTurn = true;
	}
	else
	{
		playerTurn = false;
	}
	//End conditions
	bool escape = false;
	bool playerDefeated = false;
	bool enemyDefeated = false;

	//Enemies
	int nrOfEnemies = rand() % 5+1;

	for (size_t i = 0; i < nrOfEnemies; i++)
	{
		enemies_.push(Enemy(character_.get_level()));
	}

	//Battle varibles
	int attackRoll = 0;
	int defendRoll = 0;
	int damage = 0;
	int gainExp = 0;

	
	while ((choice = get_battle_menu_choice())!= BattleMenu::ESCAPE && !playerDefeated && !enemyDefeated) // (!escape && !playerDefeated && !enemyDefeated)
	{
		if (playerTurn && !playerDefeated)
		{
			//Menu

			//Move
			switch (choice)
			{
			case ESCAPE:
				escape = true;
				cout << "Escape" << endl;
				break;
			case ATTACK:
				cout << "ATTACK" << endl;
				//Select enemy 

				cout << "Select enemy : " << endl;
				
				for (size_t i = 0; i < enemies_.size(); i++)
				{
					cout << i << ": " << enemies_[i].get_level()<<" - " 
						<<"HP: " << enemies_[i].get_Hp() << "/" << enemies_[i].get_HpMax() << endl;
				}
				cout << endl;
				cin >> choice;

				while (cin.fail()|| choice >= enemies_.size() || choice <0 )//check cin
				{
					cout << "Faulty input!" << endl;
					cin.clear();
					cin.ignore(100, '\n');
					cout << endl << "Choice ";
					cin >> choice;
				}

				cin.ignore(100, '\n');
				cout << endl;


				attackRoll = rand() % 100 + 1;
				if (attackRoll > 50 )//Hit
				{
					cout << "HIT! " << "\n\n";
					damage = character_.get_damage();
					enemies_[choice].take_damage(damage);
					cout << "Damage: " << damage << "!" << "\n\n";
					if (!enemies_[choice].is_alive())
					{
						cout << "Enemy defated!" << endl;
						gainExp = enemies_[choice].get_exp();
						character_.gain_exp(gainExp);
						cout << "exp gained : " << gainExp << endl;
						enemies_.remove(choice);
					}
				}
				else//Miss
				{
					cout << "Miss! \n\n";
				}
				break;
			case DEFEND:
				cout << "DEFEND" << endl;
				break;
			case USEITEM:
				cout << "USEITEM" << endl;
				break;
			default:
				break;
			}		

			//End turn
			playerTurn = false;
		}
		else if(!playerTurn && !escape && !enemyDefeated)
		{
			//Enemy attack
			for (size_t i = 0; i < enemies_.size(); i++)
			{

			}
			//End turn
			playerTurn = true;
		}
		

		//Conditions


		if (!character_.is_alive())
		{
			playerDefeated = true;
		}
		else if (enemies_.size() <=0)
		{
			enemyDefeated = true;
		}
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