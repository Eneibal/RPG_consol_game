#pragma once
#include <string>
#include<iostream>
using namespace std;
class Item
{
private:
	string name;
	int level;
	int buy_value;
	int sell_valu;
	int rarity;
public:
	Item(string name_ ="NONE",int level_=0,
		int buy_value_ =0,
		int sell_valu_=0,
		int rarity_ =0);
	virtual ~Item();
	string debug_print() const;
	virtual Item* clone()const=0;
	//Accessors
	const string & get_name()const;
	const int & get_level()const;
	const int & get_buy_value()const;
	const int & get_sell_value()const;
	const int & get_rarity()const;

	//Modifiers
};

