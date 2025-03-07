#pragma once
#include "ItemBase.h"
#include <string>

class Character;

class HealingPotion : public ItemBase
{
public:
    //================================================================================================
    //=============================== PROPERTIES & VARIABLES =========================================
    //================================================================================================
    std::string Name;
    int HealAmount;
    int SellValue;

    //================================================================================================
    //====================================== FUNCTIONS ===============================================
    //================================================================================================
    // Initializer list for optimization to set the Name and Heal Amount of the Health Potion
    HealingPotion(const std::string& name, int heal) : Name(name), HealAmount(heal), SellValue(35){}
    void Use(Character& Owner) override;
    void TypeText(const std::string& text);
    std::string GetName() const { return Name; };

};
