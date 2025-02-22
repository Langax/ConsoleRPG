#pragma once
#include "Inventory.h"
#include "ItemBase.h"

class Character;

class BattleSystem
{
public:
    //================================================================================================
    //=============================== PROPERTIES & VARIABLES =========================================
    //================================================================================================
    bool bInCombat = true;
    
    // Always begin with the player turn (could be optimized to be random later)
    bool bPlayerTurn = true;
    bool bEnemyTurn = false;

    bool bPlayerDied = false;
    bool bEnemyDied = false;

    Inventory<ItemBase>& PlayerInventory;
    //================================================================================================
    //====================================== FUNCTIONS ===============================================
    //================================================================================================
    BattleSystem(Inventory<ItemBase>& Inventory) : PlayerInventory(Inventory) {}
    void StartBattle(Character& Player, Character& Enemy);
};

