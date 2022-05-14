#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int sum(vector<int> nums, int j, int n)
    {
        int sum = 0;
        for(int i=j; i<n; i++)
        {
            sum += nums[i];
        }
        return sum;
    }
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        {
            return 0;
        }
        
        int leftSum = 0;
        int rightSum = 0;
        for(int i=0; i<n; i++)
        {
            if(i == 0)
            {
                leftSum = 0;
            }
            else{
                leftSum += nums[i-1];
            }
            rightSum = sum(nums, i+1, n);
            if(i == n-1)
            {
                rightSum = 0;
            }
            if(leftSum == rightSum)
            {
                return i;
            }
        }
        return -1;
    }
};

int main(){



    return 0;
}