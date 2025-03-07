#include "Goblin.h"
#include <sstream>
#include <iostream>

Goblin::Goblin()
{
    Name = "Vicious Goblin";
    Health = 200;
    AttackPower = 10;
    MagicPower = 0;
    Mana = 30;
}

bool Goblin::Attack(Character& Target)
{
    if (bIsDead) return false;
    std::ostringstream AttackText;
    int Damage = CalculateDamage(1.0f, 1);
    AttackText << "The " << Name << " counterattacks and stabs its dagger! dealing " << Damage << " damage to " << Target.Name << "\n";
    TypeText(AttackText.str());
    Target.TakeDamage(Damage);
    return true;
}


void Goblin::Heal()
{
    std::ostringstream HealText;
    HealText << "The " << Name << " pulls out an unknown meat and eats it! It begins to look a little better..\n";
    TypeText(HealText.str());
    Health += 35;
    if (Health > 200)
    {
        Health = 200;
    }
}


void Goblin::Status()
{
    std::ostringstream StatusText;

    if (Health < 50) StatusText << "The " << Name << " is panicking, looking very worn!\n";
    else if (Health < 100) StatusText << "The " << Name << " looks around nervously, starting to look worn\n";
    else if (Health < 150) StatusText << "The " << Name << " still stands firm looking ready to fight\n";
    else StatusText << "The " << Name << " is in peak condition, ready for battle!\n";
    TypeText(StatusText.str());

}

