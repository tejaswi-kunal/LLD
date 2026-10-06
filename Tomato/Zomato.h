#include<iostream>

#include "User.h"
#include "Resturant.h"
#include "Order.h"
#include "OrderFactory.h"
#include "ScheduledOrder.h"
#include "NowOrder.h"
#include "OrderFactory.h"
#include "MenuItem.h"
#include "ResturantManager.h"
#include "Cart.h"
#include "NowOrder.h"
#include "PaymentNotification.h"
#include "PaymentStrategy.h"

using namespace std;

class Zomato
{
    public:
    Zomato()
    {
        intiateTheApplication();
    }

    void intiateTheApplication()
    {
        // first we have to create some sample restaurants 
        Resturant* r1=new Resturant("Haldiram","Delhi");
        Resturant* r2=new Resturant("Biryani Mahal","Patna");
        Resturant* r3=new Resturant("Biryani Grills","Patna");
        Resturant* r4=new Resturant("Maurya","Patna");
        Resturant* r5=new Resturant("DhabaA1","Guwahati");

        // now we have to add some items
        r1->addItem(new MenuItem("P1", "Haldiram Chips", 24));
        r1->addItem(new MenuItem("P2", "Raj Kachori", 80));
        r1->addItem(new MenuItem("P3", "Chole Bhature", 120));
        r1->addItem(new MenuItem("P4", "Gulab Jamun", 60));

        r2->addItem(new MenuItem("P1", "Chicken Biryani", 220));
        r2->addItem(new MenuItem("P2", "Mutton Biryani", 280));
        r2->addItem(new MenuItem("P3", "Chicken Kebab", 180));
        r2->addItem(new MenuItem("P4", "Raita", 50));

        r3->addItem(new MenuItem("P1", "Paneer Tikka", 180));
        r3->addItem(new MenuItem("P2", "Butter Chicken", 240));
        r3->addItem(new MenuItem("P3", "Garlic Naan", 60));
        r3->addItem(new MenuItem("P4", "Chicken Tikka", 190));

        r4->addItem(new MenuItem("P1", "Mutton Curry", 280));
        r4->addItem(new MenuItem("P2", "Dal Makhani", 140));
        r4->addItem(new MenuItem("P3", "Paneer Butter Masala", 180));
        r4->addItem(new MenuItem("P4", "Tandoori Roti", 30));

        r5->addItem(new MenuItem("P1", "Chicken Thali", 220));
        r5->addItem(new MenuItem("P2", "Dal Tadka", 120));
        r5->addItem(new MenuItem("P3", "Paneer Masala", 160));
        r5->addItem(new MenuItem("P4", "Butter Naan", 50));

        // now we have to add the resturants in the restaurant list for that we require the resturant manager 
        ResturantManager* resManager=ResturantManager::createResturantManager();
        resManager->addResturants(r1);
        resManager->addResturants(r2);
        resManager->addResturants(r3);
    }

    // first we have to add or register the user 
    User* registerUser(string name,string location)
    {
        User* user=new User(name,location);
        cout<<"User Registered Successfully!"<<endl;
        return user;
    }

    // now we have to search for resturant
    // we assume the client is frontend ,so frontend will give the command what it wants to do and we will make functions for it here 
    vector<Resturant*> searchResturant(string location)
    {
        // for searching we require the resManager
        ResturantManager* resManager=ResturantManager::createResturantManager();
        vector<Resturant*>res=resManager->searchResturant(location);

        cout<<"Result Of Searching : "<<endl;
        for(auto &it : res)
        {
            cout<<it->getName()<<endl;
        }
        cout<<"Please Select Any One Resturant From The Above List"<<endl;
        return res;
    }

    void selectResuturant(User* user,Resturant* res)
    {
        Cart* cart=user->getCart();
        cart->setResturant(res);
        cout<<"Selected "<<res->getName()<<endl;
    }

    // now we have to add items from the Resturant for what the client has requested 
    void addProduct(string code,User* user)
    {
        Cart* cart=user->getCart();
        
        for(auto it : cart->getResturant()->getMenu())
        {
            if(it->getCode()==code)
            {
                cart->addItem(it);
                cout<<"Added "<<endl;
                it->getItem();
            }
        }
    }

    // now we have to check out 
    // we have two options for checkout 
    Order* checkOutNow(User* user,string type)
    {
        OrderFactory* factory=new NowOrderFactory();
        Cart* cart=user->getCart();
        Resturant* res=cart->getResturant();
        Order* order=factory->createOrder(type,user,res,cart->getItems(),cart->calculateTotalPrice());
        cout<<"Total Cost "<<order->getTotalCost()<<endl;
        return order;
    }

    Order* checkOutScheduled(User* user,string type,string orderTime)
    {
        OrderFactory* factory=new ScheduledOrderFactory(orderTime);
        Cart* cart=user->getCart();
        Resturant* res=cart->getResturant();
        Order* order=factory->createOrder(type,user,res,cart->getItems(),cart->calculateTotalPrice());
        cout<<"Total Cost "<<order->getTotalCost()<<endl;
        return order;
    }

    // we have to also dynamically take the Payement Startegy
    void PaymentMethod(Order* order,PaymentStrategy* strategy)
    {
        order->setPaymentStrategy(strategy);
        cout<<"Selected "<<strategy->paymentType()<<endl;
    }

    // now we have to checkout 
    void checkOut(Order* order)
    {
        PaymentStrategy* strategy=order->getPaymentStrategy();
        strategy->pay(order->getTotalCost());
    }

    // once the order has been created now we have to notify the user 
    void notifyUser(Order* order)
    {
        PaymentNotificationService* notificationService=new PaymentNotificationService(order);
        notificationService->notify();
    }
};