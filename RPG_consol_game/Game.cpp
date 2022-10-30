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
//Functions
void Game::init_game()
{
	create_new_character();
}

MainMenu Game::get_main_menu_choice()
{
	system("cls");
	cout << "\n =Main Menu= \n" << endl;
	cout << "\n" << (int)MainMenu::QUIT << ". Quit" << endl;
	cout << "\n" << (int)MainMenu::TRAVEL << ". Travel" << endl;
	cout << "\n" << (int)MainMenu::SHOP << ". Shop" << endl;
	cout << "\n" << (int)MainMenu::LEVELUP << ". Level up" << endl;
	cout << "\n" << (int)MainMenu::REST << ". Rest" << endl;
	cout << "\n" << (int)MainMenu::CHARACTERSHEET << ". Character sheet" << endl;
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
	MainMenu choice;
	while ((choice = get_main_menu_choice()) != MainMenu::QUIT)//!= MainMenu::QUIT
	{
		switch (choice)
		{
		case TRAVEL:

			system("pause");
			break;
		case SHOP:

			system("pause");
			break;
		case LEVELUP:

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

			break;
		case LOADCHARACTER:
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
	}
}

void Game::create_new_character()
{
	string name;
	cout << "Enter name for character: ";
	getline(cin, name);

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
	
	if (in_file.is_open())
	{
		while (!in_file.eof())//(getline(in_file,string()))
		{
			name = "";

			in_file >> name;
			
			//check double coppy last character
			if (name !="")
			{
				//Character temp(name);
				//character.push_back(Character(temp));
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

void Game::travel()
{
	character[active_characters].travel();

	Event ev;

	ev.gererate_event(character[active_characters]);
}