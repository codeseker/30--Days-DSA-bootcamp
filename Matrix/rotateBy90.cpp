#include <iostream>
#include <vector>
using namespace std;

// shifting is done in clockwise direction

class Solution {
public:

    // TC O(N*M)
    // SC O(N*M)
    void rotate(vector<vector<int>>& matrix) {
        
        // row reverse se transpose krna h
        int n = matrix.size();
        int m = matrix[0].size();
        
        int b[n][m];
        
        // reverse order me store krr
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                b[i][j] = matrix[n-i-1][j];
            }
        }
        
        // ab iska transpose nikal
        int c[n][m];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                c[i][j] = b[j][i];
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                matrix[i][j] = c[i][j];
            }
        }
    }
};

class Solution {
public:

    // TC O(N*M)
    // SC O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<m; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // now for each row reverse the row using 2 pointer
        for(int i=0; i<n; i++)
        {
            int s = 0;
            int e = n-1;
            
            while(s < e)
            {
                swap(matrix[i][s], matrix[i][e]);
                s++;
                e--;
            }
        }
    }
};

int main()
{

    

    

    return 0;
}