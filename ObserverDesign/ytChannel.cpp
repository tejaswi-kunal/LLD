#include<iostream>

using namespace std;

class IObserver
{
    public:
    virtual void update()=0;
};

class IObserverable
{
    public:
    virtual void add(IObserver* o)=0;
    virtual void remove(IObserver* o)=0;
    virtual void notify()=0;

};

// now we have to make the concrete class of the above interfaces ,
// for IObservable it will be something like yt channel ,facebook channel and other things which can be observed and many
// observers are connected to it so whenever there is any change in it ,it have to notify all its users
// for IObserver it can be user of any platform which has subsribed any of there services and we have notify it 

class YtChannel : public IObserverable
{
    private:
    // it will maintain list of all its subscribers 
    string name;
    vector<IObserver*>subscribers;
    string newVide;
    public:
    YtChannel(string name)
    {
        this->name=name;
    }

    void add(IObserver* o) override 
    {
        subscribers.push_back(o);
        cout<<"Subscribed Successfully"<<endl;
    }

    void remove(IObserver* o) override
    {
        for(int i=0;i<subscribers.size();i++)
        {
            if(subscribers[i]==o){
                swap(subscribers[i],subscribers[subscribers.size()-1]);
                subscribers.pop_back();
                cout<<"Unsubsribed Successfully"<<endl;
            }
        }
    }

    void uploadNewVideo(string title)
    {
        cout<<"New Video Uploaded By "<<name<<endl;
        this->newVide=title;
        notify();
    }

    // we have to notify all the subsribers when new video uploads
    void notify() override
    {
        for(auto it : subscribers)
        {
            it->update();
        }
    }

    string getName()
    {
        return name;
    }

    string getNewVideo()
    {
        return newVide;
    }
    
};

class Subscriber : public IObserver
{
    private:
    string username;
    YtChannel* channel;
    // this subsrriber will also have a has-a relation with the yt channle so that when the notification cames it will get 
    // to know ohh the new video has been uploaded by this channnel
    // we can provide that through the notify function
    public:
    Subscriber(string name,YtChannel* channel)
    {
        this->username=name;
        this->channel=channel;
    }

    void update() override
    {
        cout<<username<<" Got Notification For The Video Uploaded By "<<channel->getName()<<" Whose Video Title Is "<<channel->getNewVideo()<<endl;
    }
};

int main()
{
    YtChannel* CoderArmy=new YtChannel("Coder Army");

    Subscriber* u1=new Subscriber("Tejaswi",CoderArmy);
    Subscriber* u2=new Subscriber("Kunal",CoderArmy);

    CoderArmy->add(u1);
    CoderArmy->add(u2);


    CoderArmy->uploadNewVideo("Hello");
    return 0;
}