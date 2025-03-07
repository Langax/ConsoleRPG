#include "Mage.h"
#include <iostream>
#include <sstream>

Mage::Mage()
{
    Name = "Mage";
    Health = 75;
    AttackPower = 5;
    MagicPower = 25;
    Mana = 100;
    ClassID = 2;
}

bool Mage::Attack(Character& Target)
{
    if (bIsDead) return false;
    if (Mana < 15)
    {
        TypeText("You don't have enough mana!\n");
        return false;
    }
    std::ostringstream AttackText;
    int Damage = CalculateDamage(0.9f, 2);
    AttackText << "\n" << Name << " Hurls a mighty fireball through the air dealing " << Damage << " damage to the " << Target.Name << "\n";
    TypeText(AttackText.str());
    Mana -= 15;
    Target.TakeDamage(Damage);
    return true;
}

void Mage::Heal()
{
    if (bIsDead) return;
    if (Mana < 10)
    {
        TypeText("You don't have enough mana!\n");
        return;
    }
    
    std::ostringstream HealText;
    HealText << Name << " Channels a water spell and heals 20 health!\n";
    TypeText(HealText.str());


    Health += 20;
    if (Health > 75)
    {
        Health = 75;
    }
    Mana -= 10;
}
