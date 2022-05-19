#include <bits/stdc++.h>
using namespace std;

int leftPos(int arr[], int n, int x)
{
    int s = 0;
    int e = n - 1;
    int index = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] == x)
        {
            index = mid;
            e = mid - 1;
        }
        else if (arr[mid] > x)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return index;
}
int rightPos(int arr[], int n, int x)
{
    int s = 0;
    int e = n - 1;
    int index = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] == x)
        {
            index = mid;
            s = mid + 1;
        }
        else if (arr[mid] > x)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return index;
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

    int x;
    cout << "Enter the element to Search for first and last Occ: " << endl;
    cin >> x;

    pair<int, int> p;
    p.first = -1;
    p.second = -1;

    p.first = leftPos(arr, n, x);
    p.second = rightPos(arr, n, x);

    cout << "First Occ: " << p.first << " Second Occ: " << p.second << endl;

    return 0;
}