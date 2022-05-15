// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    // TC O(R*C)
    // SC O(R*C)
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> res;
        
        int row_start = 0;
        int row_end = r-1;
        int col_start = 0;
        int col_end = c-1;
        
        while(row_start <= row_end && col_start <= col_end)
        {
            // print first row
            for(int i=col_start; row_start <= row_end && col_start <= col_end && i<=col_end; i++)
            {
                res.push_back(matrix[row_start][i]);
            }
            row_start++;
            
            
            // print last col
            for(int i=row_start; row_start <= row_end && col_start <= col_end && i<=row_end; i++)
            {
                res.push_back(matrix[i][col_end]);
            }
            col_end--;
            // print last row reverse order
            for(int i=col_end; row_start <= row_end && col_start <= col_end && i>=col_start; i--)
            {
                res.push_back(matrix[row_end][i]);
            }
            row_end--;
            // print first col rev order
            for(int i=row_end; row_start <= row_end && col_start <= col_end && i>=row_start; i--)
            {
                res.push_back(matrix[i][col_start]);
            }
             col_start++;
             
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends