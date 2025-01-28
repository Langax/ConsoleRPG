#pragma once

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
    //================================================================================================
    //====================================== FUNCTIONS ===============================================
    //================================================================================================

    void StartBattle(Character& Player, Character& Enemy);
};

