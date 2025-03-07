#include "BattleSystem.h"
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include "../Character/Character.h"


void BattleSystem::TypeText(const std::string& text)
{
    for (char c : text) //For each character within the "text" string
    {
        std::cout << c << std::flush; //Print each character immediately
        std::this_thread::sleep_for(std::chrono::milliseconds(28)); //Wait for x milliseconds before printing the next character in the string
    }
}

void BattleSystem::StartBattle(Character& Player, Character& Enemy)
{
    std::ostringstream EncounterText;
    EncounterText << "You've encountered a " << Enemy.Name << ", prepare to fight!\n";
    TypeText(EncounterText.str());

    while (bInCombat)
    {
        if (bPlayerTurn)
        {
            size_t ItemChoice;
            size_t ItemCount = PlayerInventory.GetItemCount();
            if (Player.ClassID == 1)
            {
                std::cout << "\nHow would you like to act?\n1. Attack\n2. Heal\n3. Use Item\n" << Player.Name << ": ";
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
                    if (PlayerInventory.GetSize() >= 1)
                    {
                        PlayerInventory.ListItems();
                        std::ostringstream ItemChoiceText;
                        ItemChoiceText << "Which item would you like to use? (1-" << ItemCount << "): ";
                        TypeText(ItemChoiceText.str());
                        std::cin >> ItemChoice;

                        if (ItemChoice >= 1 && ItemChoice <= ItemCount)
                        {
                            PlayerInventory.UseItem(ItemChoice - 1, Player);
                        }
                        break;
                    }
                    else 
                    {
                        TypeText("You do not have any items avilable! \n");
                    }

                default: ;
                }
            }
            else if (Player.ClassID == 2)
            {
                std::cout << "\nHow would you like to act?\n1. Attack\n2. Heal\n3. Recover Mana\n4. Use Item\n" << Player.Name << ": ";
                int choice;
                std::cin >> choice;

                switch(choice)
                {
                case 1:
                    if (Player.Attack(Enemy)) 
                    {
                        bEnemyTurn = true;
                        bPlayerTurn = false;
                        break;
                    }
                    else 
                    {
                        break;
                    }
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
                    if (PlayerInventory.GetSize() >= 1)
                    {
                        PlayerInventory.ListItems();
                        std::ostringstream ItemChoiceText;
                        ItemChoiceText << "Which item would you like to use? (1-" << ItemCount << "): ";
                        TypeText(ItemChoiceText.str());
                        std::cin >> ItemChoice;

                        if (ItemChoice >= 1 && ItemChoice <= ItemCount)
                        {
                            PlayerInventory.UseItem(ItemChoice - 1, Player);
                        }
                        break;
                    }
                    else
                    {
                        TypeText("You do not have any items avilable! \n");
                    }
                default: ;
                }
            }


        }

        
        else if (bEnemyTurn)
        {
            if (Enemy.Health <= 50 and Enemy.Mana >= 15) 
            {
                Enemy.Heal();
            }
            else 
            {
                Enemy.Attack(Player);
            }
            bPlayerTurn = true;
            bEnemyTurn = false;

            if (Player.bIsDead)
            {
                TypeText("You failed your mission.. Try again when you are better prepared\n");
                bInCombat = false;
                bPlayerDied = true;
                return;
            }

            if (Enemy.bIsDead)
            {
                TypeText("Congratulations! You have proven your strength and won your battle!\n");
                bInCombat = false;
                bEnemyDied = true;
                return;
            }

            Enemy.Status();
            Player.Status();
        }

        
        else
        {
            break;
        }
    }
}

