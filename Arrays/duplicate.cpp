#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution
{
public:
    // TC O(NLOGN);
    // SC O(N)
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return nums[i];
            }
        }
        return -1;
    }

    // TC O(N)
    // SC O(N)
    int findDuplicate2(vector<int> &nums)
    {
        unordered_map<int, bool> visited;
        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[nums[i]] == false)
            {
                visited[nums[i]] = true;
            }
            else
            {
                return nums[i];
            }
        }
        return -1;
    }

    // best approach
    int findDuplicate(vector<int> &nums)
    {
        int duplicate = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            int cur = abs(nums[i]);
            if (nums[cur] < 0)
            {
                duplicate = cur;
                break;
            }
            nums[cur] *= -1;
        }

        // Restore numbers
        for (auto &num : nums)
            num = abs(num);

        return duplicate;
    }
};

int main()
{

    int a = 10;
    cout << 0 - a << endl;

    return 0;
}