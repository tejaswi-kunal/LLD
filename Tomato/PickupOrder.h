#pragma once

#include<iostream>
#include "Order.h"

using namespace std;

class PickupOrder : public Order
{
    private:
    string resAddress;

    public:
    PickupOrder(User* user,Resturant* resturant,vector<MenuItem*>items,string &resAddress,int totalCost,string orderTime):Order(user,resturant,items,totalCost,orderTime)
    {
        this->resAddress=resAddress;
    }

    string getType()
    {
        return "PickUP";
    }
};