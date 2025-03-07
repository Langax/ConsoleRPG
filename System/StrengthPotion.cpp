#include "StrengthPotion.h"
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include "../Character/Character.h"

void StrengthPotion::TypeText(const std::string& text)
{
    for (char c : text) //For each character within the "text" string
    {
        std::cout << c << std::flush; //Print each character immediately
        std::this_thread::sleep_for(std::chrono::milliseconds(35)); //Wait for x milliseconds before printing the next character in the string
    }
}

void StrengthPotion::Use(Character& Owner)
{
    std::ostringstream UsageText;
    UsageText << "You used a " << Name << "! Your physical damage increased by " << StrengthIncrease << "!\n";
    TypeText(UsageText.str());
    Owner.AttackPower += StrengthIncrease;
}


