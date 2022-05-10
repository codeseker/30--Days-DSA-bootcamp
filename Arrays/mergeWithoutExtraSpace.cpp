#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
  
   void merges(int arr[], int l, int mid, int r){
       int n1 = mid-l+1;
       int n2 = r-mid;
       int a[n1];
       int b[n2];
       for(int i=0; i<n1; i++)
       {
           a[i] = arr[l+i];
       }
       for(int i=0; i<n2; i++)
       {
           b[i] = arr[mid+1+i];
       }
       int t = 0;
       int y = 0;
       int p = l;
       
       while(t<n1 && y<n2)
       {
           if(a[t]<b[y])
           {
               arr[p] = a[t];
               p++;
               t++;
           }
           else{
               arr[p] = b[y];
               p++;
               y++;
           }
       }
       while(t<n1)
       {
           arr[p] = a[t];
           p++;
           t++;
       }
       while(y<n2)
       {
           arr[p] = b[y];
           p++;
           y++;
       }
   }
   void mergeSort(int arr[], int l, int r)
   {
       if(l<r)
       {
           int mid = (l+r)/2;
           mergeSort(arr,l,mid);
           mergeSort(arr,mid+1,r);
           merges(arr,l,mid,r);
       }
   }
   
	void merge(int arr1[], int arr2[], int n, int m) {
	    int i=n-1;
	    int j=0;
	    while(i>=0 && j<m)
	    {
	        if(arr1[i]>arr2[j])
	        {
	            int temp = arr1[i];
	            arr1[i] = arr2[j];
	            arr2[j] = temp;
	            i--;
	            j++;
	        }
	        else{
	            break;
	        }
	    }
	   mergeSort(arr1,0,n-1);
	   mergeSort(arr2,0,m-1);
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends