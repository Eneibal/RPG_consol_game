#pragma once

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
	SELECTCHARACTER,
	CREATENEWCHARACTER,
	SAVECHARACTER,
	LOADCHARACTER,	
};



class Game
{
private:
	MainMenu get_main_menu_choice();
	LevelUpCharacter get_level_up_character();

	int choice;
	bool playing;

	//Character related
	int active_characters;
	vector<Character> character;
	string file_name;

	//Enemis
	dArr<Enemy> enemies;

public:
	Game();
	~Game();
	//Operators


	//Functions
	void main_menu();
	void init_game();
	void create_new_character();
	void level_up_character();
	void save_character();
	void load_character();
	void select_character();
	void travel();
	//Accessors
	bool get_playing()const;
};

