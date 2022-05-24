#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, vector<vector<int>> &res, vector<int> tmp, int i)
{
    // base case
    if (i == nums.size())
    {
        res.push_back(tmp);
        return;
    }

    // exclude
    solve(nums, res, tmp, i + 1);
    // include

    tmp.push_back(nums[i]);
    // res.push_back(tmp);
    solve(nums, res, tmp, i + 1);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> tmp;

    solve(nums, res, tmp, 0);
    return res;
}

int main()
{
    
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }

    vector<vector<int> > ans = subsets(nums);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}