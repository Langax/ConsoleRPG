#pragma once
#include "ItemBase.h"

class Character;

class ManaPotion : public ItemBase
{
public:
    //================================================================================================
    //=============================== PROPERTIES & VARIABLES =========================================
    //================================================================================================
    std::string Name;
    int ManaAmount;
    int SellValue;

    //================================================================================================
    //====================================== FUNCTIONS ===============================================
    //================================================================================================
    
    // Initializer list for optimization to set the Name and Heal Amount of the Health Potion
    ManaPotion(const std::string& name, int mana) : Name(name), ManaAmount(mana), SellValue(35) {}
    void Use(Character& Owner) override;
    void TypeText(const std::string& text);
    std::string GetName() const { return Name; };

};
