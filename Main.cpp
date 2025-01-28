#include <iostream>
#include "Character/Mage.h"
#include "Character/Goblin.h"
#include "Character/Warrior.h"
#include "System/BattleSystem.h"
#include "System/HealingPotion.h"
#include "System/Inventory.h"
#include "System/ItemBase.h"

int main()
{
    std::cout << "You open your eyes to a world filled with magic and monsters, before you lies a choice, will you choose the wisdom of magecraft, or the glory of strength? \n";

    Inventory<ItemBase> Inventory;
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
    BattleSystem* FirstBattle = new BattleSystem(Inventory);
    
    FirstBattle->StartBattle(*Player, *FirstGoblin);
    if (FirstBattle->bPlayerDied)
    {
        delete Player;
        delete FirstBattle;
    }

    if (FirstBattle->bEnemyDied)
    {
        delete FirstGoblin;
        delete FirstBattle;
        Inventory.AddItem(std::make_unique<HealingPotion>("Health Potion", 50));
    }


    Character* SecondGoblin = new Goblin();
    BattleSystem* SecondBattle = new BattleSystem(Inventory);

    SecondBattle->StartBattle(*Player, *SecondGoblin);
    if (SecondBattle->bPlayerDied)
    {
        delete Player;
        delete SecondBattle;
    }

    if (SecondBattle->bEnemyDied)
    {
        delete SecondGoblin;
        delete FirstBattle;
        Inventory.AddItem(std::make_unique<HealingPotion>("Health Potion", 50));
    }
    

    delete Player;
    return 0;
}
