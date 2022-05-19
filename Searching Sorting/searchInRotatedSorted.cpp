#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums, int n)
    {
        int s = 0;
        int e = n - 1;

        while (s < e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] >= nums[0])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        }

        return s;
    }
    int binarySearch(vector<int> &nums, int target, int s, int e)
    {
        int start = s;
        int end = e;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int pivot = pivotIndex(nums, n);

        if (target >= nums[pivot] && target <= nums[n - 1])
        {
            return binarySearch(nums, target, pivot, n - 1);
        }
        else
        {
            return binarySearch(nums, target, 0, pivot - 1);
        }
    }
};

int main()
{

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    
    return 0;
}