#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n, int i)
{
    // base case
    if (i >= n)
    {
        return true;
    }

    if (arr[i] > arr[i + 1])
    {
        return false;
    }
    return isSorted(arr, n, i + 1);
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    if(isSorted(arr, n, 0))
    {
        cout<<"Sorted"<<endl;
    }
    else{
        cout<<"Not Sorted"<<endl;
    }
    return 0;
}