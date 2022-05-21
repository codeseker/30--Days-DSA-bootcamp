// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array.
    void swap(vector<int> &arr,int i, int j)
    {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
	int minSwaps(vector<int>&nums)
	{
	    unordered_map<int, int> h;
	    vector<int> tmp;
	    for(auto i:nums)
	    {
	        tmp.push_back(i);
	    }
	    sort(tmp.begin(), tmp.end());
	    for(int i=0; i<nums.size(); i++)
        {
            h[nums[i]] = i;
        }
        
        int cnt = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != tmp[i])
            {
                cnt++;
                int init = nums[i];
              // If not, swap this element
              // with the index of the
              // element which should come here
              swap(nums, i, h[tmp[i]]);
        
              // Update the indexes in
              // the hashmap accordingly
              h[init] = h[tmp[i]];
              h[tmp[i]] = i;
            }
        }
        
        return cnt;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends