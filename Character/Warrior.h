#pragma once
#include "Character.h"

class Warrior : public Character
{
public:
    //================================================================================================
    //=============================== PROPERTIES & VARIABLES =========================================
    //================================================================================================

    
    //================================================================================================
    //====================================== FUNCTIONS ===============================================
    //================================================================================================
    Warrior();
    void Attack(Character& target) override;
    void Heal() override;
    void TakeDamage(int damage) override;
    void Die() override;
    int CalculateDamage() override;
    void Status() override;
    void RecoverMana() override;
};
