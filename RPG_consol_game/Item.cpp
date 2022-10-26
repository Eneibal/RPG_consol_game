#include "Item.h"

Item::Item()
{
	name = "NONE";
	buy_value = 0;
	sell_valu = 0;
}

Item::~Item()
{
}

string Item::debug_print()const
{
	return name;
}