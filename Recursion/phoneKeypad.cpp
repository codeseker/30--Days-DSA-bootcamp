#include <bits/stdc++.h>
using namespace std;

void solve(string digits, vector<string> &ans, string tmp, int i, string mapping[])
{
    // base case
    if (i >= digits.length())
    {
        ans.push_back(tmp);
        return;
    }

    int number = digits[i] - '0';
    string value = mapping[number];
    for (int j = 0; j < value.length(); j++)
    {
        tmp.push_back(value[j]);
        solve(digits, ans, tmp, i + 1, mapping);
        tmp.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.length() == 0)
    {
        return ans;
    }
    string tmp;
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, ans, tmp, 0, mapping);
    return ans;
}

int main()
{
    string s;
    cin >> s;

    vector<string> ans = letterCombinations(s);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}