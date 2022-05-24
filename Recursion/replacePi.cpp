#include <bits/stdc++.h>
using namespace std;

void replace(string s, int i)
{
    // base case
    if (i == s.length())
    {
        return;
    }

    if (s[i] == 'p' && s[i + 1] == 'i')
    {
        cout << "3.14";
        replace(s, i + 2);
    }
    else
    {
        cout << s[i];
        replace(s, i + 1);
    }
}

int main()
{
    string s;
    cin >> s;

    replace(s, 0);
    return 0;
}