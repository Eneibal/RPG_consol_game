#pragma once
#include <string>
#include<iostream>
using namespace std;
class Item
{
private:
	string name;
	int buy_value;
	int sell_valu;
public:
	Item();
	virtual ~Item();
	string debug_print() const;
};

