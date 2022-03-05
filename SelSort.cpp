// Write a program to implement selection sort using class.

#include<iostream>
using namespace std;

class SelSort{
    int num,count,i,j,temp,index;

    public:
        SelSort(){
            cout<<"Selection Sort program"<<endl;
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
            for(i=0;i<count-1;i++){
                index=i;
                for(j=i+1;j<count;j++){
                    if(arr[index]>arr[j]){
                        index=j;
                    }
                }
                temp=arr[index];
                arr[index]=arr[i];
                arr[i]=temp;
            }
            for ( i = 0; i < count; i++)
            {
                cout<<arr[i]<<endl;
            }
            return 0;
        }
};
int main(){
    SelSort SS;
    return 0;
}