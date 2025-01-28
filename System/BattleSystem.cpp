#include "BattleSystem.h"
#include <iostream>
#include "../Character/Character.h"


void BattleSystem::StartBattle(Character& Player, Character& Enemy)
{
    std::cout << "You've encountered a " << Enemy.Name << ", prepare to fight!\n";
    while (bInCombat)
    {
        if (bPlayerTurn)
        {
            size_t ItemChoice;
            size_t ItemCount = PlayerInventory.GetItemCount();
            if (Player.ClassID == 1)
            {
                std::cout << "\nHow would you like to act?\n1. Attack\n2. Heal\n3. Use Item\n";
                int choice;
                std::cin >> choice;


                switch(choice)
                {
                case 1:
                    Player.Attack(Enemy);
                    bEnemyTurn = true;
                    bPlayerTurn = false;
                    break;
                case 2:
                    Player.Heal();
                    bEnemyTurn = true;
                    bPlayerTurn = false;
                    break;
                case 3:
                    PlayerInventory.ListItems();
                    std::cout << "Which item would you like to use? (1-" << ItemCount <<"): ";
                    std::cin >> ItemChoice;

                    if (ItemChoice >= 1 && ItemChoice <= ItemCount)
                    {
                        ItemBase* SelectedItem = PlayerInventory.GetItem(ItemChoice - 1);
                        SelectedItem->Use(Player);
                    }
                    break;
                default: ;
                }
            }
            else if (Player.ClassID == 2)
            {
                std::cout << "\nHow would you like to act?\n1. Attack\n2. Heal\n3. Recover Mana\n4. Use Item\n";
                int choice;
                std::cin >> choice;

                switch(choice)
                {
                case 1:
                    Player.Attack(Enemy);
                    bEnemyTurn = true;
                    bPlayerTurn = false;
                    break;
                case 2:
                    Player.Heal();
                    bEnemyTurn = true;
                    bPlayerTurn = false;
                    break;
                case 3:
                    Player.RecoverMana();
                    bEnemyTurn = true;
                    bPlayerTurn = false;
                    break;
                case 4:
                    PlayerInventory.ListItems();
                    std::cout << "Which item would you like to use? (1-" << ItemCount <<"): ";
                    std::cin >> ItemChoice;

                    if (ItemChoice >= 1 && ItemChoice <= ItemCount)
                    {
                        ItemBase* SelectedItem = PlayerInventory.GetItem(ItemChoice - 1);
                        SelectedItem->Use(Player);
                    }
                    break;
                default: ;
                }
            }

            if (Player.bIsDead)
            {
                std::cout << "You failed your mission.. Try again when you are better prepared\n";
                bInCombat = false;
                bPlayerDied = true;
            }

            if (Enemy.bIsDead)
            {
                std::cout << "Congratulations! You have proven your strength and won your battle!\n";
                bInCombat = false;
                bEnemyDied = true;
            }
        }

        
        else if (bEnemyTurn)
        {
            Enemy.Attack(Player);
            bPlayerTurn = true;
            bEnemyTurn = false;
            Enemy.Status();
            Player.Status();
        }

        
        else
        {
            break;
        }
    }
}
