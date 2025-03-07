#include <iostream>
#include <thread>
#include <chrono>
#include "Character/Mage.h"
#include "Character/Goblin.h"
#include "Character/Warrior.h"
#include "System/BattleSystem.h"
#include "System/HealingPotion.h"
#include "System/Inventory.h"
#include "System/ItemBase.h"
#include "System/GeneralGoodsMerchant.h"

bool bStorySkip = false;

void TypeText(const std::string& text) 
{
    for (char c : text) //For each character within the "text" string
    {
        std::cout << c << std::flush; //Print each character immediately

        if (!bStorySkip) 
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(45)); //Wait for x milliseconds before printing the next character in the string

        }
    }
}


int main()
{

    //Initial class selection, more options could be added later
    TypeText("You open your eyes to a world filled with magic and monsters, before you lies a choice, will you choose the wisdom of magecraft, or the glory of strength? \n");
    int choice;
    std::cout << "Choose your class:\n1. Warrior\n2. Mage\n";
    std::cin >> choice;

    Inventory<ItemBase> Inventory;
    std::unique_ptr<Character> Player = nullptr;


    switch (choice)
    {
    case 1:

        Player = std::make_unique<Warrior>();
        break;

    case 2:
        Player = std::make_unique<Mage>();
        break;
    case 45:
        Player = std::make_unique<Mage>();
        Player->MagicPower += 5000;
        Player->Gold += 5000;
        Player->Mana += 5000;
        Player->Health += 9999;
        bStorySkip = true;
        break;
    default:
        TypeText("If you will not decide, I will decide for you! You shall be a Warrior!\n");
        Player = std::make_unique<Warrior>();
        break;
    }

    //Name input for a more personalized feel along the journey
    std::string Name;
    TypeText("What name shall you go by, chosen one?\n");
    std::cin >> Name;
    Player->Name = Name;


    TypeText("You look around yourself and see a small village bustling with people surrounded by a large forest\nWhat will you do? \n");
    std::cout << "1. Visit the shop\n2. Head to the local Church\n3. Wander into the forest\n" << Player->Name << ": ";
    std::cin >> choice;

    //Create the first shop outside of the switch statement to avoid errors. Pass in the Player Inventory and name the Merchant.
    GeneralGoodsMerchant* MerchantSteve = new GeneralGoodsMerchant(Inventory, "Steve the shopkeeper: ");


    switch (choice)
    {
    case 1:
        TypeText("Steve the shopkeeper: Well hello there traveler! You don't look like you're from around here, how can I help?\n");
        TypeText("Steve the shopkeeper: Ah planning to head into the forest are we? I sell various potions here but considering you're doing the village a favour I'll give you this one for free!\n");
        
        //Create the health potion item, and add it to the inventory. Named "Weak health potion" with 35 healing potency
        Inventory.AddItem(std::make_unique<HealingPotion>("Weak Health Potion", 35));
        
        TypeText("Steve the shopkeeper: Feel free to look around still though!\n");
        MerchantSteve->StartShopping(*Player);
        break;
    case 2:
        TypeText("Penelope the Priest: Greetings my child, I can tell you have come from far far away, please help this Village and slay the goblins in the surrounding Forest\n");
        TypeText("Penelope the Priest: I will grant you my blessing of Strength to assist your journey, it will help with your physical attacks. Be safe my child\n");

        //Grant the player a permanent physical damage buff
        Player->AttackPower += 5;
        break;
    case 3:
        //If they do not wish to shop or visit the church, proceed with the story
        break;
    default:
        break;
    }

    //Cleanup
    delete MerchantSteve;

    TypeText("After finishing your business in the Village you decide to head into the forest\n");
    TypeText("Wandering around the forest for some time, it appears you have become lost\n\n");

    //Create the first encounter using the BattleSystem and Character classes
    Character* FirstGoblin = new Goblin();
    BattleSystem* FirstBattle = new BattleSystem(Inventory);
    
    //Begin the fight and end when either the player or Enemy character is dead
    //TODO: Add flee option based on character/enemy agility
    FirstBattle->StartBattle(*Player, *FirstGoblin);
    if (FirstBattle->bPlayerDied)
    {
        //End the fight and cleanup objects
        delete FirstBattle;
        delete FirstGoblin;
    }

    if (FirstBattle->bEnemyDied)
    {
        delete FirstGoblin;
        delete FirstBattle;

        //Add a health potion to the inventory of the player as a reward for beating the goblin and reward 50 gold
        Player->Gold += 50;
        Inventory.AddItem(std::make_unique<HealingPotion>("Health Potion", 50));
    }

    TypeText("After claiming Victory in your first battle, you continue traversing the vast forest\n");
    TypeText("Step *crunch* step *crunch\n");
    TypeText("Step *crunch* step *crunch\n\n");
    TypeText("Walking for some time, eventually you spot someone up ahead\n");
    TypeText("Pete the Potion Seller: Oh thank goodness! I've been lost in this forest for hours, could you point me in the direction of the nearest village?\n");
    TypeText("Pete the Potion Seller: Thank you so much! Whilst I am here, would you like to browse my wares?\n");

    //Second shop interaction using the same system as the first, but with another merchant name
    GeneralGoodsMerchant* MerchantPete = new GeneralGoodsMerchant(Inventory, "Pete the Potion Seller: ");
    MerchantPete->StartShopping(*Player);

    //Cleanup
    delete MerchantPete;

    //Repeat for the second encounter
    Character* SecondGoblin = new Goblin();
    BattleSystem* SecondBattle = new BattleSystem(Inventory);
    SecondGoblin->Name = "Mighty Goblin King Boblin";

    SecondBattle->StartBattle(*Player, *SecondGoblin);
    if (SecondBattle->bPlayerDied)
    {
        delete SecondBattle;
        delete SecondGoblin;
    }

    if (SecondBattle->bEnemyDied)
    {
        delete SecondGoblin;
        delete SecondBattle;
        Inventory.AddItem(std::make_unique<HealingPotion>("Health Potion", 50));
    }
    
    TypeText("You have sucessfully cleared out the Goblin camp and slain the Mighty Goblin King Boblin!\n");
    TypeText("After returning to the Village, the villagers sing your praises and you are revered by the Chief\n");
    TypeText("However unbeknownst to you, a far greater threat looms in the distance..\n\n");

    TypeText("To be continued..\n");



    return 0;
}
