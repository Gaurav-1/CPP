// Write a program to implement Bubble sort using class.

#include<iostream>
using namespace std;

class BubSort{
    int i,j,count,temp;
    
    public:
    BubSort(){
        cout<<"Bubble Sort program"<<endl;
        cout<<"Enter the size of numbers you want to enter: ";
            cin>>count;
            int arr[count];
            insert(arr);
            sort(arr);
    }
    int insert(int *arr){
            cout<<"Enter elements: \n";
            for (i = 0; i < count; i++)
                cin>>arr[i];
            return 0;
    }
    int sort(int *arr){
        cout<<"After sorting:"<<endl;
        for(i=0;i<count;i++){
            for(j=0;j<count-1;j++){
                if(arr[j]>arr[j+1]){
                    temp=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=temp;
                }
            }
            
        }
        for ( i = 0; i < count; i++)
        cout<<arr[i]<<endl;
        return 0;
    }
};

int main(){
    BubSort BS;
    return 0;
}