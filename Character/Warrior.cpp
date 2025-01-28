#include "Warrior.h"
#include <iostream>

Warrior::Warrior()
{
    Name = "Warrior";
    Health = 150;
    AttackPower = 20;
    MagicPower = 0;
    Mana = 25;
    ClassID = 1;
}

void Warrior::Attack(Character& Target)
{
    if (bIsDead) return;

    int Damage = CalculateDamage();
    std::cout << "\n" << Name << " Cleaves their sword through the air dealing " << Damage << " damage to the " << Target.Name << "\n";
    Target.TakeDamage(Damage);
}

void Warrior::Heal()
{
    std::cout << Name << " Calms their rage and heals 15 health points\n";
    Health += 15;
    if (Health > 150)
    {
        Health = 150;
    }
    Mana -= 5;
}

void Warrior::TakeDamage(int Damage)
{
    if (bIsDead) return;
    
    if (Damage > 0)
    {
        //std::cout << "The Warrior grunts with pain, and takes " << Damage << " damage\n";
        std::cout << "\n";
        Health -= Damage;
        if (Health <= 0)
        {
            Die();
        }
    }
    else
    {
        std::cout << Name << " Holds steadfastly, and takes no damage!\n";
    }
}

void Warrior::Die()
{
    std::cout << Name << " Has fainted!\n";
    bIsDead = true;
}

int Warrior::CalculateDamage()
{
    std::srand(std::time(nullptr)); // Seed random number generator
    int RandomNumber = std::rand() % 5 + 1; // Generates a number between 1 and 5

    int CalculatedDamage = (AttackPower * 0.8) + RandomNumber;

    return CalculatedDamage;
}

void Warrior::Status()
{
    std::cout << "Remaining Health: " << Health << '\n';
    std::cout << "Remaining Mana: " << Mana << '\n';
}

void Warrior::RecoverMana()
{
    
}
