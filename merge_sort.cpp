#include<bits/stdc++.h>
using namespace std;

void merge( vector<int> &arr,int left, int mid, int right)
{
    int n1 = mid-left+1;
    int n2 =  right-mid;
    
    vector<int>a(n1),b(n2);
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[left+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k++]=a[i++];
        }
        else
        {
            arr[k++]=b[j++];
        }
    }
    while(i<n1)
    {
        arr[k++]=a[i++];
    }
    while(j<n2)
    {
        arr[k++]=b[j++];
    }
}

void merge_sort(vector<int>& arr,int left,int right)
{
    if(left>=right)
    return;
    
    int mid=(left+right)/2;
    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1,right);
    merge(  arr,left,mid,right);

}

int main()
{
    vector<int> arr={12,11,13,5,6};
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    merge_sort(arr,0,4);
    cout<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}