#include "Character.h"

Character::Character()
{
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

Character::Character(string name_, int distance_travelled_,
	int gold_, int level_,
	int exp_, int strenght_, int vitality_,
	int dexterity_, int intelligence_,
	int hp_, int stamina_, int stat_points_, int skillpoints_)
{
	distanc_travelled = distance_travelled_;

	gold = gold_;
	name = name_;
	level = level_;
	exp = exp_;
	exp_next = 0;

	strenght = strenght_;
	vitality = vitality_;
	dexterity = dexterity_;
	intelligence = intelligence_;

	hp = hp_;
	hp_max = 0;
	stamina = stamina_;
	stamina_max = 0;
	damage_min = 0;
	damage_max = 0;
	defence = 0;
	accuracy = 0;
	luck = 0;

	stat_points = stat_points_;
	skill_points = skillpoints_;

	update_stats();
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

	strenght = 5;
	vitality = 5;
	dexterity = 5;
	intelligence = 5;	

	stat_points = 0;
	skill_points = 0;
	update_stats();
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
		update_stats();

		cout << "You are now LEVEL " << level << "!" << endl;
	}
	else
	{
		cout << "NOT ENOUGHT EXP!\n\n";
	}
}

LevelUpCharacter Character::get_level_up_stats(int stat_)
{
	return static_cast<LevelUpCharacter>(stat_);
}

void Character::add_to_stat(int stat_, int value_)
{
	if (stat_points < value_)
	{
		cout << "ERROR! NOT ENOUGHT STATPOINTS!" << endl;
	}
	else
	{
		LevelUpCharacter choice;

		switch (choice = get_level_up_stats(stat_))
		{
		case STRENGHT:
			strenght += value_;
			cout <<"STRENGHT Increased!";
			break;
		case VITALITY:
			vitality += value_;
			cout << "VITALITY Increased!";
			break;
		case DEXTERITY:
			dexterity += value_;
			cout << "DEXTERITY Increased!";
			break;
		case INTELLIGENCE:
			intelligence += value_;
			cout << "INTELLIGENCE Increased!";
			break;
		default:
			cout << "NO SUCH STAT!" << endl;
			break;
		}
		stat_points -= value_;
	}
}

void Character::update_stats()
{
	exp_next = static_cast<int>((50 / 3) * ((pow(level, 3) -
		6 * pow(level, 2)) +
		17 * level - 12)) + 100;

	hp_max = (vitality * 2) + (strenght / 2);
	stamina_max = vitality + (strenght / 2) + (dexterity / 3);
	stamina = stamina_max;
	damage_min = strenght;
	damage_max = strenght + 2;
	defence = dexterity + (intelligence / 2);
	accuracy = (dexterity / 2) + intelligence;
	luck = intelligence;

}

string Character::get_as_string()const
{
	return name +" "
		+ to_string(distanc_travelled) + " "
		+ to_string(gold)+" "
		+ to_string(level)+" "
		+ to_string(exp) + " "
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

const int& Character::get_stat_points()const
{
	return stat_points;
}

const int& Character::get_hp() const
{
	return hp;
}

const int& Character::get_hp_max() const
{
	return hp_max;
}

const bool Character::is_alive()
{
	return hp > 0;
}

const int& Character::get_stamina() const
{
	return stamina;
}

const int& Character::get_damage_min() const
{
	return damage_min;
}

const int& Character::get_damage()const
{
	return rand() % damage_max + damage_min;
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

void Character::take_damage(const int damage_)
{
	hp -= damage_;
	if (hp <=0)
	{
		hp = 0;
	}
}