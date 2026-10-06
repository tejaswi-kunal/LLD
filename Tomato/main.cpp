// now this main will work as the client ,we will send all the requested data to the main as we used to send the 
// to write the code just think client as frontend and we will use the fuctions in the  zomato like teh apis
// those functions are nothing the apis which are using the internal desgins

#include<iostream>
#include "UPIStrategy.h"
#include "Zomato.h"

using namespace std;

int main()
{
    // first we have to intiate the app
    Zomato* app=new Zomato();

    // now we have to register the user 
    User* user =  app->registerUser("Tejaswi","Patna");

    // now we have to serach the restraurnt
    vector<Resturant*>res = app->searchResturant("Patna");

    // now we have to select the restarunt 
    // for ui lets assume the use has selected the first restaurnt 
    app->selectResuturant(user,res[0]);

    // now user have to add the items in the cart 
    app->addProduct("P1",user);
    app->addProduct("P2",user);

    // now the user will checkout
    Order* order=app->checkOutNow(user,"Delivery");

    // now we have to select payement method 
    app->PaymentMethod(order,new UPIStrategy());

    // now we have to checkout
    app->checkOut(order);

    // now we have to notify the user 
    app->notifyUser(order);

    return 0;
}