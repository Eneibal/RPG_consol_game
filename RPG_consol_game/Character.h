#pragma once
#include"Inventory.h"
#include"Enemy.h"

enum LevelUpCharacter
{
	STRENGHT = 1,
	VITALITY,
	DEXTERITY,
	INTELLIGENCE,
};

class Character
{
private:
	LevelUpCharacter get_level_up_stats(int stat_);

	int distanc_travelled;

	Inventory inventory;
	Weapon weapon;
	Armor armor_head;
	Armor armor_chest;
	Armor armor_arms;
	Armor armor_legs;

	int gold;
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
	int accuracy;
	int luck;

	int stat_points;
	

public:
	Character();
	Character(string name_,int distance_travelled_,
		int gold_,int level_,
		int exp_,int strenght_,int vitality_,
		int dexterity_,int intelligence_,
		int hp_,int stamina_,int stat_points_);
	~Character();

	//Funcrions
	void initialize(const string name_);
	void print_stats()const;
	string get_as_string()const;
	void level_up();	
	void update_stats();
	void add_to_stat(int stat_, int value_);
	void reset_HP();
	//Accessors
	const int& get_dist_travel()const;
	const string& get_name()const;
	const int& get_level()const;
	const int& get_exp()const;
	const int& get_exp_next()const;
	const int& get_stat_points()const;
	const int& get_hp()const;
	const int& get_hp_max()const;
	const bool is_alive();
	const int& get_stamina()const;
	const int& get_damage_min()const;
	const int& get_damage()const;
	const int& get_damage_max()const;
	const int& get_defence()const;
	const int& get_luck()const;
	const int& get_accuracy()const;
	const int& get_gold()const;

	//Modifier
	void set_dist_travelled(int  distance_);
	void travel();
	void gain_exp(const int exp_);
	void gain_gold(const int gold_);
	void pay_gold(const int gold_);
	void take_damage(const int damage_);
};

