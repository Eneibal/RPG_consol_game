#include "Enemy.h"


Enemy::Enemy(int level_)
{
	level = level_;
	hp_max = level * 10;
	hp = hp_max;
	damage_min = level * 1;
	damage_max = level * 2;
	drop_chance = rand() % 100+1;
	defence = rand() %level * 2 +1;
	accuracy = rand() % level *2 +1;
}

Enemy::~Enemy()
{
}

bool Enemy::is_alive()
{
	return hp>0;
}

string Enemy::get_as_string() const
{
	return "Level: " + to_string(level) + "\n" +
		"Hp: " + to_string(hp) + " / " + to_string(hp_max) + "\n" +
		"Dagame: " + to_string(damage_min) + " / " + to_string(damage_max) + "\n" +
		"Defence: " + to_string(defence) + "\n" +
		"Accurancy: " + to_string(accuracy) + "\n" +
		"Drop chance: " + to_string(drop_chance) + "\n";
}

void Enemy::take_damage(int damage) 
{
	hp -= damage;
	if (hp <=0)
	{
		hp = 0;

	}
}
int Enemy::get_level()const
{
	return level;
}


int Enemy::get_damage() const
{
	return rand()% damage_max + damage_min; //damage_min +  damage_max
}

int Enemy::get_exp() const
{
	return level *100;
}

int Enemy::get_Hp()const
{
	return hp;
}

int Enemy::get_HpMax()const
{
	return hp_max;
}

int Enemy::get_defence()const
{
	return defence;
}

int Enemy::get_Accuracy()const
{
	return accuracy;
}
