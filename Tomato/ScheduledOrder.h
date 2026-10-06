#pragma once

#include<iostream>
#include "Order.h"
#include "PickupOrder.h"
#include "DeliveryOrder.h"
#include "User.h"
#include "OrderFactory.h"
#include "MenuItem.h"

using namespace std;

class ScheduledOrderFactory : public OrderFactory
{
    string orderTime;
    public:
    ScheduledOrderFactory(string &orderTime)
    {
        this->orderTime=orderTime;
    }

    Order* createOrder(string &type,User* user,Resturant* resturant,vector<MenuItem*>items,int totalCost) override
    {
        Order* order=nullptr;
        if(type=="PickUp")
        {
            string resAddress=resturant->getLocation();
            order=new PickupOrder(user,resturant,items,resAddress,totalCost,orderTime);
            return order;
        }

        else
        {
            string userAddress=user->getAddress();
            order=new DeliveryOrder(user,resturant,items,userAddress,totalCost,orderTime);
            return order;
        }
    }
};
