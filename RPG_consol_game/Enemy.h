#pragma once
#include <stdlib.h>
#include<string>
using namespace std;
class Enemy
{
private:
	int level;
	int hp;
	int hp_max;
	int damage_min;
	int damage_max;
	float drop_chance;
	int defence;
	int accuracy;
public:
	Enemy(int level_ = 0);
	virtual ~Enemy();

	bool is_alive();
	string get_as_string()const;
	void take_damage(int damage);
	int get_level()const;
	int get_damage()const;
	int get_exp()const;
	int get_Hp()const;
	int get_HpMax()const;
	int get_defence()const;
	int get_Accuracy()const;
};

