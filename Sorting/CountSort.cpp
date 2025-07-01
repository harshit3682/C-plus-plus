#include"./header.h"
using namespace std;

vector<char> countSort(vector<char>inputArr,int n)
{
    int maxi = *max_element(inputArr.begin(), inputArr.end());

    vector<int>freq(maxi+1,0);// Frequency Array..
    for(auto it:inputArr)
    {
        freq[it]++;
    }

    // Cumulative Frequency:  
    for(int i=1;i<freq.size();i++)
    {
        freq[i]=freq[i-1]+freq[i];
    }

    vector<char>outputArr(n);
    for(int i=n-1;i>=0;i--)
    {
        outputArr[freq[inputArr[i]]-1]=inputArr[i];
        freq[inputArr[i]]--;
    }
    return outputArr;
} 


int main()
{
    int t;
    cout<<"Enter TestCases: ";
    cin>>t;

    while(t--)
    {
        int n;
        cout<<"Enter no. of alphabets: ";
        cin>>n;
    
        cout<<"Input Array: ";
        vector<char>inputArr(n);
        for(int i=0;i<n;i++)
        {
            cin>>inputArr[i];
        }
        
        vector<char>outputArr=countSort(inputArr,n);

        cout<<"Sorted Array: "<<endl;
        
        int maxi=1;
        for(auto it:outputArr)
        {
            cout<<it<<" ";
        }
        cout<<endl<<endl;

    }

}