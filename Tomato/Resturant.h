#pragma once

#include<iostream>
#include "MenuItem.h"

using namespace std;

class Resturant
{
    private:
    string name;
    string location;
    int id;
    static int nextId;
    vector<MenuItem*>menu;

    public:
    Resturant(string name,string location)
    {
        this->name=name;
        this->id=++nextId;
        this->location=location;
    }

    void addItem(MenuItem *m)
    {
        menu.push_back(m);
    }

    void showMenu()
    {
        for(auto &it : menu)
        {
            it->getItem();
        }
    }

    string getLocation()
    {
        return location;
    }

    string getName()
    {
        return name;
    }

    vector<MenuItem*> getMenu()
    {
        return menu;
    }
};

int Resturant::nextId=0;

