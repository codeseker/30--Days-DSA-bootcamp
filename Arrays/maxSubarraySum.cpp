#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSum(int arr[], int n)
{
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int sum = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            sum += arr[j];
            res.push_back(sum);
        }
    }

    int ans = INT_MIN;

    for (auto i : res)
    {
        ans = max(ans, i);
    }

    return ans;
}

// kadanes algo
// TC O(N)
// SC O(1)

long long maxSubarraySum(int arr[], int n)
{

    long long max_sum = INT_MIN;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (max_sum < sum)
        {
            max_sum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return max_sum;
}

int main()
{

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = maxSum(arr, n);
    cout << "Ans is: " << ans << endl;

    return 0;
}