#include <bits/stdc++.h>
using namespace std;

int square(int x)
{
    int s = 0;
    int e = x;

    while (s <= e)
    {
        long long mid = s + (e - s) / 2;
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid > x)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return e;
}

int main()
{
    int n;
    cin >> n;

    cout<< "Sqaure root is: "<< square(n)<<endl;
    return 0;
}