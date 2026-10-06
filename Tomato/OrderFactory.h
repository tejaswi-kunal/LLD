#pragma once 

#include<iostream>
#include "Order.h"
#include "User.h"
#include "OrderFactory.h"
#include "MenuItem.h"

using namespace std;

class OrderFactory
{
    private:
    Order* order;

    public:
    virtual Order* createOrder(string &type,User* user,Resturant* resturant,vector<MenuItem*>items,int totalCost)=0;

    virtual ~OrderFactory()=default;
};