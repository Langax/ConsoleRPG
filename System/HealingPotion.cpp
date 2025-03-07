#include "HealingPotion.h"
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include "../Character/Character.h"

void HealingPotion::TypeText(const std::string& text)
{
    for (char c : text) //For each character within the "text" string
    {
        std::cout << c << std::flush; //Print each character immediately
        std::this_thread::sleep_for(std::chrono::milliseconds(35)); //Wait for x milliseconds before printing the next character in the string
    }
}

void HealingPotion::Use(Character& Owner)
{
    std::ostringstream UsageText;
    UsageText << "You used a " << Name << "! Healed " << HealAmount << " Health!\n";
    TypeText(UsageText.str());
    Owner.Health += HealAmount;
}

