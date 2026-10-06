#pragma once

#include<iostream>

using namespace std;

// we will have 3 diffrent types of payment strategy which will override this payment Strategt interfcae
class PaymentStrategy
{
    public:
    virtual void pay(int amount)=0;

    virtual string paymentType()=0;

    virtual ~PaymentStrategy()=default;
};