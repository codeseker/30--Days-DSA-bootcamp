// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        sort(arr, arr+n);
        
        int i=0;
        int j = n-1;
        int cnt = 0;
        
        while(i<j)
        {
            if((arr[i] + arr[j]) == k)
            {
                cnt++;
                int m = i+1;
                
                while(m < j && (arr[m] + arr[j]) == k)
                {
                    cnt++;
                    m++;
                }
                j--;
            }
            else if((arr[i] + arr[j]) > k)
            {
                j--;
            }
            else{
                i++;
            }
        }
        
        return cnt;
    }

    // USING HASHMAPS

    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int, int> m;

        // Store counts of all elements in map m
        for (int i = 0; i < n; i++) 
            m[arr[i]]++;
        
        int twice_count = 0;
        // iterate through each element and increment the
        // count (Notice that every pair is counted twice)
        for (int i = 0; i < n; i++) {
            twice_count += m[k - arr[i]];

            // if (arr[i], arr[i]) pair satisfies the condition,
            // then we need to ensure that the count is
            // decreased by one such that the (arr[i], arr[i])
            // pair is not considered
            if (k - arr[i] == arr[i]) twice_count--;
        }

        // return the half of twice_count
        return twice_count / 2;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends