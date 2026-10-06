#pragma once

#include<iostream>
#include "Order.h"

using namespace std;

class DeliveryOrder : public Order
{
    private:
    string userAddress;

    public:
    DeliveryOrder(User* user,Resturant* resturant,vector<MenuItem*>items,string &userAddress,int totalCost,string orderTime):Order(user,resturant,items,totalCost,orderTime)
    {
        this->userAddress=userAddress;
    }

    string getType()
    {
        return "Delivery";
    }
};

