// TC -> O(N);
// SC -> O(N);
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        vector<int> res;
        for(int i=0; i<=r; i++)
        {
            res.push_back(arr[i]);
        }
        
        sort(res.begin(), res.end());
        
        return res[k-1];
    }
};