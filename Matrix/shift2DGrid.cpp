#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<int> res;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            res.push_back(a[i][j]);
        }
    }

    int k;
    cout<<"Enter the value to shift: "<<endl;
    cin>>k;

    while(k--)
    {
        int i = 0;
        int j = res.size()-1;

        while(i != j)
        {
            swap(res[i], res[j]);
            i++;
        }
    }

    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            a[i][j] = res[(m)*i + j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}
