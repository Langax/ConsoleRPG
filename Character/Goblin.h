#pragma once
#include "Character.h"

class Goblin : public Character
{
public:
    //================================================================================================
    //=============================== PROPERTIES & VARIABLES =========================================
    //================================================================================================


    //================================================================================================
    //====================================== FUNCTIONS ===============================================
    //================================================================================================
    Goblin();
    void Attack(Character& Target) override;
    void TakeDamage(int Damage) override;
    void Heal() override;
    void Die() override;
    void Status() override;
    int CalculateDamage() override;
    void RecoverMana() override;
};
