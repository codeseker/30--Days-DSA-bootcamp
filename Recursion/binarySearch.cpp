#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int s, int e, int x)
{
    // base case
    if (s > e)
    {
        return -1;
    }

    int mid = s + (e - s) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }
    else if (arr[mid] > x)
    {
        return search(arr, n, s, mid - 1, x);
    }
    else
    {
        return search(arr, n, mid + 1, e, x);
    }
}

int main()
{
    int arr[] = {1,2,3,4,5};

    cout<<"Index is: "<<search(arr, 5, 0, 4, 5)<<endl;
    return 0;
}