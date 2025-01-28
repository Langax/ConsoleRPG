#include <iostream>

#include "Character/Mage.h"
#include "Character/Goblin.h"
#include "Character/Warrior.h"

int main()
{
    std::cout << "You open your eyes to a world filled with magic and monsters, before you lies a choice, will you choose the wisdom of magecraft, or the glory of strength? \n";
    
    Character* Player = nullptr;
    int choice;
    std::cout << "Choose your class:\n1. Warrior\n2. Mage\n";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        Player = new Warrior();
        break;

    case 2:
        Player = new Mage();
        break;
    default:
        std::cout << "If you will not decide, I will decide for you. You shall be a Warrior!";
        Player = new Warrior();
        break;
    }

    
    Character* Enemies[3];
    Enemies[0] = new Goblin();
    Enemies[1] = new Goblin();
    Enemies[2] = new Goblin();
    
    Player->Attack(*Enemies[0]);
    Player->Heal();

    if (Enemies[0]->bIsDead == true)
    {
        delete Enemies[0];
    }
    
    delete Player;
    return 0;
}
