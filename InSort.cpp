// Write a program to implement insertion sort using class.

#include<iostream>
using namespace std;

class InSort{
    int i,j,count,temp;
    
    public:
    InSort(){
        cout<<"Insertion Sort program"<<endl;
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
            for(i=1;i<count;i++){
                temp=arr[i];
                for(j=i-1;j>=0;j--){
                    if(arr[j]>arr[j+1]){
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
    InSort IS;
    return 0;
}