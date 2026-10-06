#pragma once

#include<iostream>
#include "PaymentStrategy.h"

using namespace std;

class UPIStrategy : public PaymentStrategy
{
    public:
    void pay(int amount) override{
        cout<<"Paid "<<amount<<"$ Using UPI"<<endl;
    }

    string paymentType() override
    {
        return "Credit Card";
    }
};


