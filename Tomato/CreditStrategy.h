#pragma once;

#include<iostream>
#include "PaymentStrategy.h"

using namespace std;

class CreditStrategy : public PaymentStrategy
{
    void pay(int amount) override
    {
        cout<<"Paid "<<amount<<"$ Using Credit Card"<<endl;
    }

    string paymentType() override
    {
        return "Credit Card";
    }
};
