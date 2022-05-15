// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        vector<int> res;
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                res.push_back(matrix[i][j]);
            }
        }
        
        sort(res.begin(), res.end());
        int size = res.size();
        if(size % 2 != 0)
        {
            int mid = (size+1)/2;
            int ans = res[mid-1];
            return ans;
        }
        else{
            int mid1 = (size/2);
            int mid2 = ((size/2) + 1);
            int ans = ((int)res[mid1-1] + (int)res[mid2-1])/2;
            return ans;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends