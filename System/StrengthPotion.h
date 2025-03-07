#pragma once
#include "ItemBase.h"

class Character;

class StrengthPotion : public ItemBase
{
public:
    //================================================================================================
    //=============================== PROPERTIES & VARIABLES =========================================
    //================================================================================================
    std::string Name;
    int StrengthIncrease;
    int SellValue;

    //================================================================================================
    //====================================== FUNCTIONS ===============================================
    //================================================================================================
  
    // Initializer list for optimization to set the Name and Heal Amount of the Health Potion
    StrengthPotion(const std::string& name, int strength) : Name(name), StrengthIncrease(strength), SellValue(35) {}
    void Use(Character& Owner) override;
    void TypeText(const std::string& text);
    std::string GetName() const { return Name; };

};
