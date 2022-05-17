#include <iostream>
using namespace std;
#include <vector>

// if transpose is equal to the original matrix than the matrix is said to be symetric


// TC O(N*M)
// SC O(N*M)
vector<vector<int>> transpose(vector<vector<int>> matrix, int n, int m)
{
    vector<vector<int>> res(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res[i][j] = matrix[j][i];
        }
    }

    return res;
}
bool isMatrixSymmetric(vector<vector<int>> matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> b(n, vector<int>(m));

    b = transpose(matrix, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] != b[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{

    return 0;
}