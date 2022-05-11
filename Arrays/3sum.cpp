// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    // TC O(N^2)
    // 3 POINTER APPROACH V.V.V.IMP
    void merge(int *arr, int s, int e)
    {
        int mid = s + (e - s) / 2;

        int len1 = mid - s + 1;
        int len2 = e - mid;
        int *first = new int[len1];
        int *second = new int[len2];
        int k = s;
        for (int i = 0; i < len1; i++)
        {
            first[i] = arr[k++];
        }
        k = mid + 1;
        for (int i = 0; i < len2; i++)
        {
            second[i] = arr[k++];
        }

        // merge both arays
        int i = 0;
        int j = 0;
        // int l = 0;
        k = s;
        while (i < len1 && j < len2)
        {
            if (first[i] < second[j])
            {
                arr[k] = first[i];
                k++;
                i++;
            }
            else
            {
                arr[k] = second[j];
                k++;
                j++;
            }
        }
        while (i < len1)
        {
            arr[k] = first[i];
            k++;
            i++;
        }
        while (j < len2)
        {
            arr[k] = second[j];
            k++;
            j++;
        }
    }

    void mergeSort(int *arr, int s, int e)
    {
        if (s >= e)
        {
            return;
        }

        int mid = s + (e - s) / 2;
        // leftPart sort kar
        mergeSort(arr, s, mid);

        // rigth part sort kar
        mergeSort(arr, mid + 1, e);

        // merge both arrays
        merge(arr, s, e);
    }
    bool find3Numbers(int a[], int n, int x)
    {
        mergeSort(a, 0, n - 1);
        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                if (a[i] + a[j] + a[k] == x)
                {
                    return true;
                }
                else if (a[i] + a[j] + a[k] > x)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}
// } Driver Code Ends