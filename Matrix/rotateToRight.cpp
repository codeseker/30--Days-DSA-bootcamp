#include <iostream>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;

    int mat[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    int k;
    cout << "Enter the value to shift: " << endl;
    cin >> k;

    while (k--)
    {
        for (int i = 0; i < n; i++)
        {
            int s = 0;
            int e = m - 1;

            while (s <= e)
            {
                swap(mat[i][s], mat[i][e]);
                s++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}