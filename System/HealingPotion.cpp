#include "HealingPotion.h"
#include <iostream>
#include "../Character/Character.h"


void HealingPotion::Use(Character& Owner)
{
    std::cout << "You used a healing potion! Healed " << HealAmount << " Health!\n";
    Owner.Health += HealAmount;
}

std::string HealingPotion::GetName()
{
    return Name;
}
