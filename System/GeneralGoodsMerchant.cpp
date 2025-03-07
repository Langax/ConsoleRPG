#include "GeneralGoodsMerchant.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include "../Character/Character.h"
#include "../System/Inventory.h"
#include "../System/HealingPotion.h"
#include "../System/ManaPotion.h"
#include "../System/StrengthPotion.h"




void GeneralGoodsMerchant::TypeText(const std::string& text)
{
    for (char c : text) //For each character within the "text" string
    {
        std::cout << c << std::flush; //Print each character immediately
        std::this_thread::sleep_for(std::chrono::milliseconds(35)); //Wait for x milliseconds before printing the next character in the string
    }
}


void GeneralGoodsMerchant::StartShopping(Character& Player) 
{
	while (bShopping) 
	{
        std::ostringstream WelcomeText;
        WelcomeText << Name << "Welcome to the store! What can I do for you today?\n";
        TypeText(WelcomeText.str());
        std::cout << "1. Buy\n2. Sell\n3. Leave\n" << Player.Name << ": ";
        int choice;
        std::cin >> choice;
        switch (choice) 
        {
        case 1:
            TypeText("What would you like to purchase today?\n");
            std::cout << "1. Health Potion  - 50 Gold\n2. Strength Potion  - 75 Gold\n3. Mana Potion  - 75 Gold\nYour Gold: " << Player.Gold << "\n" << Player.Name << ": ";
            int BuyChoice;
            std::cin >> BuyChoice;
            switch (BuyChoice)
            {
            case 1:
                if (Player.Gold <= 49) 
                {
                    TypeText("You don't have enough gold for that one!\n");
                    std::cout << "Your gold: " << Player.Gold << "\n";
                    break;
                }
                else 
                {
                    PlayerInventory.AddItem(std::make_unique<HealingPotion>("Health Potion", 50));
                    Player.Gold -= 50;
                    break;
                }
            case 2:
                if (Player.Gold <= 74)
                {
                    TypeText("You don't have enough gold for that one!\n");
                    std::cout << "Your gold: " << Player.Gold << "\n";
                    break;
                }
                else
                {
                    PlayerInventory.AddItem(std::make_unique<StrengthPotion>("Strength Potion", 3));
                    Player.Gold -= 75;
                    break;
                }
            case 3:
                if (Player.Gold <= 74)
                {
                    TypeText("You don't have enough gold for that one!\n");
                    std::cout << "Your gold: " << Player.Gold << "\n";
                    break;
                }
                else
                {
                    PlayerInventory.AddItem(std::make_unique<ManaPotion>("Mana Potion", 30));
                    Player.Gold -= 75;
                    break;
                }
            default: break;
            }
            break;
        case 2:
            TypeText("What are you looking to sell?\n");
            if (PlayerInventory.GetSize() >= 1) 
            {
                PlayerInventory.ListItems();
                std::ostringstream SellItemText;
                SellItemText << "Which item would you like to sell? (1-" << PlayerInventory.GetItemCount() << "): ";
                TypeText(SellItemText.str());

                int ItemChoice;
                std::cin >> ItemChoice;
                if (ItemChoice >= 1 && ItemChoice <= PlayerInventory.GetItemCount())
                {
                    ItemBase* SelectedItem = PlayerInventory.GetItem(ItemChoice - 1);
                    Player.Gold = Player.Gold + SelectedItem->SellValue;
                    std::ostringstream SoldItemText;
                    SoldItemText << "You sold your " << SelectedItem->Name << " for " << SelectedItem->SellValue << " Gold!\n";
                    TypeText(SoldItemText.str());
                    PlayerInventory.RemoveItem(ItemChoice - 1);
                }
                break;
            }
            else 
            {
                TypeText("You don't have any items available to sell!\n");
                break;
            }
            break;
        case 3:
            bShopping = false;
            break;
        default: 
            bShopping = false;
            break;
        }
	}
}