#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> merge(vector<int> &a, vector<int> &b)
    {
        vector<int> res;

        int i = 0;
        int j = 0;
        int n = a.size();
        int m = b.size();

        while (i < n && j < m)
        {
            if (a[i] <= b[j])
            {
                res.push_back(a[i]);
                i++;
            }
            else
            {
                res.push_back(b[j]);
                j++;
            }
        }
        while (i < n)
        {
            res.push_back(a[i]);
            i++;
        }
        while (j < m)
        {
            res.push_back(b[j]);
            j++;
        }

        return res;
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(n + m);
        res = merge(nums1, nums2);
        int size = res.size();
        if (size % 2 != 0)
        {
            int mid = (size + 1) / 2;
            double ans = res[mid - 1];
            return ans;
        }
        else
        {
            int mid1 = (size / 2);
            int mid2 = ((size / 2) + 1);
            double ans = ((double)res[mid1 - 1] + (double)res[mid2 - 1]) / 2;
            return ans;
        }
    }
};

int main()
{

    return 0;
}