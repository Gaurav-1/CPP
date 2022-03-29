#include<iostream>
using namespace std;

class Link
{
    struct node
    {
        int data;
        struct node* link;
    };
    struct node* top=NULL;
    struct node* ptr;

    public:
    
    void insertnode(int item)
    {
        ptr=(struct node*)malloc(sizeof(struct node));
        if(ptr==NULL)
        {
        cout<<"\n!!! Overflow !!!"<<endl;
            return;
        }
        else
        {
            if(top==NULL)
            {
                ptr->data=item;
                ptr->link=NULL; }
            else
            {
                ptr->data=item;
                ptr->link=top;
            }
            top=ptr;
        }
    }
    void deletenode()
    {
        if(top==NULL)
            return;
        else
        {
            struct node* temp=top;
            top=top->link;
            delete temp;
        }
    }

    struct node* helper()
    {
        return top;
    }
};
class Stack
{
    Link l;
    public:
    void push(int item)
    {
        l.insertnode(item);
        cout<<"\nItem "<<item<<" is pushed in stack"<<endl;
        return;
    }
    void pop()
    {
        if(l.helper()==NULL)
        {
            cout<<"\nThe Stack is empty"<<endl;
            return;
        }
        else
        {
            cout<<"\nItem "<<l.helper()->data<<" is poped from stack"<<endl;
            l.deletenode();
        }
    }
};
int main()
{
    int ch,item;
    Stack s;
    while(ch)
    {
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter the choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter data: ";
                cin>>item;
                s.push(item);
                break;
            case 2:
                s.pop();
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