// Write a program to implement Binary search using class.

#include<iostream>
using namespace std;

class BiSearch{
    int count,i,num,beg=0,mid,end;
    bool flag;

    public:
    BiSearch(){
        cout<<"Binary Search program"<<endl;
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
        return -1;
    }

    int search(int *arr){ 
        i=0;
        cout<<"Enter element you want to find: ";
        cin>>num;
        end=count;
        while(beg<=end)
        {
            mid=beg+(end-beg)/2;
            if (arr[mid] == num){
                cout<<"Element "<<arr[mid]<<" found at location "<<mid+1;
                flag=true;
                break;
            }

            if (arr[mid] < num){
                beg = mid + 1;
                flag=false;
            }
            else if (arr[mid]>num){
                end = mid - 1;
                flag=false;
            }
        }

        if (flag==false)
        {
            cout<<"!!! Element not found !!!";
        }
        
        return -1;
    }
};

int main(){
    BiSearch BS;
    return 0;
}