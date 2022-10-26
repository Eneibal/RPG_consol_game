#include "Inventory.h"

Inventory::Inventory()
{
	cap = 10;
	nr_of_items = 0;
	item_arr = new Item * [cap];
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < nr_of_items; i++)
	{
		delete item_arr[i];
	}
	delete[]item_arr;
}

void Inventory::expand()
{
	cap *= 2;
	Item** temp_arr = new Item * [cap];

	for (size_t i = 0; i < nr_of_items; i++)
	{
		temp_arr[i] = new Item(*item_arr[i]);
	}

	for (size_t i = 0; i < nr_of_items; i++)
	{
		delete item_arr[i];
	}

	delete item_arr;
	item_arr = temp_arr;

	initialize(nr_of_items);
}

void Inventory::initialize(const int from)
{
	for (size_t i = from; i < cap; i++)
	{
		item_arr[i] = nullptr;
	}
}

void Inventory::add_item(const Item& item)
{
	if (nr_of_items >= cap)
	{
		expand();
	}
	item_arr[nr_of_items++] = new Item(item);
}
void Inventory::remove_item(int index)
{

}

void Inventory::debug_print()const
{
	for (size_t i = 0; i < nr_of_items; i++)
	{
		cout << item_arr[i]->debug_print() << endl;
	}
}