#include "Item.h"



Item::Item(string name_, int level_, int buy_value_, int sell_valu_, int rarity_)
{
	name = name_;
	level = level_;
	buy_value = buy_value_;
	sell_valu = sell_valu_;
	rarity = rarity_;
}

Item::~Item()
{
}

string Item::debug_print()const
{
	return name;
}

const string& Item::get_name() const
{
	return name;
}

const int& Item::get_level() const
{
	return level;
}

const int& Item::get_buy_value() const
{
	return buy_value;
}

const int& Item::get_sell_value() const
{
	return sell_valu;
}

const int& Item::get_rarity() const
{
	return rarity;
}
