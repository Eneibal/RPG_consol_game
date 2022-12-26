#include "Weapon.h"

Weapon::Weapon(int damage_min_, int damage_max_,
    string name_, int level_, int buy_value_, int sell_value_, int rarity_)
    :Item(name_,level_,buy_value_,sell_value_,rarity_)
{
    damage_min = damage_min_;
    damage_max = damage_max_;
}

Weapon::~Weapon()
{
}

string Weapon::toString()
{
    string str = to_string(damage_min) + " " + to_string(damage_max);
    return str;
}

Weapon* Weapon::clone()const
{
    return new Weapon(*this);
}

int Weapon::getDamageMin()const
{
    return damage_min;
}

int Weapon::getDamageMax()const
{
    return damage_max;
}