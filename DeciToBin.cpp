// Write a program to convert decimal number into their binary equivalent.

#include<iostream>
using namespace std;

int  main(){
    int i,num,arr[10];

    cout<<"Decimal to binary conversion program"<<endl;
    cout<<"Enter a number to convert: ";
    cin>>num;

    for (i = 0;num>0; i++)
    {
        arr[i]=num%2;
        num=num/2;
    }
    
    cout<<"Binary converstion: ";
    for (i = i-1;i>=0; i--)
    {
        cout<<arr[i];
    }
    return 0;
}