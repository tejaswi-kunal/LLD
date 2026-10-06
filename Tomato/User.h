#pragma once

#include<iostream>
#include "Cart.h"

using namespace std;

class User
{
    private:
    string name;
    int id;
    static int nextId;
    string location;
    Cart* cart;

    public:
    User(string &name,string &location)
    {
        this->name=name;
        this->location=location;
        this->cart=new Cart();
        this->id=++nextId;
    }

    string getAddress()
    {
        return location;
    }

    string getName()
    {
        return name;
    }

    Cart* getCart()
    {
        return cart;
    }
};

int User::nextId=0;