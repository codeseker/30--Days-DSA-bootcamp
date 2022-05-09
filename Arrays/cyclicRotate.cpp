// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}
// } Driver Code Ends


//User function Template for C++


// TC = O(N);
// SC = O(N);
void rotate(int arr[], int n)
{
    vector<int> res;
    res.push_back(arr[n-1]);
    for(int i=0; i<n-1; i++)
    {
        res.push_back(arr[i]);
    }
    
    for(int i=0; i<res.size(); i++)
    {
        arr[i] = res[i];
    }
    
}

// TC = O(N);
// SC = O(1);
void rotate2(int arr[], int n)
{
    int i=0;
     int j = n-1;
     
     while(i != j)
     {
         swap(arr[i], arr[j]);
         i++;
     }
    
}