#pragma once

#include<iostream>

using namespace std;

class MenuItem
{
    private:
    string code;
    string name;
    int price;

    public:

    // constructor
    MenuItem(string code,string name,int price)
    {
        this->code=code;
        this->name=name;
        this->price=price;
    }

    // now getter setter
    void getItem()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Price : "<<price<<endl;
    }

    int getPrice()
    {
        return price;
    }

    string getCode()
    {
        return code;
    }
};
