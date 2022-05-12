// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    
	    if(n == 1)
	    {
	        return arr[0];
	    }
	    
	    long long max_product = INT_MIN;
	    long long curr = 1;
	    
	    // traverse left to right
	    for(int i=0; i<n; i++)
	    {
	        curr = curr * (arr[i]);
	        max_product = max(max_product, curr);
	        if(curr == 0)
	        {
	            curr = 1;
	        }
	    }
	    curr = 1;
	    
	    // traverse right top left
	    
	    for(int i=n-1; i>=0; i--)
	    {
	        curr = curr * arr[i];
	        max_product = max(max_product, curr);
	        if(curr == 0)
	        {
	            curr = 1;
	        }
	    }
	    
	    return max_product;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends