//Write a program to find Sum of n natural numbers using class.

#include<iostream>
using namespace std;

int main(){
    int num,i=0,sum=0;
    char flag;

    cout<<"Sum of natural number program"<<endl;
    cout<<"Enter the numbers you want to check: ";
    cin>>num;
// you can skip this section
    cout<<"Enter manualy y/n: ";
    cin>>flag;

    int numArr[num];
    if(flag=='y')
        cout<<"Enter numbers:"<<endl;
    while (flag=='y'&&i<num)
    {
        cin>>numArr[i];
        i++;
    }
// till this
    for(i=0;i<num;i++){
        if (flag=='y')      //this section also
            sum=sum+numArr[i]; //this section also
        else
            sum=sum+i;
    }
    cout<<"Sum: "<<sum;
    return 0;
}