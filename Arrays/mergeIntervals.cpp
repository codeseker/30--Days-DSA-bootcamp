#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:

    // TC O(NLOGN)
    // SC O(N)
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals)
        {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0])
            {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else
            {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};

//  TC O(N)
// SC O(1)
void solve(int arr[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i][1] >= arr[i + 1][0])
        {
            cout << arr[i][0] << " " << arr[i + 1][1] << " ";
            i += 1;
        }
        else
        {
            cout << arr[i][0] << " " << arr[i][1] << " ";
        }
    }
}

int main()
{

    int arr[][2] = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};

    solve(arr, 4);

    return 0;
}