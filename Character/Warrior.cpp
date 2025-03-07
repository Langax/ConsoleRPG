#include "Warrior.h"
#include <iostream>
#include <sstream>

Warrior::Warrior()
{
    Name = "Warrior";
    Health = 100;
    AttackPower = 20;
    MagicPower = 0;
    Mana = 25;
    ClassID = 1;
}

bool Warrior::Attack(Character& Target)
{
    if (bIsDead) return false;

    int Damage = CalculateDamage(0.8, 1);

    std::ostringstream AttackText;
    AttackText << "\n" << Name << " Cleaves their sword through the air dealing " << Damage << " damage to the " << Target.Name << "\n";
    TypeText(AttackText.str());

    Target.TakeDamage(Damage);
    return true;
}

void Warrior::Heal()
{
    std::ostringstream HealText;
    HealText << Name << " Calms their rage and heals 15 health points\n";
    TypeText(HealText.str());


    Health += 15;
    if (Health > 150)
    {
        Health = 150;
    }
    Mana -= 5;
}

