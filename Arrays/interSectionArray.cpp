#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res;
        int i = 0;
        int j = 0;
        while(i<n && j<m)
        {
            if(nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j])
            {
                j++;
            }
            else{
                i++;
            }
        }
        return res;
    }
    vector<int> removeDup(vector<int>& res)
    {
        vector<int> ans;
        unordered_map<int, bool> visited;
        
        for(auto i:res)
        {
            if(!visited[i])
            {
                ans.push_back(i);
                visited[i] = true;
            }
        }
        
        return ans;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res = solve(nums1, nums2);
        
        res = removeDup(res);
        return res;
    }
};

int main(){



    return 0;
}