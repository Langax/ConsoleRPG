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
            if (Player.ClassID == 1)
            {
                std::cout << "\nHow would you like to act?\n1. Attack\n2. Heal\n";
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
                default: ;
                }
            }
            else if (Player.ClassID == 2)
            {
                std::cout << "\nHow would you like to act?\n1. Attack\n2. Heal\n3. Recover Mana\n";
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
                default: ;
                }
            }

            if (Player.bIsDead)
            {
                std::cout << "You failed your mission.. Try again when you are better prepared";
                bInCombat = false;
                bPlayerDied = true;
            }

            if (Enemy.bIsDead)
            {
                std::cout << "Congratulations! You have proven your strength and won your battle!";
                bInCombat = false;
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
