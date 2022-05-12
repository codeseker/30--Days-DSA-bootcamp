// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
 // MERGE SORT APPROACH 
//  TC O(NLOGN)

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long *arr, long long s, long long e, long long &cnt)
    {
        long long mid = s + (e - s) / 2;
    
        long long len1 = mid - s + 1;
        long long len2 = e - mid;
        long long *first = new long long[len1];
        long long *second = new long long[len2];
        long long k = s;
        for (int i = 0; i < len1; i++)
        {
            first[i] = arr[k++];
        }
        k = mid + 1;
        for (int i = 0; i < len2; i++)
        {
            second[i] = arr[k++];
        }
    
        // merge both arays
        long long i = 0;
        long long j = 0;
        //int l = 0;
        k = s;
        while (i < len1 && j < len2)
        {
            if (first[i] <= second[j])
            {
                arr[k] = first[i];
                k++;
                i++;
            }
            else
            {
                arr[k] = second[j];
                cnt += (len1-i);
                k++;
                j++;
            }
        }
        while (i < len1)
        {
            arr[k] = first[i];
            k++;
            i++;
        }
        while (j < len2)
        {
            arr[k] = second[j];
            k++;
            j++;
        }
    }

    void mergeSort(long long *arr, int s, long long e, long long &cnt)
    {
        if (s >= e)
        {
            return;
        }
    
        long long mid = s + (e - s) / 2;
        // leftPart sort kar
        mergeSort(arr, s, mid, cnt);
    
        // rigth part sort kar
        mergeSort(arr, mid + 1, e, cnt);
    
        // merge both arrays
        merge(arr, s, e, cnt);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long cnt = 0;
        mergeSort(arr, 0, N-1, cnt);
        return cnt;
    }

    // BRUTE FORCE APPROACH 
    // TC O(N^2)

    long long int inversionCount(long long arr[], long long n)
    {
        long long cnt = 0;
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(arr[i] > arr[j] && i<j)
                {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends