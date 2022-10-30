#pragma once
//
#include"Event.h"

#include<vector>
#include<ctime>
enum MainMenu
{
	QUIT=1,
	TRAVEL,
	SHOP,
	LEVELUP,
	REST,
	CHARACTERSHEET,
	CREATENEWCHARACTER,
	SAVECHARACTER,
	LOADCHARACTER,
};

class Game
{
private:
	int choice;
	bool playing;

	MainMenu get_main_menu_choice();
	//Character related
	int active_characters;
	vector<Character> character;
	string file_name;
public:
	Game();
	~Game();
	//Operators


	//Functions
	void main_menu();
	void init_game();
	void create_new_character();
	void save_character();
	void load_character();
	void travel();
	//Accessors
	bool get_playing()const;
};

