//Write a program to check a string is palindrome or not

#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int length,i,flag=0;
    char str[20];

    cout<<"Enter a string: ";
    cin>>str;

    length=strlen(str);
    for(i=0;i<length;i++){
        if(str[i]!=str[length-i-1]){
            flag=1;
            break;
        }
    }
    if(flag)
        cout<<"[ "<<str<<" ]"<<"is not palindrome";
    else
        cout<<"[ "<<str<<" ]"<<"is palindrome";

    return 0;
}