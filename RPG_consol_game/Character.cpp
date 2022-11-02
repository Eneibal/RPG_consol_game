#include "Character.h"

Character::Character()
{
	x_pos = 0.0;
	y_pos = 0.0;

	distanc_travelled = 0;

	gold=0;
	name="";
	level=0;
	exp=0;
	exp_next=0;

	strenght = 0;
	vitality = 0;
	dexterity = 0;
	intelligence = 0;

	hp = 0;
	hp_max=0;
	stamina=0;
	stamina_max = 0;
	damage_min=0;
	damage_max=0;
	defence=0;
	accuracy = 0;
	luck = 0;

	stat_points = 0;
	skill_points = 0;
}

Character::~Character()
{
}
//Functions
void Character::initialize(const string name_)
{
	distanc_travelled = 0;
	gold = 100;
	name = name_;
	level = 1;
	exp = 0;
	exp_next = static_cast<int>((50 / 3) * ((pow(level, 3) -
		6 * pow(level, 2)) +
		17 * level - 12)) + 100;

	strenght = 5;
	vitality = 5;
	dexterity = 5;
	intelligence = 5;

	
	hp_max = (vitality *2)+(strenght / 2);
	hp = hp_max;
	
	stamina_max = vitality + (strenght / 2 )+(dexterity /3);
	stamina = stamina_max;

	damage_min = strenght;
	damage_max = strenght +2;
	defence = dexterity + (intelligence /2);
	accuracy = (dexterity / 2);
	luck = intelligence;

	stat_points = 0;
	skill_points = 0;
}

void Character::print_stats()const
{
	cout << "= Character Sheet =" << endl;
	cout << "= Name: " << name << endl;
	cout << "= Level: " << level << endl;
	cout << "= Exp: " << exp << endl;
	cout << "= Exp to next level: " << exp_next << endl<<endl;
	cout << "= Strenght: " << strenght << endl;
	cout << "= Vitalyty: " << vitality << endl;
	cout << "= Dexterity: " << dexterity << endl;
	cout << "= Intelligent: " << intelligence << endl<<endl;
	cout << "= HP: " << hp << " / " << hp_max << endl;
	cout << "Stamina: " << stamina << " / " << stamina_max << endl;
	cout << "= Damage: " << damage_min << " - " << damage_max << endl;
	cout << "= Defence: " << defence << endl;
	cout << "= Accuracy: " << accuracy << endl;
	cout << "= Luck: " << luck << endl;
	cout << endl;
}

void Character::level_up()
{
	if (exp>=exp_next)
	{
		exp -= exp_next;

		level++;
		exp_next = static_cast<int>((50 / 3) * ((pow(level, 3) -
			6 * pow(level, 2)) +
			17 * level - 12)) + 100;

		stat_points++;
		skill_points++;

		cout << "You are now LEVEL " << level << "!" << endl;
	}
	else
	{
		cout << "NOT ENOUGHT EXP!\n\n";
	}
}

string Character::get_as_string()const
{
	return to_string(x_pos) + " "
		+ to_string(y_pos) + " "
		+ name + " "
		+ to_string(exp) + " "
		+ to_string(exp_next) + " "
		+ to_string(strenght) + " "
		+ to_string(vitality) + " "
		+ to_string(dexterity) + " "
		+ to_string(intelligence) + " "
		+ to_string(hp) + " "
		+ to_string(stamina) + " "
		+ to_string(stat_points) + " "
		+ to_string(skill_points);
}

const int& Character::get_dist_travel() const
{
	return distanc_travelled;
}

const string& Character::get_name() const
{
	return name;
}

const int& Character::get_level() const
{
	return level;
}

const int& Character::get_exp() const
{
	return exp;
}

const int& Character::get_exp_next() const
{
	return exp_next;
}

const int& Character::get_hp() const
{
	return hp;
}

const int& Character::get_hp_max() const
{
	return hp_max;
}

const int& Character::get_stamina() const
{
	return stamina;
}

const int& Character::get_damage_min() const
{
	return damage_min;
}

const int& Character::get_damage_max() const
{
	return damage_max;
}

const int& Character::get_defence() const
{
	return defence;
}

const int& Character::get_luck() const
{
	return luck;
}

const int& Character::get_accuracy() const
{
	return accuracy;
}

//Modifire

void Character::set_dist_travelled(int  distance_)
{
	distanc_travelled = distance_;
}

void Character::travel()
{
	distanc_travelled++;
}

void Character::gain_exp(int exp_)
{
	exp += exp_;
}