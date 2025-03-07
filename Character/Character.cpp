#include "Character.h"
#include <thread>
#include <chrono>
#include <sstream>

void Character::TypeText(const std::string& text)
{
    for (char c : text) //For each character within the "text" string
    {
        std::cout << c << std::flush; //Print each character immediately
        std::this_thread::sleep_for(std::chrono::milliseconds(35)); //Wait for x milliseconds before printing the next character in the string
    }
}

void Character::TakeDamage(int damage)
{
    if (bIsDead) return;

    std::ostringstream NoDamageText;
    NoDamageText << Name << " looks unfazed, and takes no damage!\n";

    if (damage > 0)
    {
        std::cout << "\n";
        Health -= damage;
        if (Health <= 0)
        {
            Die();
        }
    }
    else
    {
        TypeText(NoDamageText.str());
    }
}

void Character::Die()
{
    std::ostringstream DeathText;
    DeathText << Name << " has fainted!\n";
    TypeText(DeathText.str());
    bIsDead = true;
}

int Character::CalculateDamage(float multiplier, int damagetype)
{
    //Damagetype 1 for physical damage, 2 for magic damage


    std::srand(std::time(nullptr)); // Seed random number generator
    int RandomNumber = std::rand() % 5 + 1; // Generates a number between 1 and 5
    int CalculatedDamage;

    if (damagetype == 1) 
    {
        CalculatedDamage = (AttackPower * multiplier) + RandomNumber;
    }
    else 
    {
        CalculatedDamage = (MagicPower * multiplier) + RandomNumber;

    }

    return CalculatedDamage;
}

void Character::Status()
{
    std::ostringstream StatusText;
    StatusText << "Remaining Health: " << Health << "\nRemaining Mana: " << Mana << "\n";
    TypeText(StatusText.str());
}

void Character::RecoverMana()
{
    if (bIsDead) return;

    int ManaRecovery = 5 + MagicPower;
    std::ostringstream RecoverManaText;
    RecoverManaText << Name << " sits for a moment, and recovers " << ManaRecovery << " Mana!\n";
    TypeText(RecoverManaText.str());

    Mana += ManaRecovery;
    if (Mana > 100)
    {
        Mana = 100;
    }
}


