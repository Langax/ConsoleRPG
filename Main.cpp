#include <iostream>

#include "Character/Mage.h"
#include "Character/Goblin.h"
#include "Character/Warrior.h"
#include "System/BattleSystem.h"

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
        std::cout << "If you will not decide, I will decide for you. You shall be a Warrior!\n";
        Player = new Warrior();
        break;
    }

    std::string Name;
    std::cout << "What name shall you go by, chosen one?\n";
    std::cin >> Name;
    Player->Name = Name;
    
    Character* FirstGoblin = new Goblin();
    BattleSystem* FirstBattle = new BattleSystem();
    
    FirstBattle->StartBattle(*Player, *FirstGoblin);
    if (FirstBattle->bPlayerDied)
    {
        delete Player;
        delete FirstBattle;
    }

    if (!FirstBattle->bInCombat)
    {
        delete FirstGoblin;
        delete FirstBattle;
    }


    delete Player;
    delete FirstBattle;
    return 0;
}
