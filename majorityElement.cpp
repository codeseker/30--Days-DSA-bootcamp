class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = INT_MAX, ele2 = INT_MAX;
        int cnt1 = 0, cnt2 = 0;

        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(cnt1 == 0 && nums[i] != ele2) {
                cnt1 = 1;
                ele1 = nums[i];
            } else if(cnt2 == 0 && nums[i] != ele1) {
                cnt2 = 1;
                ele2 = nums[i];
            } else if(ele1 == nums[i]) {
                cnt1++;
            } else if(ele2 == nums[i]) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for(auto it: nums) {
            if(it == ele1) {
                cnt1++;
            } else if(it == ele2) {
                cnt2++;
            }
        }

        vector<int> ans;
        if(cnt1 > (n/3)) {
            ans.push_back(ele1);
        }
        if(cnt2 > (n/3)) {
            ans.push_back(ele2);
        }

        return ans;
    }
};