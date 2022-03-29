#include<iostream>
using namespace std;

void swap(int *arr,int ar[])
{
    int temp;
    temp=arr[0];
    arr[0]=ar[0];
    ar[0]=temp;
}

void heap(int *arr,int n,int i)
{
    int lar=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[lar])
        lar=l;
    if(r<n && arr[r]>arr[lar])
        lar=r;
    if(lar!=i)
    {
        swap(arr[i],arr[lar]);
        heap(arr,n,lar);
    }
}

void sort(int *arr,int n)
{
    for(int i=n/2-1;i>=0;i--)
        heap(arr,n,i);
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heap(arr,i,0);
    }
}

void res(int *arr,int n)
{
    cout<<"\nAfter sorting: "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;
}

int main()
{
    int n;
    cout<<"\nEnter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter array elements: "<<endl;

    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,n);
    res(arr,n);
    return 0;
}