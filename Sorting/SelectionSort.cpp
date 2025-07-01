#include<iostream>
using namespace std;
void selectionSort(int arr[],int n)
{
        for(int i=0;i<n;i++)
        {
                int min=i;
                for(int j=i+1;j<n;j++)
                {
                        if(arr[min] > arr[j])
                        {
                                min=j;
                        }
                }
                swap(arr[i],arr[min]);
                
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
        int arr[6]={22,1,3,7,11,9};
        selectionSort(arr,6);
        print(arr,6);
}