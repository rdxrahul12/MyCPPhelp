#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>& arr)
{
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main()
{
    vector<int> arr={12,11,13,5,6};
    cout<<"Given array:\n";
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubble_sort(arr);
    cout<<"Sorted array:\n";
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}