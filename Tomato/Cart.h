#pragma once 

#include <iostream>
#include "MenuItem.h"
#include "Resturant.h"

using namespace std;

class Cart
{
    private:
    vector<MenuItem*>items;
    Resturant* resturant;

    public:
    Cart()
    {

    }

    void setResturant(Resturant* resturant)
    {
        this->resturant=resturant;
    }

    void addItem(MenuItem* item)
    {
        items.push_back(item);
    }

    int calculateTotalPrice()
    {
        int totalPrice=0;
        for(auto &it : items)
        {
            totalPrice+=it->getPrice();
        }
        return totalPrice;
    }

    Resturant* getResturant()
    {
        return resturant;
    }

    vector<MenuItem*> getItems()
    {
        return items;
    }

};