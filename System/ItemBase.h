#pragma once
#include <string>

class Character;

class ItemBase
{

    
public:
    //================================================================================================
    //=============================== PROPERTIES & VARIABLES =========================================
    //================================================================================================
    int SellValue = 35;
    std::string Name;



    //================================================================================================
    //====================================== FUNCTIONS ===============================================
    //================================================================================================
    virtual void Use(Character& Owner) = 0;
    virtual std::string GetName() const { return Name; }

};
