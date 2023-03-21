#include <iostream>
using namespace std;
struct Node
{
    long phoneno;
    string name;
    struct Node *add;
    int srno;
}*head = NULL;

class LinkedList
{
    public:
    int sr = 0;
    void add();
    void deleteRecord(int);
    void displayAll();
    void displaySpecific(string);
};

void LinkedList::add()
{
    
    struct Node *temp = new Node;
    long v1;
    string v2;
    
    cout<<"Name: "<<endl;
    cin>>v2;
    cout<<"Phone Number: "<<endl;
    cin>>v1;
    
    temp->add = NULL;
    temp->name = v2;
    temp->phoneno = v1;
    sr++;
    temp->srno=sr;
    
    
    
    
    
    if(head==NULL)
    {
        
        head = temp;
    }
    
    else
    {
        struct Node *p = new Node;
        p=head;
        
        while(p->add!=NULL)
        {
            p= p->add;
        }
        
        p->add = temp;
        
    }
}

void LinkedList::deleteRecord()
{
        int schoice;
        cout<<"Enter the Serial Number of the record to peremenantly delete the record"<<endl;
        cin>>schoice;
        
        struct Node *p = new Node;
        struct Node *prev = new Node;
        
        if(schoice<1)
        {
            cout<<"Invalid serail number kindly check again"<<endl;
        }
        else if(schoice==1)
        {
            p=head;
            cout<<p->name<<"'s record has been deleted"<<endl;
            head=p->add;
            delete p;
        }
        else
        {
            p = head;
            for(int i=1;i<loc-1;i++)
            {
                if(p!=NULL)
                {
                    p=p->add;
                }
            }
        }
}
void LinkedList::displayAll()
{
        struct Node *p = new Node;
        p=head;
        
        while(p!=NULL)
        {
            cout<<"Sr no: "<<p->srno<<" Name: "<<p->name<<" Phone No: "<<p->phoneno<<endl;
            p= p->add;
        }
        
}

void LinkedList::displaySpecific(string temp)
{
        struct Node *p = new Node;
        p=head;
        while(p!=NULL)
        {
            if(p->name==temp)
            {
                cout<<"Name: "<<p->name<<" Phone No: "<<p->phoneno<<endl;
                break;
            }
            else
            {
                p= p->add;
            }
        }
        
        if(p->name!=temp)
        {
            cout<<"Invalid Name"<<endl;
            cout<<"Try checking the spelling again for "<<temp<<endl;
        }
}


int main()
{
    LinkedList ll;
    int choice;
    
    do
    {
        cout<<"Choose any one of the following"<<endl;
        cout<<"1) Add Member in the directory"<<endl;
        cout<<"2) Display someone's number"<<endl;
        cout<<"3) Delete a record"<<endl;
        cout<<"4) Display all numbers"<<endl;

        cin>>choice;


        switch(choice)
        {
            case 1:ll.add();
            break;
            case 2:
            {
                string s1;
                cout<<"Who's number are you looking for"<<endl;
                cin>>s1;
                ll.displaySpecific(s1);
                break;
                
                
            }
            case 3:
            {
                ll.displayAll();
                ll.deleteRecord();
                
                
            }
            case 4:ll.displayAll();
            break;
        }
        
    }while(true);
    
}