// Write a program to implement Linear search using class.

#include<iostream>
using namespace std;

class LiSearch{
    int count,i,num;
    bool flag;

    public:
    LiSearch(){
        cout<<"Linear Search program"<<endl;
        cout<<"Enter the size of numbers you want to enter: ";
        cin>>count;
        int arr[count];
        entery(arr);
        search(arr);
    }

    int entery(int *arr){
        cout<<"Enter elements: \n";
        for (i = 0; i < count; i++)
            cin>>arr[i];
        return 0;
    }

    int search(int *arr){ 
        i=0;
        cout<<"Enter element you want to find: ";
        cin>>num;
        for (i = 0; i < count; i++)
        {
            if(arr[i]==num){
                cout<<"Element found at location: "<<i+1<<endl;
                flag=true;
                break;
            }
            else
                flag=false;
        }
        if (flag==false)
        {
            cout<<"!!! Element not found !!!";
        }
        
        return 0;
    }
    
};
int main(){
    LiSearch LS;
    return 0;
}