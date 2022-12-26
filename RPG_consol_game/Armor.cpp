#include "Armor.h"

Armor::Armor(int type_, int defence_,
    string name_, int level_, int buy_value_, int sell_value_, int rarity_)
    :Item(name_, level_, buy_value_, sell_value_, rarity_)
{
    type = type_;
    defence = defence_;
}

Armor::~Armor()
{
}

Armor* Armor::clone()const
{
    return new Armor(*this);
}


string Armor::toString()
{
    string str = to_string(type) + " " + to_string(defence);
    return str;
}

int Armor::get_defence()const
{
    return defence;
}

int Armor::get_type()const
{
    return type;
}