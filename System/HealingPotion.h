#pragma once
#include "ItemBase.h"

class Character;

class HealingPotion : public ItemBase
{
public:
    //================================================================================================
    //=============================== PROPERTIES & VARIABLES =========================================
    //================================================================================================
    std::string Name;
    int HealAmount;


    //================================================================================================
    //====================================== FUNCTIONS ===============================================
    //================================================================================================
    // Initializer list for optimization to set the Name and Heal Amount of the Health Potion
    HealingPotion(const std::string& name, int heal) : Name(name), HealAmount(heal){}
    void Use(Character& Owner) override;
    std::string GetName() override;
};
