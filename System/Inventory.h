#pragma once
#include <iostream>
#include <vector>
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

    void AddItem(std::unique_ptr<T> Item)
    {
        std::cout << "You got a " << Item->GetName() << "!\n";
        Items.push_back(std::move(Item));
    }
    
    void RemoveItem(int Index)
    {
        if (Index >= 0 && Index < Items.size())
        {
            std::cout << "Removed item: " << Items[Index]->GetName() << "\n";
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


