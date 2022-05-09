#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// DNF sort technique
// TC -> O(N);
// SC -> O(1);

class Solution
{
public:
    void sort012(int a[], int n)
    {
        int low = 0;
        int mid = 0;
        int high = (n - 1);

        while (mid <= high)
        {
            if (a[mid] == 0)
            {
                swap(a[low], a[mid]);
                low++;
                mid++;
            }
            else if (a[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(a[mid], a[high]);
                high--;
            }
        }
    }
};

// BRUTE FORCE APPROACH

// TC -> O(N);
// SC -> O(1);
void sort012(int a[], int n)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            zeroCount++;
        }
        else if (a[i] == 1)
        {
            oneCount++;
        }
        else
        {
            twoCount++;
        }
    }

    // lastPos for loops for 1 and 2
    int lastPos = 0;

    // required count are swaps by zeros
    for (int i = 0; i < n; i++)
    {
        if (zeroCount > 0)
        {
            a[i] = 0;
            zeroCount--;
            lastPos = i;
        }
    }

    for (int i = lastPos + 1; i < n; i++)
    {
        if (oneCount > 0)
        {
            a[i] = 1;
            oneCount--;
            lastPos = i;
        }
    }
    for (int i = lastPos + 1; i < n; i++)
    {
        if (twoCount > 0)
        {
            a[i] = 2;
            twoCount--;
            lastPos = i;
        }
    }
}
