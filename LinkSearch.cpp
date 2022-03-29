// Write a program to implement searching in linked list using class.

#include<iostream>
using namespace std;
    
class LinkSearch
{
    struct node
    {
        int data;
        struct node* link;
    };
    struct node* start=NULL;
    struct node* ptr;
    int size=0;
    public:
    void insertbeg(int item)
    {
        ptr=(struct node*)malloc(sizeof(struct node));
        if(ptr==NULL)
        {
            cout<<"!!! Overflow !!!"<<endl;
            return;
        }
        else
        {
            if(start==NULL)
            {
                ptr->data=item;
                ptr->link=NULL;
                size++;
            }
            else
            {
                ptr->data=item;
                ptr->link=start;
                size++;
            }
            start=ptr;
            cout<<"Node is inserted in starting"<<endl<<endl;
        }
    }

    int search(int item)
    {
        struct node* temp=start;
        if(start==NULL)
        {
            cout<<"!!! Underflow !!!"<<endl;
            return -1;
        }
        int counter=0;
        while(temp!=NULL)
        {
            if(temp->data == item)
            {
                cout<<"The element location is: "<<++counter<<endl<<endl;
                return -1;
            }
            else
            {
                counter++;
                temp=temp->link;
            }
        }
        return 0;
    }
};
int main()
{
    int ch=1,item;
    LinkSearch l;
    cout<<"Search in LinkList"<<endl;
    while(ch)
    {
        cout<<"1. Insert"<<endl;
        cout<<"2. Search "<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter the choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter data: ";
                cin>>item;
                l.insertbeg(item);
                break;
            
            case 2:
                cout<<"\nEnter the element to search: ";
                cin>>item;
                if(l.search(item)==0)
                cout<<"!!! Element not found !!!"<<endl<<endl;
                break;

            case 3:
                cout<<"\nExited"<<endl;
                return 0;
                break;
            
            default:
                cout<<"\n!!! Wrong choice !!!"<<endl;
                break;
        }
    }
    return 0;
}