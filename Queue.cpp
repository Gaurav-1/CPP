#include<iostream>
using namespace std;

class Queue
{
    int rear=-1,front=0,queue[10],size=10;

    public:
    
    void insert(int item)
    {
        if(rear==size)
            cout<<"!!! Queue is full !!!"<<endl;
        else
        {
            rear++;
            queue[rear]=item;
            cout<<"The "<<item<<" item is inserted"<<endl;
        }
    }
    void del()
    {
        if(front==-1 || rear<front)
            cout<<"The Queue is empty"<<endl;
        else
        {
            cout<<"The "<<queue[front]<<" element is deleted"<<endl;
            front++;
        }
    }
};
int main()
{
    int item,ch;
    Queue q;
    while(ch)
    {
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter the choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter data: ";
                cin>>item;
                q.insert(item);
                break;
            case 2:
                q.del();
                break;
            case 3:
                cout<<"\nExited"<<endl;
                return 0;
                break;
            default:
                cout<<"\n!!!nWrong choice !!!"<<endl;
                break;
        }
    }
    return 0;
}