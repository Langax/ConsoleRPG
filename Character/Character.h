#pragma once
#include <string>

class Character
{
    
public:
    //================================================================================================
    //=============================== PROPERTIES & VARIABLES =========================================
    //================================================================================================
    int Health = 100;
    int AttackPower = 10;
    int MagicPower = 10;
    int Mana = 50;
    std::string Name = "Unidentified";
    bool bIsDead = false;
    virtual ~Character() {}
    int ClassID = 0;

    
    //================================================================================================
    //====================================== FUNCTIONS ===============================================
    //================================================================================================
    virtual void Attack(Character& target) = 0;
    virtual void Heal() = 0;
    virtual void TakeDamage(int damage) = 0;
    virtual void Die() = 0;
    virtual int CalculateDamage() = 0;
    virtual void Status() = 0;
    virtual void RecoverMana() = 0;
};
