#include "Game.h"

Game::Game()
{
	choice = 0;
	playing = true;
	active_characters = 0;
	file_name = "characters.txt";
}

bool Game::get_playing() const
{
	return playing;
}

Game::~Game()
{

}

MainMenu Game::get_main_menu_choice()
{
	if (character[active_characters].get_exp() >=
		character[active_characters].get_exp_next())
	{
		cout << "LEVEL UP AVALIBLE! \n\n";
		system("pause");
	}
	system("cls");

	cout << "\n =Main Menu= \n" << endl;
	cout << "= Active character: " << character[active_characters].get_name() << " Nr: "
		<<active_characters+1<<" / "<<character.size() << endl;
	cout << "\n" << (int)MainMenu::QUIT << ". Quit" << endl;
	cout << "\n" << (int)MainMenu::TRAVEL << ". Travel" << endl;
	cout << "\n" << (int)MainMenu::SHOP << ". Shop" << endl;
	cout << "\n" << (int)MainMenu::LEVELUP << ". Level up" << endl;
	cout << "\n" << (int)MainMenu::REST << ". Rest" << endl;
	cout << "\n" << (int)MainMenu::CHARACTERSHEET << ". Character sheet" << endl;
	cout << "\n" << (int)MainMenu::SELECTCHARACTER << ". Select character" << endl;
	cout << "\n" << (int)MainMenu::CREATENEWCHARACTER << ". Create new character" << endl;
	cout << "\n" << (int)MainMenu::SAVECHARACTER << ". Save character" << endl;
	cout << "\n" << (int)MainMenu::LOADCHARACTER << ". Load character" << endl;
	

	cout << "\n\n" << "Choice: ";
	cin >> choice;

	while (cin.fail())//check cin
	{
		cout << "Faulty input!" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << endl << "Choice ";
		cin >> choice;
	}

	cin.ignore(100, '\n');
	cout << endl;

	return static_cast<MainMenu>(choice);
}

void Game::main_menu()
{
	if (character[active_characters].is_alive())
	{


		MainMenu choice;
		while ((choice = get_main_menu_choice()) != MainMenu::QUIT)//!= MainMenu::QUIT
		{
			switch (choice)
			{
			case TRAVEL:
				travel();
				system("pause");
				break;
			case SHOP:

				system("pause");
				break;
			case LEVELUP:
				level_up_character();
				system("pause");
				break;
			case REST:

				system("pause");
				break;
			case CHARACTERSHEET:
				character[active_characters].print_stats();
				system("pause");
				break;
			case CREATENEWCHARACTER:
				create_new_character();
				save_character();
				system("pause");
				break;
			case SAVECHARACTER:
				save_character();
				system("pause");
				break;
			case LOADCHARACTER:
				load_character();
				system("pause");
				break;
			case SELECTCHARACTER:
				select_character();
				system("pause");
				break;
			default:
				cout << "Invalid choice in main menu: " << (int)choice << endl;
				system("pause");
				break;
			}
		}
		if (MainMenu::QUIT)
		{
			playing = false;
			save_character();
		}
	}
	else
	{
		cout << "\n = YOU ARE DEAD, LOAD ? = \n" << endl;
		cout << "\n =(0) Yes, (1) No= \n" << endl;
		cin >> choice;

		while (cin.fail() || choice <0 || choice >1)//check cin
		{
			cout << "Faulty input!" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\n =(0) Yes, (1) No= \n" << endl;
			cin >> choice;
		}

		cin.ignore(100, '\n');
		cout << endl;
		if (choice == 0)
		{
			load_character();
		}
		else
		{
			playing = false;
		}
	}
}

LevelUpCharacter Game::get_level_up_character()
{
	system("cls");
	cout << "You have statpoints to allocate !\n\n";
	cout << "Stat to upgrade: ";
	cout << "\n" << (int)LevelUpCharacter::STRENGHT << ". Stranght" << endl;
	cout << "\n" << (int)LevelUpCharacter::VITALITY << ". Vitality" << endl;
	cout << "\n" << (int)LevelUpCharacter::DEXTERITY << ". Dexterity" << endl;
	cout << "\n" << (int)LevelUpCharacter::INTELLIGENCE << ". Intelligence" << endl;

	cout << "\n\n" << "Choice: ";
	cin >> choice;

	while (cin.fail() || choice > 4)//choice =4 levelUpCharacter have only 4 stats
	{
		cout << "Faulty input!" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << endl << "Stat to upgrade: ";
		cin >> choice;
	}

	cin.ignore(100, '\n');
	cout << endl;

	return static_cast<LevelUpCharacter>(choice);
}

void Game::level_up_character()
{
	character[active_characters].level_up();

	if (character[active_characters].get_stat_points() > 0)
	{
		LevelUpCharacter choice;
		choice = get_level_up_character();
		switch (choice)
		{
		case STRENGHT:
			character[active_characters].add_to_stat(0, 1);
			break;
		case VITALITY:
			character[active_characters].add_to_stat(1, 1);
			break;
		case DEXTERITY:
			character[active_characters].add_to_stat(2, 1);
			break;
		case INTELLIGENCE:
			character[active_characters].add_to_stat(3, 1);
			break;
		default:
			break;
		}
	}
}

//Functions
void Game::init_game()
{
	ifstream in;
	in.open("characters.txt");
	if (in.is_open())
	{
		load_character();
	}
	else
	{
		create_new_character();
		save_character();
	}
	in.close();

	//system("pause");
}

void Game::create_new_character()
{
	string name;
	cout << "Enter name for character: ";
	getline(cin, name);

	for (size_t i = 0; i < character.size(); i++)
	{
		while (name == character[i].get_name())
		{
			cout << "Error! Characte alredy exist!" << endl;
			cout << "Character name :";
			getline(cin, name);
		}
	}

	character.push_back(Character());
	active_characters = character.size() - 1;
	character[active_characters].initialize(name);
	//cin.ignore();
}

void Game::save_character()
{
	ofstream out_file(file_name,ios::out);
	if (out_file.is_open())
	{
		for (size_t i = 0; i < character.size(); i++)
		{
			out_file << character[i].get_as_string()<<"\n";
		}
		out_file.close();
	}
}

void Game::load_character()
{
	ifstream in_file(file_name, ios::in);

	character.clear();

	string name = "";
	int distanc_travelled=0;
	int gold=0;
	int level=0;
	int exp=0;

	int strenght=0;
	int vitality=0;
	int dexterity=0;
	int intelligence=0;

	int hp=0;
	int stamina=0;

	int stat_points=0;

	if (in_file.is_open())
	{
		while (!in_file.eof())//(getline(in_file,string()))
		{
			name = "";

			in_file >> name;
			in_file >> distanc_travelled;
			in_file >> gold;
			in_file >> level;
			in_file >> exp;
			in_file >> strenght;
			in_file >> vitality;
			in_file >> dexterity;
			in_file >> intelligence;
			in_file >> hp;
			in_file >> stamina;
			in_file >> stat_points;
			
			//check double coppy last character
			if (name !="")
			{
				Character temp(name, distanc_travelled,gold,level,exp,
					strenght,vitality,dexterity,intelligence,
					hp,stamina,stat_points);
				character.push_back(Character(temp));
				cout << "Character: " << name << " loaded!" << endl;
			}
		}
		in_file.close();
	}
	if (character.size()<=0)
	{
		//throw "ERROR! NO CHARACTERS LOADED OR EMPTY FILE! ";
		cout << "NO CHARACTERS LOADED OR EMPTY FILE!\n\n";
		cout << "Create new character \n\n";
		create_new_character();
	}
}

void Game::select_character()
{
	cout << " Sselect character: " << endl;

	for (size_t i = 0; i < character.size(); i++)
	{
		cout <<"Index: "<<i <<" " << character[i].get_name() << " level: " << character[i].get_level() << endl;
	}
	cout << endl;
	cout << "Choice: ";
	cin >> choice;

	while (cin.fail() || choice >= character.size() || choice < 0)//check cin
	{
		cout << "Faulty input!" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << endl << "Select characte: ";
		cin >> choice;
	}

	cin.ignore(100, '\n');
	cout << endl;
	active_characters = choice;
	cout << character[active_characters].get_name() << " Is selected!" << endl;
}

void Game::travel()
{
	character[active_characters].travel();

	Event ev;

	ev.gererate_event(character[active_characters],enemies);
}