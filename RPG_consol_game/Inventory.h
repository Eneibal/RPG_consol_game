#pragma once
//#include"Item.h"
#include"Weapon.h"
#include"Armor.h"
class Inventory
{
private:
	int cap;
	int nr_of_items;
	Item** item_arr;
	void expand();
	void initialize(const int from);

public:
	Inventory();
	virtual ~Inventory();

	void add_item(const Item& item);
	void remove_item(int index);

	void debug_print()const;
};

