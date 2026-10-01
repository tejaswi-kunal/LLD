#include<iostream>

using namespace std;

class Product
{
    public:
    string name;
    int price;

    
    Product(string name,int price)
    {
        this->name=name;
        this->price=price;
    }
};


class ShoppingCart
{
    public:
    vector<Product*>products;
    
    void addProduct(Product *p)
    {
        products.push_back(p);
        cout<<"Added "<<p->name<<", Price : "<<p->price<<endl;
    }

    void calculteTotalPrice()
    {
        int total=0;

        for(auto &it : products)
        {
            total+=it->price;
        }

        cout<<"Total Price of the Cart: "<<total<<"$"<<endl;
    }

    void numberOfProducts()
    {
        int count=products.size();
        cout<<"Total Number of Products In the Shopping Cart : "<<count<<endl;
    }
};

class SaveToDB
{
    public:
    virtual void Save(ShoppingCart *sc)=0;
};

class SaveToMongoDB : public SaveToDB
{
    public:
    void Save(ShoppingCart *sc) override
    {
        cout<<"Saving the date to MongoDB"<<endl;
    }
};

class SaveToFile : public SaveToDB
{
    public:
    void Save(ShoppingCart *sc) override 
    {
        cout<<"Saving The Data to File"<<endl;
    }
};

class SaveToSQL : public SaveToDB
{
    public:
    void Save(ShoppingCart *sc) override 
    {
        cout<<"Saving The Data To SQL"<<endl;
    }
};

class PrintInvoice
{
    public:
    void printingTheInvoice(ShoppingCart *sc)
    {
        cout<<"Printing the Invoice"<<endl;
    }
};


int main()
{
    ShoppingCart sc;
    sc.addProduct(new Product("Apple",30));
    sc.addProduct(new Product("Samsung",70));

    sc.calculteTotalPrice();
    sc.numberOfProducts();

    SaveToDB* sv1=new SaveToMongoDB;
    sv1->Save(&sc);

    SaveToDB* sv2=new SaveToFile;
    sv2->Save(&sc);

    SaveToDB* sv3=new SaveToSQL;
    sv3->Save(&sc);

    PrintInvoice* p=new PrintInvoice;
    p->printingTheInvoice(&sc);

    return 0;

}