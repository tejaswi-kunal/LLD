// once the order is created we have to notify the user 
#pragma once

#include<iostream>
#include "Order.h"
#include "User.h"

using namespace std ;

class PaymentNotificationService
{
    Order* order;
    public:
    PaymentNotificationService(Order* order)
    {
        this->order=order;
    }

    void notify()
    {
        User* user=order->getUser();
        int totalCost=order->getTotalCost();

        cout<<"Orderd Successfully"<<endl;
        cout<<"Name : "<<user->getName()<<endl;
        cout<<"Total Cost : "<<totalCost<<"$"<<endl;
        cout<<"At : "<<order->getOrderTime()<<endl;
    }   
    
};