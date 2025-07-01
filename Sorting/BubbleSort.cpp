#include<iostream>
using namespace std;

int bubbleSort(int arr[],int n)
{
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n-1-i;j++)
                {
                        if(arr[j]>arr[j+1])
                        {
                                swap(arr[j],arr[j+1]);
                        }

                }
        }
}
void print(int arr[],int n)
{
        cout<<"Printing Elements..."<<endl;
        for(int i=0;i<n;i++)
        {
                cout<<arr[i]<<" ";
        }
}
int main()
{
        int arr[6]={3,1,5,2,6,4};
        bubbleSort(arr,6);
        print(arr,6);
}