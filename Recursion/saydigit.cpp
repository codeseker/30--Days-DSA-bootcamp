#include <bits/stdc++.h>
using namespace std;

void say(int n, string arr[])
{
    // base case
    if (n == 0)
    {
        return;
    }

    // cout << rev << endl;

    int x = n % 10;
    cout << arr[x] << " ";
    say(n / 10, arr);
}

int main()
{
    int n;
    cin >> n;
    string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int rev = 0;
    while (n != 0)
    {
        int x = n % 10;
        rev = rev * 10 + x;
        n = n / 10;
    }
    say(rev, arr);
    return 0;
}