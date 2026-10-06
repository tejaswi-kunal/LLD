#pragma once

#include<iostream>
#include "User.h"
#include "Resturant.h"
#include "MenuItem.h"
#include "PaymentStrategy.h"

using namespace std;

// we will have two diffrent types of order ->Delivery order ,Pickup order 

class Order
{
    private:
    User* user;
    Resturant* resturant;
    vector<MenuItem*>items;
    PaymentStrategy* paymentStrategy;
    int totalCost;
    string orderTime;

    public:
    virtual string getType()=0;

    Order(User* user,Resturant* resturant,vector<MenuItem*>items,int totalCost,string orderTime)
    {
        this->user=user;
        this->items=items;
        this->resturant=resturant;
        this->totalCost=totalCost;
        this->orderTime=orderTime;
    }

    // we will dynamically set the payement startegy
    void setPaymentStrategy(PaymentStrategy* paymentStrategy)
    {
        if(this->paymentStrategy==nullptr && paymentStrategy!=nullptr)
        this->paymentStrategy=paymentStrategy;

        else 
        {
            cout<<"Invalid Operation"<<endl;
        }
    }

    virtual ~Order()
    {
        delete paymentStrategy;
    }

    User* getUser()
    {
        return user;
    }

    int getTotalCost()
    {
        return totalCost;
    }

    string getOrderTime()
    {
        return orderTime;
    }

    PaymentStrategy* getPaymentStrategy()
    {
        return paymentStrategy;
    }
};

