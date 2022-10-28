#pragma once
#include"Inventory.h"

class Character
{
private:
	double x_pos;
	double y_pos;

	Inventory inventory;
	Weapon weapon;
	Armor armor;

	string name;
	int level;
	int exp;
	int exp_next;

	int strenght;
	int vitality;
	int dexterity;
	int intelligence;

	int hp;
	int hp_max;
	int stamina;
	int stamina_max;
	int damage_min;
	int damage_max;
	int defence;
	int luck;

	int stat_points;
	int skill_points;

public:
	Character();
	~Character();

	//Funcrions
	void initialize(const string name_);
	void print_stats()const;
	void level_up();
	string get_as_string()const;

	//Accessors
	const double& get_x()const;
	const double& get_y()const;
	const string& get_name()const;
	const int& get_level()const;
	const int& get_exp()const;
	const int& get_exp_next()const;
	const int& get_hp()const;
	const int& get_hp_max()const;
	const int& get_stamina()const;
	const int& get_damage_min()const;
	const int& get_damage_max()const;
	const int& get_defence()const;

	//Modifier


};

