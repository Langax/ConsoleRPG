#include "Mage.h"
#include <iostream>

Mage::Mage()
{
    Name = "Mage";
    Health = 75;
    AttackPower = 5;
    MagicPower = 25;
    Mana = 100;
    ClassID = 2;
}

void Mage::Attack(Character& Target)
{
    if (bIsDead) return;
    if (Mana < 15)
    {
        std::cout << "You don't have enough mana!\n";
        return;
    }

    int Damage = CalculateDamage();
    std::cout << "The Mage hurls a mighty fireball through the air dealing " << Damage << " damage to the " << Target.Name << "\n";
    Mana -= 15;
    Target.TakeDamage(Damage);
}

void Mage::Heal()
{
    if (bIsDead) return;
    if (Mana < 10)
    {
        std::cout << "You don't have enough mana!\n";
        return;
    }
    
    std::cout << "The Mage channels a water spell and heals 10 health!\n";
    Health += 20;
    if (Health > 75)
    {
        Health = 75;
    }
    Mana -= 10;
}

void Mage::TakeDamage(int Damage)
{
    if (bIsDead) return;
    
    if (Damage > 0)
    {
        //std::cout << "The Mage flinches with pain, and takes " << Damage << " damage\n";
        std::cout << "\n";
        Health -= Damage;
        if (Health <= 0)
        {
            Die();
        }
    }
    else
    {
        std::cout << "The Mage looks unfazed, and takes no damage!\n";
    }
}

void Mage::RecoverMana()
{
    if (bIsDead) return;
    std::cout << "The Mage sits for a moment, and recovers 30 Mana!";
    Mana += 30;
    if (Mana > 100)
    {
        Mana = 100;
    }
}

void Mage::Die()
{
    std::cout << "The Mage has fainted!\n";
    bIsDead = true;
}

int Mage::CalculateDamage()
{
    std::srand(std::time(nullptr)); // Seed random number generator
    int RandomNumber = std::rand() % 5 + 1; // Generates a number between 1 and 5

    int CalculatedDamage = (MagicPower * 0.9) + RandomNumber;

    return CalculatedDamage;
}

void Mage::Status()
{
    std::cout << "Remaining Health: " << Health << '\n';
    std::cout << "Remaining Mana: " << Mana << '\n';
}
