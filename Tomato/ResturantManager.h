#pragma once

#include<iostream>
#include "Resturant.h"

using namespace std;

// now this is the class for managing the resturants ,saving it in db,adding resurants ,deleting and yes searching on the basis of its location
class ResturantManager
{   
    private:
    static ResturantManager* instance;
    vector<Resturant*>resturants;

    ResturantManager()
    {

    }

    public:
    static ResturantManager* createResturantManager()
    {
        if(instance==nullptr)
        {
            instance=new ResturantManager();
        }

        return instance;
    }

    void addResturants(Resturant* resturant)
    {
        resturants.push_back(resturant);
    }

    vector<Resturant*> searchResturant(string &location)
    {
        vector<Resturant*>searchResult;
        for(auto &it : resturants)
        {
            if(location==it->getLocation())
            {
                searchResult.push_back(it);
            }
        }

        return searchResult;
    }

    // we can add other methods to manage restuarnt like string in db and the cleanup method as its the job of Resutant manager to apply the 
    // clean up its entity objects
};

ResturantManager* ResturantManager::instance=nullptr;
