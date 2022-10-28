#pragma once
#include "Item.h"
class Weapon :
    public Item
{
private:
    int damage_min;
    int damage_max;

public:
    Weapon(int damage_min_ = 0, int damage_max_ = 0,
        string name_ = "NONE", int level_ = 0, int buy_value_ = 0,
        int sell_value_ = 0, int rarity_ = 0);
    virtual ~Weapon();

    //Pure virtual
    virtual Weapon* clone()const;

    //Functions
    string toString();

    // Inherited via Item
    //virtual Item* clone() const override;


};

