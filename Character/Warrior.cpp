#include "Warrior.h"
#include <string>
#include <iostream>

Warrior::Warrior()
{
    Name = "Warrior";
    Health = 150;
    AttackPower = 20;
    MagicPower = 0;
    Mana = 25;
}

void Warrior::Attack(Character& Target)
{
    if (bIsDead) return;
    
    std::string TargetName = Target.Name;
    std::cout << "The Warrior cleaves his sword through the air dealing " << AttackPower << " damage to the " << TargetName << "\n";
    Target.TakeDamage(AttackPower);
}

void Warrior::TakeDamage(int Damage)
{
    if (bIsDead) return;
    
    if (Damage > 0)
    {
        std::cout << "The Warrior flinches with pain, and takes " << Damage << " damage\n";
        Health -= Damage;
        std::cout << "Remaining Health: " << Health << '\n';
        if (Health <= 0)
        {
            Die();
        }
    }
    else
    {
        std::cout << "The Warrior holds steadfastly, and takes no damage!\n";
    }
}

void Warrior::Heal()
{
    std::cout << "The Warrior calms his rage and heals 5 health points\n";
    Health += 5;
    std::cout << "Remaining Health: " << Health << '\n';
    Mana -= 5;
    std::cout << "Remaining Mana: " << Mana << '\n';
}

void Warrior::Die()
{
    std::cout << "The Warrior has fainted!\n";
    bIsDead = true;
}
