#pragma once
#include "Item.h"
class Armor :
    public Item
{
private:
    int type;
    int defence;
public:
    Armor(int type_ = 0, int defence_ = 0,
        string name_ = "NONE", int level_ = 0, int buy_value_ = 0,
        int sell_value_ = 0, int rarity_ = 0);
    virtual ~Armor();

    //Pure virtual
    virtual Armor* clone()const;

    //Functions
    string toString();
};

