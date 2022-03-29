#include<iostream>
using namespace std;

class DblLink
{
    struct node
    {
        int data;
        struct node* next;
        struct node* prev;
    };
    struct node* start=NULL;
    struct node* last=NULL;
    struct node* ptr;

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
                start=(struct node*)malloc(sizeof(struct node));
                start->data=item;
                start->next=NULL;
                start->prev=NULL;
                last=(struct node*)malloc(sizeof(struct node));
                last=start;
            }
            else
            {
                ptr->data=item;
                node* temp=start;
                ptr->next=start;
                ptr->prev=NULL;
                start=ptr;
                temp->prev=start;
            }
                cout<<"Node is inserted at beginning"<<endl;
        }
    }

    int search(int item)
    {
        struct node* temp=start;
        if(start==NULL)
        {
            cout<<"!!! Underflow !!! "<<endl;
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
                temp=temp->next;
            }
        }
    return 0;
    }
};
int main()
{
    int ch,item;
    DblLink d;
    while(ch)
    {
        cout<<"1. Insert"<<endl;
        cout<<"2. Search"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter the choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter data: "<<endl;
                cin>>item;
                d.insertbeg(item);
                break;
            case 2:
                cout<<"\nEnter the element to be searched: ";
                cin>>item;
                if(d.search(item)==0)
                cout<<"!!! Element not found !!!"<<endl;
                break;
            case 3:
                cout<<"\nExited"<<endl;
                return 0;
                break;
            default:
                cout<<"\nWrong choice"<<endl;
                break;
        }
    }
    return 0;
}