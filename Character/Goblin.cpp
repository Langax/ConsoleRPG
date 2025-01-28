#include "Goblin.h"

#include <iostream>

Goblin::Goblin()
{
    Name = "Vicious Goblin";
    Health = 200;
    AttackPower = 10;
    MagicPower = 0;
    Mana = 25;
}

void Goblin::Attack(Character& Target)
{
    if (bIsDead) return;
    
    std::cout << "The " << Name << " counterattacks and stabs its dagger! dealing " << AttackPower << " damage to the " << Target.Name << "\n";
    Target.TakeDamage(AttackPower);
}

void Goblin::TakeDamage(int Damage)
{
    if (bIsDead) return;
    
    if (Damage > 0)
    {
        //std::cout << "The " << Name << " squeals from the pain\n";
        Health -= Damage;

        if (Health <= 0)
        {
            Die();
        }

    }
    else
    {
        std::cout << "The goblin chuckles 'kekekeke', and takes no damage!\n";
    }
}

void Goblin::Heal()
{
    std::cout << "The " << Name << " pulls out an unknown meat and eats it! It begins to look a little better..\n";
    Health += 5;
    if (Health > 200)
    {
        Health = 200;
    }
}

void Goblin::Die()
{
    std::cout << "The " << Name << " falls to the floor, presumably dead\n";
    bIsDead = true;
}

void Goblin::Status()
{
    if (Health < 50)
    {
        std::cout << "The " << Name << " begins to panic, looking very worn and beaten\n";
    }
    else if (Health < 100)
    {
        std::cout << "The " << Name << " looks around nervously, starting to look worn\n";
    }
    else if (Health < 150)
    {
        std::cout << "The " << Name << " still stands firm looking ready to fight\n";
    }
    else
    {
        std::cout << "The " << Name << " is in peak condition, ready for battle!\n";
    }
}

int Goblin::CalculateDamage()
{
    std::srand(std::time(nullptr)); // Seed random number generator
    int RandomNumber = std::rand() % 5 + 1; // Generates a number between 1 and 5

    int CalculatedDamage = (AttackPower * 0.8) + RandomNumber;

    return CalculatedDamage;
}

void Goblin::RecoverMana()
{
}
