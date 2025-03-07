#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <thread>
#include <chrono>
#include "../Character/Character.h"


template <typename T>
class Inventory
{
public:
    //================================================================================================
    //=============================== PROPERTIES & VARIABLES =========================================
    //================================================================================================
    std::vector<std::unique_ptr<T>> Items;
    
    //================================================================================================
    //====================================== FUNCTIONS ===============================================
    //================================================================================================

    void TypeText(const std::string& text)
    {
        for (char c : text) //For each character within the "text" string
        {
            std::cout << c << std::flush; //Print each character immediately
            std::this_thread::sleep_for(std::chrono::milliseconds(35)); //Wait for x milliseconds before printing the next character in the string
        }
    }


    void AddItem(std::unique_ptr<T> Item)
    {
        std::ostringstream GetItemText;
        GetItemText << "You got a " << Item->GetName() << "!\n";
        TypeText(GetItemText.str());
        Items.push_back(std::move(Item));
    }
    
    void RemoveItem(int Index)
    {
        if (Index >= 0 && Index < Items.size())
        {
            //std::cout << "Removed item: " << Items[Index]->GetName() << "\n";
            Items.erase(Items.begin() + Index);
        }
        else
        {
            std::cout << "Invalid index!\n";
        }
    }
    
    void UseItem(int Index, Character& Owner)
    {
        if (Index >= 0 && Index < Items.size())
        {
            Items[Index]->Use(Owner);
            RemoveItem(Index);
        }
        else
        {
            std::cout << "Invalid index!\n";
        }
    }
    
    void ListItems()
    {
        for (int i = 0; i < Items.size(); ++i)
        {
            std::cout << i + 1 << ". " << Items[i]->GetName() << "\n";
        }
        
    }

    int GetSize() 
    {
        if (Items.size() >= 1) 
        {
            return Items.size();
        }
        else 
        {
            return 0;
        }
    }

    T* GetItem(size_t Index)
    {
        if (Index >= 0 && Index < Items.size())
        {
            return Items[Index].get();
        }
        return nullptr;
    }
    
    size_t GetItemCount() const {return Items.size();}
    
};


